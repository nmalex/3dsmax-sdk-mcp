// Barebones System - native lane. Cartridge System: a plain helper that draws a wireframe tetrahedron.
// A plain DLL the slot loads; 3ds Max never sees it. No 3ds Max SDK.
//
// WHAT THIS SHOWS. The helper slot asks one question, `HelperLines`, and draws the answer:
//
//     {"lines": [[[x, y, z], ...], ...], "color": [r, g, b]}
//
// The points are in the helper's own space. The slot draws them, hit-tests them and boxes them; this
// payload returns numbers and touches neither the viewport nor the SDK. It also answers the panel -
// describe_params, describe_ui, on_ui_event - so the C++ lane stands alone without the Python one.
//
// ITS ONE PARAMETER, `size`, is the edge length. The slot keeps it and hands it back as `params` on
// every call; creating the helper by click-and-drag writes the drag distance into it.
//
// Not to be confused with Tetra Dummy (barebones/manipulator): the same shape, drawn as a manipulator
// gizmo. This one is a plain helper.
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

// The edge length, in system units - the declared default.
const double kDefaultSize = 30.0;

// Four alternate corners of a cube: a regular tetrahedron whose edge is 2 * sqrt(2).
const double kCorners[4][3] = { { 1, 1, 1 }, { 1, -1, -1 }, { -1, 1, -1 }, { -1, -1, 1 } };

void Say(const char* Line)
{
    if (GSink != nullptr) { GSink(GSinkContext, 2 /* Display */, Line); }
}

bool WriteReply(const JsonValue& Reply, char* ReplyJson, size_t ReplyCapacity)
{
    const std::string Text = Reply.Serialize();
    if (ReplyJson == nullptr || Text.size() + 1 > ReplyCapacity) { return false; }
    std::memcpy(ReplyJson, Text.c_str(), Text.size() + 1);
    return true;
}

double SizeOf(const JsonValue& Args)
{
    return Args.At("params").At("size").AsNumber(kDefaultSize);
}

JsonValue Point(const double Corner[3], double Scale)
{
    JsonValue P = JsonValue::Array();
    for (int i = 0; i < 3; ++i) { P.Push(JsonValue::Number(Corner[i] * Scale)); }
    return P;
}

// All six edges, as six two-point lines.
JsonValue HelperLines(const JsonValue& Args)
{
    const double Size = SizeOf(Args);
    static bool bSaidHello = false;
    if (!bSaidHello)
    {
        bSaidHello = true;
        Say(("Hello World - Barebones System (C++) is live; this line came from its payload on the "
             "first draw (HelperLines), a wireframe tetrahedron " + std::to_string(Size) + ".").c_str());
    }
    const double Scale = Size / (2.0 * std::sqrt(2.0));
    JsonValue Lines = JsonValue::Array();
    for (int a = 0; a < 4; ++a)
    {
        for (int b = a + 1; b < 4; ++b)
        {
            JsonValue Line = JsonValue::Array();
            Line.Push(Point(kCorners[a], Scale));
            Line.Push(Point(kCorners[b], Scale));
            Lines.Push(Line);
        }
    }
    JsonValue Out = JsonValue::Object();
    Out.Set("lines", Lines);
    return Out;
}

JsonValue DescribeParams()
{
    JsonValue Entry = JsonValue::Object();
    Entry.Set("name", JsonValue::String("size"));
    Entry.Set("type", JsonValue::String("float"));
    Entry.Set("default", JsonValue::Number(kDefaultSize));
    JsonValue List = JsonValue::Array();
    List.Push(Entry);
    JsonValue Out = JsonValue::Object();
    Out.Set("parameters", List);
    return Out;
}

JsonValue DescribeUi(const JsonValue& Args)
{
    namespace ui = maxmcp::payloadui;
    ui::VBoxWidget Root;
    auto Title = std::make_shared<ui::LabelWidget>();
    Title->Text = "Cartridge System";
    Root.Children.push_back(Title);
    Root.Children.push_back(std::make_shared<ui::SpacerWidget>());
    auto Spinner = std::make_shared<ui::SpinnerWidget>();
    Spinner->Value = SizeOf(Args);
    Spinner->Minimum = 0.01;
    Spinner->Maximum = 100000.0;
    Spinner->Step = 0.1;
    Spinner->Param = "size";
    Spinner->bUniverse = true;
    auto Field = std::make_shared<ui::FieldWidget>();
    Field->Text = "Size:";
    Field->Control = Spinner;
    Root.Children.push_back(Field);
    return ui::Build(Root);
}

