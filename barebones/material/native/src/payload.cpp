// Barebones Material - native lane, UNMANAGED. A real lit material with a rim term, per sample.
//
// WHAT THIS SHOWS. A material that lights ITSELF, the way Mtl::Shade does, without a single 3ds Max
// header: each sample arrives as an opaque handle; ShadeSampleRead gives the normal and the view
// vector, ShadeSampleAmbient the ambient light, and ShadeSampleLight walks the scene's lights. The
// colour goes back as floats and the slot writes it into the sample's shade output.
//
//   colour = hue colour at brightness base * (ambient + sum of lights)   (or unlit, when "lit" is off)
//          + rim * (1 - facing)^2               (facing = how squarely the surface faces the camera)
//
// Exporting MaxMcpGetUnmanaged is the declaration of unmanaged mode: the slot pins this DLL, refuses
// the Python lane, and calls MtlShade from the render threads. See CartridgePayloadApi.h.
//
// DEPLOY. Build, then put slot_material_native.dll beside MaterialSlot.dlt and restart 3ds Max.
#include "CartridgePayloadApi.h"
#include "MaxFacadeApi.h"
#include "Json.h"
#include "PayloadUi.h"

#include "VersionGenerated.h"

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

// Written by Prepare on the main thread, read by the render threads.
struct Look
{
    float Hue = 0.58f;
    float Base = 0.8f;
    float Rim = 0.3f;
    bool bLit = true;
};

// A colour from hue (0..1, wraps), saturation and value.
void Hsv(float H, float S, float V, float* Out)
{
    H = (H - static_cast<float>(static_cast<int>(H))) * 6.0f;
    if (H < 0.0f) { H += 6.0f; }
    const int I = static_cast<int>(H) % 6;
    const float F = H - static_cast<float>(static_cast<int>(H));
    const float P = V * (1.0f - S);
    const float Q = V * (1.0f - S * F);
    const float T = V * (1.0f - S * (1.0f - F));
    const float Table[6][3] = { { V, T, P }, { Q, V, P }, { P, V, T }, { P, Q, V }, { T, P, V }, { V, P, Q } };
    Out[0] = Table[I][0];
    Out[1] = Table[I][1];
    Out[2] = Table[I][2];
}

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
    std::strncpy(OutInfo->Name, "slot_material", sizeof(OutInfo->Name) - 1);
    std::strncpy(OutInfo->Version, CARTRIDGE_VERSION_STRING, sizeof(OutInfo->Version) - 1);
    std::strncpy(OutInfo->Variant, "unmanaged", sizeof(OutInfo->Variant) - 1);
}

void* PayloadCreateInstance(void) { return new Look(); }
void PayloadDestroyInstance(void* Instance) { delete static_cast<Look*>(Instance); }

// -- the parameters and the panel ---------------------------------------------------------------
// An UNMANAGED slot refuses the Python lane, so everything it asks on the main thread - the
// parameter declaration, the panel, a control's event - is answered here. The table is the same
// declaration python/slot_material.py makes; the panel is composed with PayloadUi.h, the same layout
// engine mcp_ui is.
struct ParamSpec
{
    const char* Name;
    const char* Type;      // "float" | "int" | "bool"
    double Default;
    double Minimum;
    double Maximum;
    double Step;
    const char* Label;
};

const ParamSpec kParams[] = {
    { "hue", "float", 0.58, 0.0, 1.0, 0.01, "Hue:" },
    { "base", "float", 0.8, 0.0, 1.0, 0.01, "Base:" },
    { "rim", "float", 0.3, 0.0, 1.0, 0.01, "Rim:" },
    { "lit", "bool", 1.0, 0.0, 1.0, 1.0, "Lit by scene lights" },
};

const char* const kPanelTitle = "Colour, rim and lighting";

JsonValue DescribeParams()
{
    JsonValue List = JsonValue::Array();
    for (const ParamSpec& P : kParams)
    {
        JsonValue Entry = JsonValue::Object();
        Entry.Set("name", JsonValue::String(P.Name));
        Entry.Set("type", JsonValue::String(P.Type));
        Entry.Set("default", std::strcmp(P.Type, "bool") == 0 ? JsonValue::Bool(P.Default != 0.0)
                                                              : JsonValue::Number(P.Default));
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
        if (std::strcmp(P.Type, "bool") == 0)
        {
            auto Box = std::make_shared<ui::CheckBoxWidget>();
            Box->Text = P.Label;
            Box->bChecked = Current.At(P.Name).AsBool(P.Default != 0.0);
            Box->Param = P.Name;
            Root.Children.push_back(Box);
            continue;
        }
        auto Spinner = std::make_shared<ui::SpinnerWidget>();
        Spinner->Value = Current.At(P.Name).AsNumber(P.Default);
        Spinner->Minimum = P.Minimum;
        Spinner->Maximum = P.Maximum;
        Spinner->Step = P.Step;
        Spinner->Numeric = P.Type;
        Spinner->Param = P.Name;
        auto Field = std::make_shared<ui::FieldWidget>();
        Field->Text = P.Label;
        Field->Control = Spinner;
        Field->Gutter = ui::FieldGutter;
        Field->ControlWidth = ui::FieldWidth;
        Root.Children.push_back(Field);
    }
    return ui::Build(Root);
}

