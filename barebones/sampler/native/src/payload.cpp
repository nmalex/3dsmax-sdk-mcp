// Barebones Sampler - native lane, UNMANAGED. A stratified, optionally jittered grid, per pixel.
//
// WHAT THIS SHOWS. A supersampler with no 3ds Max header. For each pixel the slot hands over an opaque
// handle; this lays out an N x N grid of positions inside the pixel and calls ShadeSampleTakeSample for
// each. The SLOT sums every hit sample's whole shade output (render elements included) and divides by
// the count - this code never averages anything, so it cannot get that wrong.
//
//   N = the "grid" parameter, or, when that is 0, 1 + 3 * quality (the SuperSampling rollout's spinner)
//   jitter shifts each position inside its cell by a hash of the pixel, so neighbouring pixels differ
//
// Exporting MaxMcpGetUnmanaged is the declaration of unmanaged mode. See CartridgePayloadApi.h.
//
// DEPLOY. Build, then put slot_sampler_native.dll beside SamplerSlot.dlh and restart 3ds Max.
#include "CartridgePayloadApi.h"
#include "MaxFacadeApi.h"
#include "Json.h"
#include "PayloadUi.h"

#include "VersionGenerated.h"

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

struct Pattern
{
    int Side = 2;
    bool bJitter = true;
};

bool WriteReply(const JsonValue& Reply, char* Out, size_t Capacity)
{
    const std::string Text = Reply.Serialize();
    if (Out == nullptr || Text.size() + 1 > Capacity) { return false; }
    std::memcpy(Out, Text.c_str(), Text.size() + 1);
    return true;
}

// A small, stateless hash - the render threads share nothing, so no random-number generator.
float Hash01(uint32_t X)
{
    X ^= X >> 16;
    X *= 0x7feb352dU;
    X ^= X >> 15;
    X *= 0x846ca68bU;
    X ^= X >> 16;
    return static_cast<float>(X & 0xFFFFFF) / static_cast<float>(0x1000000);
}

void PayloadDescribe(MaxMcpPayloadInfo* OutInfo)
{
    if (OutInfo == nullptr) { return; }
    OutInfo->AbiVersion = MAXMCP_PAYLOAD_ABI;
    std::strncpy(OutInfo->Name, "slot_sampler", sizeof(OutInfo->Name) - 1);
    std::strncpy(OutInfo->Version, CARTRIDGE_VERSION_STRING, sizeof(OutInfo->Version) - 1);
    std::strncpy(OutInfo->Variant, "unmanaged", sizeof(OutInfo->Variant) - 1);
}

void* PayloadCreateInstance(void) { return new Pattern(); }
void PayloadDestroyInstance(void* Instance) { delete static_cast<Pattern*>(Instance); }

// -- the parameters and the panel ---------------------------------------------------------------
// An UNMANAGED slot refuses the Python lane, so everything it asks on the main thread - the
// parameter declaration, the panel, a control's event - is answered here. The table is the same
// declaration python/slot_sampler.py makes; the panel is composed with PayloadUi.h, the same layout
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
    { "grid", "int", 0.0, 0.0, 8.0, 1.0, "Grid:" },
    { "jitter", "bool", 1.0, 0.0, 1.0, 1.0, "Jitter within each cell" },
};

const char* const kPanelTitle = "Stratified grid";

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
    if (std::strcmp(Function, "SamplerRenderBegin") != 0)
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
            Say("Hello World - Barebones Sampler (C++, unmanaged) is live; this line came from its "
                "payload on the first render (SamplerRenderBegin), and every pixel is now sampled here.");
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
        const std::string Line = std::string("Barebones Sampler (C++) native payload loaded: v")
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
    Pattern* const Self = static_cast<Pattern*>(Instance);
    if (Self == nullptr) { return; }
    JsonValue Params;
    if (!ParseJson(ParamsJson != nullptr ? ParamsJson : "{}", Params)) { return; }
    int Side = static_cast<int>(Params.At("grid").AsNumber(0.0));
    if (Side <= 0)
    {
        const double Quality = Params.At("quality").AsNumber(0.5);
        Side = 1 + static_cast<int>(3.0 * (Quality < 0.0 ? 0.0 : (Quality > 1.0 ? 1.0 : Quality)));
    }
    Self->Side = Side > 8 ? 8 : Side;
    Self->bJitter = Params.At("jitter").AsBool(true);
}

int32_t SamplerSample(void* Instance, MaxMcpShadeSampleHandle Handle, float* /*OutRGB*/,
                      float* /*OutTransparencyRGB*/)
{
    const Pattern* const Self = static_cast<const Pattern*>(Instance);
    if (Self == nullptr || GFacade == nullptr || GFacade->ShadeSampleRead == nullptr
        || GFacade->ShadeSampleTakeSample == nullptr)
    {
        return 1;
    }
    MaxMcpShadeSample S{};
    if (GFacade->ShadeSampleRead(GFacade->Context, Handle, &S) != MAXMCP_FACADE_OK) { return 1; }
    const uint32_t Seed = static_cast<uint32_t>(S.ScreenX) * 73856093U
                        ^ static_cast<uint32_t>(S.ScreenY) * 19349663U;

    const float Cell = 1.0f / static_cast<float>(Self->Side);
    for (int y = 0; y < Self->Side; ++y)
    {
        for (int x = 0; x < Self->Side; ++x)
        {
            float Ox = 0.5f;
            float Oy = 0.5f;
            if (Self->bJitter)
            {
                const uint32_t Index = static_cast<uint32_t>(y * Self->Side + x);
                Ox = Hash01(Seed ^ (Index * 2654435761U));
                Oy = Hash01(Seed ^ (Index * 2246822519U) ^ 0x9e3779b9U);
            }
            int32_t Hit = 0;
            GFacade->ShadeSampleTakeSample(GFacade->Context, Handle, (static_cast<float>(x) + Ox) * Cell,
                                           (static_cast<float>(y) + Oy) * Cell, 1.0f, nullptr, nullptr,
                                           &Hit);
        }
    }
    return 0;   // served; the slot averages what was taken, or samples the centre if nothing hit
}

const MaxMcpUnmanagedApi GUnmanagedApi =
{
    &Prepare,
    nullptr,    // TexmapColor
    nullptr,    // TexmapMono
    nullptr,    // TexmapBump
    nullptr,    // MtlShade
    nullptr,    // ShaderIllum
    &SamplerSample,
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
