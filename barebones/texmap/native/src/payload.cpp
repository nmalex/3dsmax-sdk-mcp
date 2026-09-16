// Barebones Texture Map - native lane, UNMANAGED. A real checker, computed per shading sample.
//
// WHAT THIS SHOWS. The whole unmanaged shape (CartridgePayloadApi.h, "UNMANAGED MODE"):
//   * the ordinary payload table (MaxMcpGetPayload) - Describe, the log sink, the facade, and the
//     `TexmapUpdate` greeting on the main thread;
//   * ONE MORE export, MaxMcpGetUnmanaged. Exporting it is the declaration: the slot pins this DLL,
//     opens the facade's per-sample entries, refuses the Python lane, and calls TexmapColor /
//     TexmapMono from the render threads for every sample.
//
// NO SDK, EVEN HERE. Unmanaged mode does not mean SDK-linked. This file includes the facade contract
// and nothing from 3ds Max: each sample arrives as an opaque handle, ShadeSampleRead turns it into
// plain numbers (UVW already through the map's Coordinates rollout), and the colour goes back as
// floats the slot writes. See LAW.md, LAW-1.
//
// THREADING. Prepare runs on the main thread and stores the parameters; the per-sample functions run
// on many render threads at once and only READ them.
//
// DEPLOY. Build, then put slot_texmap_native.dll beside TexmapSlot.dlt and restart 3ds Max - an
// unmanaged payload is loaded once per session.
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

// What Prepare stores and the render threads read. Plain floats: a torn read between two Prepares
// can only mix two valid parameter sets, never corrupt one.
struct Checker
{
    float Tiles = 4.0f;
    float Bright = 0.9f;
    float Dark = 0.1f;
};

bool WriteReply(const JsonValue& Reply, char* Out, size_t Capacity)
{
    const std::string Text = Reply.Serialize();
    if (Out == nullptr || Text.size() + 1 > Capacity) { return false; }
    std::memcpy(Out, Text.c_str(), Text.size() + 1);
    return true;
}

// -- the ordinary table ------------------------------------------------------------------------------

void PayloadDescribe(MaxMcpPayloadInfo* OutInfo)
{
    if (OutInfo == nullptr) { return; }
    OutInfo->AbiVersion = MAXMCP_PAYLOAD_ABI;
    std::strncpy(OutInfo->Name, "slot_texmap", sizeof(OutInfo->Name) - 1);
    std::strncpy(OutInfo->Version, CARTRIDGE_VERSION_STRING, sizeof(OutInfo->Version) - 1);
    std::strncpy(OutInfo->Variant, "unmanaged", sizeof(OutInfo->Variant) - 1);
}

void* PayloadCreateInstance(void) { return new Checker(); }
void PayloadDestroyInstance(void* Instance) { delete static_cast<Checker*>(Instance); }

// -- the parameters and the panel ---------------------------------------------------------------
// An UNMANAGED slot refuses the Python lane, so everything it asks on the main thread - the
// parameter declaration, the panel, a control's event - is answered here. The table is the same
// declaration python/slot_texmap.py makes; the panel is composed with PayloadUi.h, the same layout
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
    { "tiles", "float", 4.0, 0.01, 1000.0, 0.1, "Tiles:" },
    { "bright", "float", 0.9, 0.0, 1.0, 0.01, "Bright:" },
    { "dark", "float", 0.1, 0.0, 1.0, 0.01, "Dark:" },
};

const char* const kPanelTitle = "Checker";

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
    if (std::strcmp(Function, "TexmapUpdate") != 0)
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
            Say("Hello World - Barebones Texture Map (C++, unmanaged) is live; this line came from "
                "its payload on the first update (TexmapUpdate), and every sample is now drawn here.");
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
        const std::string Line = std::string("Barebones Texture Map (C++) native payload loaded: v")
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

// -- the unmanaged table -----------------------------------------------------------------------------

void Prepare(void* Instance, int32_t /*Time*/, const char* ParamsJson)
{
    Checker* const Self = static_cast<Checker*>(Instance);
    if (Self == nullptr) { return; }
    JsonValue Params;
    if (!ParseJson(ParamsJson != nullptr ? ParamsJson : "{}", Params)) { return; }
    Self->Tiles = static_cast<float>(Params.At("tiles").AsNumber(4.0));
    Self->Bright = static_cast<float>(Params.At("bright").AsNumber(0.9));
    Self->Dark = static_cast<float>(Params.At("dark").AsNumber(0.1));
}

// The checker's value at one sample, or a negative number when the sample could not be read.
float Sample(void* Instance, MaxMcpShadeSampleHandle Handle)
{
    const Checker* const Self = static_cast<const Checker*>(Instance);
    if (Self == nullptr || GFacade == nullptr || GFacade->ShadeSampleRead == nullptr) { return -1.0f; }
    MaxMcpShadeSample S{};
    if (GFacade->ShadeSampleRead(GFacade->Context, Handle, &S) != MAXMCP_FACADE_OK) { return -1.0f; }
    const long U = static_cast<long>(std::floor(S.UVW[0] * Self->Tiles));
    const long V = static_cast<long>(std::floor(S.UVW[1] * Self->Tiles));
    return ((U + V) & 1) != 0 ? Self->Bright : Self->Dark;
}

int32_t TexmapColor(void* Instance, MaxMcpShadeSampleHandle Handle, float* OutRGBA)
{
    const float Value = Sample(Instance, Handle);
    if (Value < 0.0f) { return 1; }   // not served: the slot answers its neutral grey
    OutRGBA[0] = OutRGBA[1] = OutRGBA[2] = Value;
    OutRGBA[3] = 1.0f;
    return 0;
}

int32_t TexmapMono(void* Instance, MaxMcpShadeSampleHandle Handle, float* OutMono)
{
    const float Value = Sample(Instance, Handle);
    if (Value < 0.0f) { return 1; }
    *OutMono = Value;
    return 0;
}

const MaxMcpUnmanagedApi GUnmanagedApi =
{
    &Prepare,
    &TexmapColor,
    &TexmapMono,
    nullptr,    // TexmapBump - no bump; the slot answers "no perturbation"
    nullptr,    // MtlShade
    nullptr,    // ShaderIllum
    nullptr,    // SamplerSample
};

}   // namespace

extern "C" __declspec(dllexport) const MaxMcpPayloadApi* MaxMcpGetPayload(uint32_t AbiVersion)
{
    return AbiVersion == MAXMCP_PAYLOAD_ABI ? &GPayloadApi : nullptr;
}

// THE DECLARATION OF UNMANAGED MODE. Remove this export and the slot runs this payload managed.
extern "C" __declspec(dllexport) const MaxMcpUnmanagedApi* MaxMcpGetUnmanaged(uint32_t UnmanagedAbi)
{
    return UnmanagedAbi == MAXMCP_UNMANAGED_ABI ? &GUnmanagedApi : nullptr;
}
