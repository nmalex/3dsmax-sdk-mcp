// Soap Bubble - native lane, UNMANAGED. A physically based thin-film material, per sample.
//
// WHAT THIS SHOWS. A material with real optics and no 3ds Max header. For every shading sample the
// Cartridge Material slot hands over an opaque handle; this code reads the sample through the facade
// (ShadeSampleRead, ShadeSampleUVW, ShadeSampleLight) and returns a colour and a transparency.
//
// THE PHYSICS, the same model Blender's Principled thin film and the physically based Shadertoy
// bubbles use:
//
//   * A soap film of index n = 1.33 between air and air, thickness d (nanometres).
//   * Light hitting it at angle theta refracts to theta_t (Snell), and the two reflections - off the
//     front and the back of the film - interfere with a phase difference
//         delta = 4 pi n d cos(theta_t) / lambda
//   * For a film between two identical media the reflectance is the Airy sum
//         R(lambda) = 2F (1 - cos delta) / (1 + F^2 - 2F cos delta)
//     with F the single-interface Fresnel reflectance. At d -> 0 it goes to zero: the "black film"
//     a bubble shows just before it bursts.
//   * R is evaluated at 16 wavelengths from 400 to 700 nm and integrated to RGB with the CIE colour
//     matching functions (Wyman, Sloan & Shirley 2013 analytic fit), then XYZ -> linear sRGB,
//     normalised so a film that reflects every wavelength equally is white.
//
// THE FILM. Thickness drains under gravity: thin at the top of the bubble (UV v = 1) and thick at the
// bottom, 150 -> 600 nm by default, as measured bubbles are. On top of that a domain-warped noise
// swirls the film; it flows with the scene time (`flow`) and with the keyable `phase`, so the bands
// move frame to frame. The Python lane moves only with `phase`: its update carries no time.
//
// WHAT IT REFLECTS. A soap film is almost all reflection and transmission. The reflected light is
// a procedural photo studio - a soft window up and to the left, a dim room around it - plus the
// scene's lights as sharp glints, each multiplied by the film's spectral reflectance. Where the
// reflection is brighter than white it rolls off towards white, so a window reads as a hot core with
// an iridescent fringe, as it does in photographs. The transparency is 1 - reflectance, so the
// background shows through the middle of the bubble and the colour concentrates towards the rim.
//
// Exporting MaxMcpGetUnmanaged is the declaration of unmanaged mode. See CartridgePayloadApi.h.
//
// DEPLOY. Build, then put slot_material_native.dll beside MaterialSlot.dlt and restart 3ds Max.
#include "CartridgePayloadApi.h"
#include "MaxFacadeApi.h"
#include "Json.h"
#include "PayloadUi.h"

#include "VersionGenerated.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <memory>
#include <string>

namespace
{

using maxmcp::JsonValue;
using maxmcp::ParseJson;

MaxMcpPayloadLogSink GSink = nullptr;
void* GSinkContext = nullptr;
const MaxMcpFacadeApi* GFacade = nullptr;

void Say(const char* Line)
{
    if (GSink != nullptr) { GSink(GSinkContext, 2 /* Display */, Line); }
}

constexpr float kPi = 3.14159265358979f;
constexpr float kFilmIor = 1.33f;
constexpr int kLambdas = 16;
constexpr float kTicksPerSecond = 4800.0f;

// Written by Prepare on the main thread, read by the render threads.
struct Film
{
    float ThicknessTop = 150.0f;      // nm, at the top of the bubble
    float ThicknessBottom = 600.0f;   // nm, at the bottom
    float Swirl = 320.0f;             // nm of thickness the noise adds or removes
    float SwirlScale = 3.0f;          // how many swirls around the bubble
    float Flow = 0.25f;               // how fast the film flows, per second
    float Phase = 0.0f;               // where the film is along its flow; key it to animate
    float Reflection = 1.0f;          // strength of the reflected studio
    float Glints = 1.0f;              // strength of the lights' highlights
};

// -- colour science ---------------------------------------------------------------------------------

float Lobe(float X, float Mu, float SigmaLeft, float SigmaRight)
{
    const float T = (X - Mu) / (X < Mu ? SigmaLeft : SigmaRight);
    return std::exp(-0.5f * T * T);
}

// The linear-sRGB weight of each wavelength, normalised so the sum over all of them is (1, 1, 1).
struct SpectrumTable
{
    float Lambda[kLambdas];
    float Weight[kLambdas][3];