// A control moved. The slot has already saved the bound value; the map/material is stale, and the
// panel keeps its shape.
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
    if (std::strcmp(Function, "MtlUpdate") != 0)
    {
        JsonValue Result;
        if (std::strcmp(Function, "describe_params") == 0) { Result = DescribeParams(); }
        else if (std::strcmp(Function, "describe_ui") == 0) { Result = DescribeUi(Args); }
        else if (std::strcmp(Function, "on_ui_event") == 0) { Result = OnUiEvent(); }
        else { return MAXMCP_PAYLOAD_NO_FUNCTION; }
        JsonValue Reply = JsonValue::Object();
        Reply.Set("ok", JsonValue::Bool(true));
        Reply.Set("result", Result);
        return WriteReply(Reply, ReplyJson, ReplyCapacity) ? MAXMCP_PAYLOAD_OK
                                                           : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
    }
    JsonValue Reply = JsonValue::Object();
    Reply.Set("ok", JsonValue::Bool(true));
    if (Args.At("event").At("probe").AsNumber(0.0) == 0.0)
    {
        static bool bSaid = false;
        if (!bSaid)
        {
            bSaid = true;
            Say("Hello World - Barebones Material (C++, unmanaged) is live; this line came from its "
                "payload on the first update (MtlUpdate), and every sample is now shaded here.");
        }
    }
    return WriteReply(Reply, ReplyJson, ReplyCapacity) ? MAXMCP_PAYLOAD_OK
                                                       : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
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
        const std::string Line = std::string("Barebones Material (C++) native payload loaded: v")
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
    Look* const Self = static_cast<Look*>(Instance);
    if (Self == nullptr) { return; }
    JsonValue Params;
    if (!ParseJson(ParamsJson != nullptr ? ParamsJson : "{}", Params)) { return; }
    Self->Hue = static_cast<float>(Params.At("hue").AsNumber(0.58));
    Self->Base = static_cast<float>(Params.At("base").AsNumber(0.8));
    Self->Rim = static_cast<float>(Params.At("rim").AsNumber(0.3));
    Self->bLit = Params.At("lit").AsBool(true);
}

int32_t MtlShade(void* Instance, MaxMcpShadeSampleHandle Handle, float* OutRGB,
                 float* OutTransparencyRGB)
{
    const Look* const Self = static_cast<const Look*>(Instance);
    if (Self == nullptr || GFacade == nullptr || GFacade->ShadeSampleRead == nullptr) { return 1; }
    MaxMcpShadeSample S{};
    if (GFacade->ShadeSampleRead(GFacade->Context, Handle, &S) != MAXMCP_FACADE_OK) { return 1; }

    // V points from the camera towards the surface, so a surface facing the camera has N.V = -1.
    float Facing = -(S.N[0] * S.V[0] + S.N[1] * S.V[1] + S.N[2] * S.V[2]);
    Facing = Facing < 0.0f ? 0.0f : (Facing > 1.0f ? 1.0f : Facing);

    float Light[3] = { 1.0f, 1.0f, 1.0f };
    if (Self->bLit && GFacade->ShadeSampleAmbient != nullptr && GFacade->ShadeSampleLight != nullptr)
    {
        MaxMcpColor Ambient{};
        GFacade->ShadeSampleAmbient(GFacade->Context, Handle, &Ambient);
        Light[0] = Ambient.r;
        Light[1] = Ambient.g;
        Light[2] = Ambient.b;
        for (int32_t i = 0; i < S.NumLights; ++i)
        {
            MaxMcpColor C{};
            MaxMcpPoint3 Dir{};
            float DotNL = 0.0f;
            float Diffuse = 0.0f;
            int32_t Lit = 0;
            if (GFacade->ShadeSampleLight(GFacade->Context, Handle, i, &C, &Dir, &DotNL, &Diffuse,
                                          &Lit) == MAXMCP_FACADE_OK && Lit != 0)
            {
                Light[0] += Diffuse * C.r;
                Light[1] += Diffuse * C.g;
                Light[2] += Diffuse * C.b;
            }
        }
    }

    const float Edge = (1.0f - Facing) * (1.0f - Facing) * Self->Rim;
    float Colour[3];
    Hsv(Self->Hue, 0.75f, Self->Base, Colour);
    for (int c = 0; c < 3; ++c)
    {
        OutRGB[c] = Colour[c] * Light[c] + Edge;
        OutTransparencyRGB[c] = 0.0f;
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
