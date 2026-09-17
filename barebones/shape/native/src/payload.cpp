// Barebones Shape - native lane. A pentagon: the smallest real spline shape. No 3ds Max SDK.
//
// The shape slot (a SimpleSpline) asks its cartridge for polylines:
//     BuildShape(params, time) -> {"polylines": [{"points": [[x, y, z], ...], "closed": true}, ...]}
// The slot builds a BezierShape from them. This payload returns a closed regular pentagon.
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
const double kRadius = 30.0;
const int kSides = 5;

void Say(const char* Line) { if (GSink != nullptr) { GSink(GSinkContext, 2, Line); } }

bool WriteReply(const JsonValue& Reply, char* ReplyJson, size_t ReplyCapacity)
{
    const std::string Text = Reply.Serialize();
    if (ReplyJson == nullptr || Text.size() + 1 > ReplyCapacity) { return false; }
    std::memcpy(ReplyJson, Text.c_str(), Text.size() + 1);
    return true;
}

JsonValue BuildShape()
{
    static bool bSaidHello = false;
    if (!bSaidHello)
    {
        bSaidHello = true;
        Say("Hello World - Barebones Shape (C++) is live; this line came from its payload on the "
            "first BuildShape, a 5-sided polygon.");
    }
    JsonValue Points = JsonValue::Array();
    for (int i = 0; i < kSides; ++i)
    {
        const double A = 3.14159265358979 / 2 + i * 2 * 3.14159265358979 / kSides;
        JsonValue P = JsonValue::Array();
        P.Push(JsonValue::Number(kRadius * std::cos(A)));
        P.Push(JsonValue::Number(kRadius * std::sin(A)));
        P.Push(JsonValue::Number(0.0));
        Points.Push(P);
    }
    JsonValue Line = JsonValue::Object();
    Line.Set("points", Points);
    Line.Set("closed", JsonValue::Bool(true));
    JsonValue Lines = JsonValue::Array();
    Lines.Push(Line);
    JsonValue Out = JsonValue::Object();
    Out.Set("polylines", Lines);
    return Out;
}

JsonValue DescribeUi()
{
    namespace ui = maxmcp::payloadui;
    ui::VBoxWidget Root;
    auto Title = std::make_shared<ui::LabelWidget>(); Title->Text = "Cartridge Shape";
    Root.Children.push_back(Title);
    Root.Children.push_back(std::make_shared<ui::SpacerWidget>());
    auto L = std::make_shared<ui::LabelWidget>(); L->Text = "A 5-sided polygon.";
    Root.Children.push_back(L);
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

void PayloadDescribe(MaxMcpPayloadInfo* OutInfo)
{
    if (OutInfo == nullptr) { return; }
    OutInfo->AbiVersion = MAXMCP_PAYLOAD_ABI;
    std::strncpy(OutInfo->Name, "slot_shape", sizeof(OutInfo->Name) - 1);
    std::strncpy(OutInfo->Version, CARTRIDGE_VERSION_STRING, sizeof(OutInfo->Version) - 1);
    std::strncpy(OutInfo->Variant, "slot_shape_native", sizeof(OutInfo->Variant) - 1);
}

void* PayloadCreateInstance(void) { return nullptr; }
void PayloadDestroyInstance(void*) {}

MaxMcpPayloadResult PayloadCall(void*, const char* Function, const char* ArgumentsJson,
                                char* ReplyJson, size_t ReplyCapacity)
{
    if (Function == nullptr) { return MAXMCP_PAYLOAD_NO_FUNCTION; }
    JsonValue Args;
    ParseJson(ArgumentsJson != nullptr ? ArgumentsJson : "{}", Args);
    JsonValue Result;
    if (std::strcmp(Function, "BuildShape") == 0) { Result = BuildShape(); }
    else if (std::strcmp(Function, "describe_ui") == 0) { Result = DescribeUi(); }
    else if (std::strcmp(Function, "on_ui_event") == 0) { Result = OnUiEvent(); }
    else { return MAXMCP_PAYLOAD_NO_FUNCTION; }
    JsonValue Reply = JsonValue::Object();
    Reply.Set("ok", JsonValue::Bool(true));
    Reply.Set("result", Result);
    return WriteReply(Reply, ReplyJson, ReplyCapacity) ? MAXMCP_PAYLOAD_OK : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
}

MaxMcpPayloadResult PayloadCallBuffers(void*, const char*, const MaxMcpBuffer*, size_t, const char*, char*, size_t)
{ return MAXMCP_PAYLOAD_NO_FUNCTION; }

void PayloadSetLogSink(MaxMcpPayloadLogSink Sink, void* Context)
{
    GSink = Sink; GSinkContext = Context;
    if (Sink != nullptr)
    {
        const std::string Line = std::string("Barebones Shape (C++) native payload loaded: v")
            + CARTRIDGE_VERSION_STRING + " built " + CARTRIDGE_BUILD_STAMP
            + ". This is the load report, not the greeting - the greeting comes from the first BuildShape.";
        Sink(Context, 2, Line.c_str());
    }
}

void PayloadSetFacade(const MaxMcpFacadeApi*) {}

const MaxMcpPayloadApi GPayloadApi = {
    &PayloadDescribe, &PayloadCreateInstance, &PayloadDestroyInstance, &PayloadCall,
    &PayloadCallBuffers, &PayloadSetLogSink, &PayloadSetFacade, nullptr,
};
}

extern "C" __declspec(dllexport) const MaxMcpPayloadApi* MaxMcpGetPayload(uint32_t AbiVersion)
{ return AbiVersion == MAXMCP_PAYLOAD_ABI ? &GPayloadApi : nullptr; }