    SpectrumTable()
    {
        float Sum[3] = { 0.0f, 0.0f, 0.0f };
        for (int i = 0; i < kLambdas; ++i)
        {
            const float L = 400.0f + 300.0f * static_cast<float>(i) / static_cast<float>(kLambdas - 1);
            Lambda[i] = L;
            // CIE 1931 colour matching functions, Wyman et al. 2013 multi-lobe fit.
            const float X = 1.056f * Lobe(L, 599.8f, 37.9f, 31.0f) + 0.362f * Lobe(L, 442.0f, 16.0f, 26.7f)
                          - 0.065f * Lobe(L, 501.1f, 20.4f, 26.2f);
            const float Y = 0.821f * Lobe(L, 568.8f, 46.9f, 40.5f) + 0.286f * Lobe(L, 530.9f, 16.3f, 31.1f);
            const float Z = 1.217f * Lobe(L, 437.0f, 11.8f, 36.0f) + 0.681f * Lobe(L, 459.0f, 26.0f, 13.8f);
            // XYZ -> linear sRGB (D65).
            Weight[i][0] = 3.2406f * X - 1.5372f * Y - 0.4986f * Z;
            Weight[i][1] = -0.9689f * X + 1.8758f * Y + 0.0415f * Z;
            Weight[i][2] = 0.0557f * X - 0.2040f * Y + 1.0570f * Z;
            for (int c = 0; c < 3; ++c) { Sum[c] += Weight[i][c]; }
        }
        for (int i = 0; i < kLambdas; ++i)
        {
            for (int c = 0; c < 3; ++c) { Weight[i][c] /= Sum[c]; }
        }
    }
};

const SpectrumTable& Spectrum()
{
    static const SpectrumTable Table;
    return Table;
}

// Reflectance of the film, as linear RGB, for a film of thickness D (nm) seen at cos(theta) = CosI.
void FilmReflectance(float D, float CosI, float* OutRgb)
{
    CosI = std::clamp(CosI, 0.0f, 1.0f);
    const float SinI2 = 1.0f - CosI * CosI;
    const float CosT = std::sqrt(std::max(0.0f, 1.0f - SinI2 / (kFilmIor * kFilmIor)));

    // Single-interface Fresnel reflectance, unpolarised (average of s and p).
    const float N = kFilmIor;
    const float Rs = (CosI - N * CosT) / (CosI + N * CosT);
    const float Rp = (N * CosI - CosT) / (N * CosI + CosT);
    const float F = std::clamp(0.5f * (Rs * Rs + Rp * Rp), 0.0f, 0.999f);

    const SpectrumTable& S = Spectrum();
    float Rgb[3] = { 0.0f, 0.0f, 0.0f };
    const float PathPhase = 4.0f * kPi * kFilmIor * std::max(0.0f, D) * CosT;
    for (int i = 0; i < kLambdas; ++i)
    {
        const float CosDelta = std::cos(PathPhase / S.Lambda[i]);
        const float R = 2.0f * F * (1.0f - CosDelta) / (1.0f + F * F - 2.0f * F * CosDelta);
        for (int c = 0; c < 3; ++c) { Rgb[c] += R * S.Weight[i][c]; }
    }
    for (int c = 0; c < 3; ++c) { OutRgb[c] = std::max(0.0f, Rgb[c]); }
}

// -- the film's thickness ------------------------------------------------------------------------------

float Hash(int X, int Y, int Z)
{
    unsigned H = static_cast<unsigned>(X) * 374761393u + static_cast<unsigned>(Y) * 668265263u
               + static_cast<unsigned>(Z) * 2147483647u;
    H = (H ^ (H >> 13)) * 1274126177u;
    H ^= H >> 16;
    return static_cast<float>(H & 0xFFFFFF) / static_cast<float>(0xFFFFFF);
}

float Smooth(float T) { return T * T * (3.0f - 2.0f * T); }

// Value noise, 0..1.
float Noise(float X, float Y, float Z)
{
    const int Xi = static_cast<int>(std::floor(X));
    const int Yi = static_cast<int>(std::floor(Y));
    const int Zi = static_cast<int>(std::floor(Z));
    const float Xf = Smooth(X - static_cast<float>(Xi));
    const float Yf = Smooth(Y - static_cast<float>(Yi));
    const float Zf = Smooth(Z - static_cast<float>(Zi));
    const auto Lerp = [](float A, float B, float T) { return A + (B - A) * T; };
    const float X00 = Lerp(Hash(Xi, Yi, Zi), Hash(Xi + 1, Yi, Zi), Xf);
    const float X10 = Lerp(Hash(Xi, Yi + 1, Zi), Hash(Xi + 1, Yi + 1, Zi), Xf);
    const float X01 = Lerp(Hash(Xi, Yi, Zi + 1), Hash(Xi + 1, Yi, Zi + 1), Xf);
    const float X11 = Lerp(Hash(Xi, Yi + 1, Zi + 1), Hash(Xi + 1, Yi + 1, Zi + 1), Xf);
    return Lerp(Lerp(X00, X10, Yf), Lerp(X01, X11, Yf), Zf);
}

float Fbm(float X, float Y, float Z)
{
    float Sum = 0.0f;
    float Amp = 0.5f;
    for (int o = 0; o < 4; ++o)
    {
        Sum += Amp * Noise(X, Y, Z);
        X = X * 2.03f + 11.7f;
        Y = Y * 2.03f + 3.1f;
        Z = Z * 2.03f + 7.3f;
        Amp *= 0.5f;
    }
    return Sum;   // about 0..0.94
}

// The film thickness at (u, v) at time Seconds. u is wrapped onto a circle so the seam does not show.
float Thickness(const Film& F, float U, float V, float Seconds)
{
    const float Height = std::clamp(V, 0.0f, 1.0f);
    // Drainage: thin on top, thick at the bottom, with most of the change high up.
    float D = F.ThicknessBottom + (F.ThicknessTop - F.ThicknessBottom) * std::pow(Height, 1.6f);

    const float Angle = 2.0f * kPi * U;
    const float R = F.SwirlScale / (2.0f * kPi);
    float X = std::cos(Angle) * R * 2.0f;
    float Y = std::sin(Angle) * R * 2.0f;
    // The film flows down over time, and along its keyable phase.
    const float Along = Seconds * F.Flow + F.Phase;
    float Z = Height * F.SwirlScale - Along;
    // Domain warp: the swirls of a real film are eddies, not blobs.
    const float Wx = Fbm(X + 5.2f, Y + 1.3f, Z + Along * 0.5f);
    const float Wy = Fbm(X + 1.7f, Y + 9.2f, Z - Along * 0.3f);
    X += 2.5f * (Wx - 0.47f);
    Y += 2.5f * (Wy - 0.47f);
    D += F.Swirl * 2.0f * (Fbm(X, Y, Z) - 0.47f);

    // The black film: the very top thins out below visible interference just before bursting.
    if (Height > 0.97f) { D *= std::max(0.0f, (1.0f - Height) / 0.03f); }
    return std::max(0.0f, D);
}

// -- the payload ABI ------------------------------------------------------------------------------------

bool WriteReply(const JsonValue& Reply, char* Out, size_t Capacity)
{
    const std::string Text = Reply.Serialize();
    if (Out == nullptr || Text.size() + 1 > Capacity) { return false; }
    std::memcpy(Out, Text.c_str(), Text.size() + 1);
    return true;
}

void PayloadDescribe(MaxMcpPayloadInfo* OutInfo)
{
    if (OutInfo == nullptr) { return; }
    OutInfo->AbiVersion = MAXMCP_PAYLOAD_ABI;
    std::strncpy(OutInfo->Name, "soap_bubble", sizeof(OutInfo->Name) - 1);
    std::strncpy(OutInfo->Version, CARTRIDGE_VERSION_STRING, sizeof(OutInfo->Version) - 1);
    std::strncpy(OutInfo->Variant, "unmanaged", sizeof(OutInfo->Variant) - 1);
}

void* PayloadCreateInstance(void) { return new Film(); }
void PayloadDestroyInstance(void* Instance) { delete static_cast<Film*>(Instance); }

// -- the parameters and the panel -------------------------------------------------------------------
// An UNMANAGED slot refuses the Python lane, so the declaration, the panel and a control's event are
// all answered here. The same table as python/soap_bubble.py.
struct ParamSpec
{
    const char* Name;
    double Default;
    double Minimum;
    double Maximum;
    double Step;
    const char* Label;
};

const ParamSpec kParams[] = {
    { "thickness_top", 150.0, 0.0, 2000.0, 5.0, "Top (nm):" },
    { "thickness_bottom", 600.0, 0.0, 2000.0, 5.0, "Bottom (nm):" },
    { "swirl", 320.0, 0.0, 1000.0, 5.0, "Swirl (nm):" },
    { "swirl_scale", 3.0, 0.1, 20.0, 0.1, "Swirl size:" },
    { "flow", 0.25, 0.0, 5.0, 0.01, "Flow speed:" },
    { "phase", 0.0, -1000.0, 1000.0, 0.01, "Phase:" },
    { "reflection", 1.0, 0.0, 5.0, 0.05, "Reflection:" },
    { "glints", 1.0, 0.0, 5.0, 0.05, "Glints:" },
};

const char* const kPanelTitle = "Soap film";

JsonValue DescribeParams()
{
    JsonValue List = JsonValue::Array();
    for (const ParamSpec& P : kParams)
    {
        JsonValue Entry = JsonValue::Object();
        Entry.Set("name", JsonValue::String(P.Name));
        Entry.Set("type", JsonValue::String("float"));
        Entry.Set("default", JsonValue::Number(P.Default));
        List.Push(Entry);
    }
    JsonValue Out = JsonValue::Object();
    Out.Set("parameters", List);
    return Out;
}

JsonValue DescribeUi(const JsonValue& Args)
{
    namespace ui = maxmcp::payloadui;
    const JsonValue& Current = Args.At("params");
    ui::VBoxWidget Root;
    auto Title = std::make_shared<ui::LabelWidget>();
    Title->Text = kPanelTitle;
    Root.Children.push_back(Title);
    Root.Children.push_back(std::make_shared<ui::SpacerWidget>());
    for (const ParamSpec& P : kParams)
    {
        auto Spinner = std::make_shared<ui::SpinnerWidget>();
        Spinner->Value = Current.At(P.Name).AsNumber(P.Default);
        Spinner->Minimum = P.Minimum;
        Spinner->Maximum = P.Maximum;
        Spinner->Step = P.Step;
        Spinner->Numeric = "float";
        Spinner->Param = P.Name;
        auto Field = std::make_shared<ui::FieldWidget>();
        Field->Text = P.Label;
        Field->Control = Spinner;
        Field->Gutter = ui::FieldGutter + 12;
        Field->ControlWidth = ui::FieldWidth;
        Root.Children.push_back(Field);
    }
    return ui::Build(Root);
}

JsonValue OnUiEvent()
{
    JsonValue Out = JsonValue::Object();
    Out.Set("invalidate", JsonValue::Bool(true));
    Out.Set("rebuild", JsonValue::Bool(false));
    Out.Set("updates", JsonValue::Array());
    return Out;
}

MaxMcpPayloadResult PayloadCall(void*, const char* Function, const char* ArgumentsJson,
                                char* ReplyJson, size_t ReplyCapacity)
{
    if (Function == nullptr) { return MAXMCP_PAYLOAD_NO_FUNCTION; }
    JsonValue Args;
    ParseJson(ArgumentsJson != nullptr ? ArgumentsJson : "{}", Args);
    JsonValue Result = JsonValue::Object();
    if (std::strcmp(Function, "describe_params") == 0) { Result = DescribeParams(); }
    else if (std::strcmp(Function, "describe_ui") == 0) { Result = DescribeUi(Args); }
    else if (std::strcmp(Function, "on_ui_event") == 0) { Result = OnUiEvent(); }
    else if (std::strcmp(Function, "MtlUpdate") == 0)
    {
        // The viewport's colour (no per-sample call is made there): a pale film tint.
        JsonValue Colour = JsonValue::Array();
        Colour.Push(JsonValue::Number(0.78));
        Colour.Push(JsonValue::Number(0.74));
        Colour.Push(JsonValue::Number(0.88));
        Result.Set("color", Colour);
        if (Args.At("event").At("probe").AsNumber(0.0) == 0.0)
        {
            static bool bSaid = false;
            if (!bSaid)
            {
                bSaid = true;
                Say("Hello World - Soap Bubble (C++, unmanaged) is live: every sample is a thin-film "
                    "interference calculation over 16 wavelengths.");
            }
        }
    }
    else
    {
        return MAXMCP_PAYLOAD_NO_FUNCTION;
    }
    JsonValue Reply = JsonValue::Object();
    Reply.Set("ok", JsonValue::Bool(true));
    Reply.Set("result", Result);
    return WriteReply(Reply, ReplyJson, ReplyCapacity) ? MAXMCP_PAYLOAD_OK : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
}

MaxMcpPayloadResult PayloadCallBuffers(void*, const char*, const MaxMcpBuffer*, size_t, const char*,
                                       char*, size_t)
{
    return MAXMCP_PAYLOAD_NO_FUNCTION;
}

void PayloadSetLogSink(MaxMcpPayloadLogSink Sink, void* Context)
{
    GSink = Sink;
    GSinkContext = Context;
    if (Sink != nullptr)
    {
        const std::string Line = std::string("Soap Bubble (C++) native payload loaded: v")
            + CARTRIDGE_VERSION_STRING + " built " + CARTRIDGE_BUILD_STAMP
            + ". It exports MaxMcpGetUnmanaged, so the slot runs it UNMANAGED. This is the load "
              "report, not the greeting.";
        Sink(Context, 2, Line.c_str());
    }
}

void PayloadSetFacade(const MaxMcpFacadeApi* Slot) { GFacade = Slot; }

const MaxMcpPayloadApi GPayloadApi =
{
    &PayloadDescribe, &PayloadCreateInstance, &PayloadDestroyInstance, &PayloadCall,
    &PayloadCallBuffers, &PayloadSetLogSink, &PayloadSetFacade, nullptr,
};

void Prepare(void* Instance, int32_t /*Time*/, const char* ParamsJson)
{
    Film* const Self = static_cast<Film*>(Instance);
    if (Self == nullptr) { return; }
    JsonValue Params;
    if (!ParseJson(ParamsJson != nullptr ? ParamsJson : "{}", Params)) { return; }
    const auto Read = [&Params](const char* Name, double Fallback)
    {
        return static_cast<float>(Params.At(Name).AsNumber(Fallback));
    };
    Self->ThicknessTop = Read("thickness_top", 150.0);
    Self->ThicknessBottom = Read("thickness_bottom", 600.0);
    Self->Swirl = Read("swirl", 320.0);
    Self->SwirlScale = std::max(0.1f, Read("swirl_scale", 3.0));
    Self->Flow = Read("flow", 0.25);
    Self->Phase = Read("phase", 0.0);
    Self->Reflection = Read("reflection", 1.0);
    Self->Glints = Read("glints", 1.0);
    Spectrum();   // build the table here, on the main thread, not on the first render thread
}

float SmoothStep(float A, float B, float X)
{
    const float T = std::clamp((X - A) / (B - A), 0.0f, 1.0f);
    return T * T * (3.0f - 2.0f * T);
}

// The photo studio a bubble reflects, by the reflected direction in camera space (x right, y up,
// +z back towards the camera): a dim room brightening upwards, and a soft rectangular window up and
// to the left, behind the camera - the highlight every bubble photograph has.
float Studio(float Rx, float Ry, float Rz)
{
    const float Room = 0.06f + 0.30f * SmoothStep(-0.6f, 0.8f, Ry);
    const float Window = SmoothStep(-0.95f, -0.80f, Rx) * (1.0f - SmoothStep(-0.35f, -0.20f, Rx))
                       * SmoothStep(0.15f, 0.30f, Ry) * (1.0f - SmoothStep(0.70f, 0.85f, Ry))
                       * SmoothStep(0.0f, 0.15f, Rz);
    return Room + 6.0f * Window;
}

// Brighter than white rolls off towards white, keeping the hue at the fringe.
void RollOff(float* Rgb)
{
    const float Peak = std::max(Rgb[0], std::max(Rgb[1], Rgb[2]));
    if (Peak <= 1.0f) { return; }
    const float Over = std::min(1.0f, (Peak - 1.0f) / 2.0f);
    for (int c = 0; c < 3; ++c)
    {
        const float Clamped = Rgb[c] / Peak;
        Rgb[c] = Clamped + (1.0f - Clamped) * Over;
    }
}

int32_t MtlShade(void* Instance, MaxMcpShadeSampleHandle Handle, float* OutRGB,
                 float* OutTransparencyRGB)
{
    const Film* const Self = static_cast<const Film*>(Instance);
    if (Self == nullptr || GFacade == nullptr || GFacade->ShadeSampleRead == nullptr) { return 1; }
    MaxMcpShadeSample S{};
    if (GFacade->ShadeSampleRead(GFacade->Context, Handle, &S) != MAXMCP_FACADE_OK) { return 1; }

    // Both faces of the film are shaded (the scene renders two-sided), so use |N.V|.
    const float NdotV = S.N[0] * S.V[0] + S.N[1] * S.V[1] + S.N[2] * S.V[2];
    const float CosI = std::clamp(std::fabs(NdotV), 0.0f, 1.0f);
    const float Sign = NdotV < 0.0f ? 1.0f : -1.0f;   // the normal on the viewer's side

    const float Seconds = static_cast<float>(S.Time) / kTicksPerSecond;
    const float D = Thickness(*Self, S.UVW[0], S.UVW[1], Seconds);

    float Film[3];
    FilmReflectance(D, CosI, Film);

    // The reflected direction, R = V - 2 (N.V) N, with N on the viewer's side.
    const float Nx = S.N[0] * Sign;
    const float Ny = S.N[1] * Sign;
    const float Nz = S.N[2] * Sign;
    const float NdV = Nx * S.V[0] + Ny * S.V[1] + Nz * S.V[2];
    const float Rx = S.V[0] - 2.0f * NdV * Nx;
    const float Ry = S.V[1] - 2.0f * NdV * Ny;
    const float Rz = S.V[2] - 2.0f * NdV * Nz;
    float Incoming[3];
    const float Env = Studio(Rx, Ry, Rz) * Self->Reflection;
    for (int c = 0; c < 3; ++c) { Incoming[c] = Env; }

    // The lights, as sharp glints: a mirror-like lobe around the reflected direction.
    if (Self->Glints > 0.0f && GFacade->ShadeSampleLight != nullptr)
    {
        for (int32_t i = 0; i < S.NumLights; ++i)
        {
            MaxMcpColor C{};
            MaxMcpPoint3 Dir{};
            float DotNL = 0.0f;
            float Diffuse = 0.0f;
            int32_t Lit = 0;
            if (GFacade->ShadeSampleLight(GFacade->Context, Handle, i, &C, &Dir, &DotNL, &Diffuse, &Lit)
                    != MAXMCP_FACADE_OK || Lit == 0)
            {
                continue;
            }
            const float Align = std::max(0.0f, Rx * Dir.x + Ry * Dir.y + Rz * Dir.z);
            const float Glint = Self->Glints * (std::pow(Align, 600.0f) * 40.0f + std::pow(Align, 60.0f) * 0.8f);
            Incoming[0] += Glint * C.r;
            Incoming[1] += Glint * C.g;
            Incoming[2] += Glint * C.b;
        }
    }

    float Reflected[3];
    for (int c = 0; c < 3; ++c) { Reflected[c] = Film[c] * Incoming[c]; }
    RollOff(Reflected);
    for (int c = 0; c < 3; ++c)
    {
        OutRGB[c] = Reflected[c];
        // What the film does not reflect, it lets through; a blown-out window hides what is behind it.
        OutTransparencyRGB[c] = std::clamp(1.0f - std::max(Film[c], Reflected[c]), 0.0f, 1.0f);
    }
    return 0;
}

const MaxMcpUnmanagedApi GUnmanagedApi =
{
    &Prepare,
    nullptr,    // TexmapColor
    nullptr,    // TexmapMono
    nullptr,    // TexmapBump
    &MtlShade,
    nullptr,    // ShaderIllum
    nullptr,    // SamplerSample
};

}   // namespace

extern "C" __declspec(dllexport) const MaxMcpPayloadApi* MaxMcpGetPayload(uint32_t AbiVersion)
{
    return AbiVersion == MAXMCP_PAYLOAD_ABI ? &GPayloadApi : nullptr;
}

// THE DECLARATION OF UNMANAGED MODE.
extern "C" __declspec(dllexport) const MaxMcpUnmanagedApi* MaxMcpGetUnmanaged(uint32_t UnmanagedAbi)
{
    return UnmanagedAbi == MAXMCP_UNMANAGED_ABI ? &GUnmanagedApi : nullptr;
}