JsonValue OnUiEvent()
{
    // The slot has already saved the spinner's value; `invalidate` asks it for new lines.
    JsonValue Out = JsonValue::Object();
    Out.Set("invalidate", JsonValue::Bool(true));
    Out.Set("rebuild", JsonValue::Bool(false));
    Out.Set("updates", JsonValue::Array());
    return Out;
}

void PayloadDescribe(MaxMcpPayloadInfo* OutInfo)
{
    if (OutInfo == nullptr) { return; }
    OutInfo->AbiVersion = MAXMCP_PAYLOAD_ABI;
    std::strncpy(OutInfo->Name, "slot_system", sizeof(OutInfo->Name) - 1);
    std::strncpy(OutInfo->Version, CARTRIDGE_VERSION_STRING, sizeof(OutInfo->Version) - 1);
    std::strncpy(OutInfo->Variant, "slot_system_native", sizeof(OutInfo->Variant) - 1);
}

// Instance state is CACHES ONLY, never parameters - every call carries what it needs. None here.
void* PayloadCreateInstance(void) { return nullptr; }
void PayloadDestroyInstance(void*) {}

MaxMcpPayloadResult PayloadCall(void*, const char* Function, const char* ArgumentsJson,
                                char* ReplyJson, size_t ReplyCapacity)
{
    if (Function == nullptr) { return MAXMCP_PAYLOAD_NO_FUNCTION; }
    JsonValue Args;
    ParseJson(ArgumentsJson != nullptr ? ArgumentsJson : "{}", Args);
    JsonValue Result;
    if (std::strcmp(Function, "HelperLines") == 0) { Result = HelperLines(Args); }
    else if (std::strcmp(Function, "describe_params") == 0) { Result = DescribeParams(); }
    else if (std::strcmp(Function, "describe_ui") == 0) { Result = DescribeUi(Args); }
    else if (std::strcmp(Function, "on_ui_event") == 0) { Result = OnUiEvent(); }
    else
    {
        // Anything else falls through to the Python lane - the routing answer, not a failure.
        return MAXMCP_PAYLOAD_NO_FUNCTION;
    }
    JsonValue Reply = JsonValue::Object();
    Reply.Set("ok", JsonValue::Bool(true));
    Reply.Set("result", Result);
    return WriteReply(Reply, ReplyJson, ReplyCapacity) ? MAXMCP_PAYLOAD_OK
                                                       : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
}

MaxMcpPayloadResult PayloadCallBuffers(void*, const char*, const MaxMcpBuffer*, size_t,
                                       const char*, char*, size_t)
{
    return MAXMCP_PAYLOAD_NO_FUNCTION;
}

void PayloadSetLogSink(MaxMcpPayloadLogSink Sink, void* Context)
{
    GSink = Sink;
    GSinkContext = Context;
    if (Sink != nullptr)
    {
        const std::string Line =
            std::string("Barebones System (C++) native payload loaded: v") + CARTRIDGE_VERSION_STRING
            + " built " + CARTRIDGE_BUILD_STAMP
            + ". This is the load report, not the greeting - the greeting comes from the first draw.";
        Sink(Context, 2 /* Display */, Line.c_str());
    }
}

// This payload needs no facade: it returns numbers.
void PayloadSetFacade(const MaxMcpFacadeApi*) {}

const MaxMcpPayloadApi GPayloadApi =
{
    &PayloadDescribe,
    &PayloadCreateInstance,
    &PayloadDestroyInstance,
    &PayloadCall,
    &PayloadCallBuffers,
    &PayloadSetLogSink,
    &PayloadSetFacade,
    nullptr,   // no host callbacks declared: HelperLines is asked by the slot, not by 3ds Max
};

}

extern "C" __declspec(dllexport) const MaxMcpPayloadApi* MaxMcpGetPayload(uint32_t AbiVersion)
{
    return AbiVersion == MAXMCP_PAYLOAD_ABI ? &GPayloadApi : nullptr;
}
