// Barebones Geometry - native lane. A parametric cube: the smallest real geometry object.
// A plain DLL the slot loads; 3ds Max never sees it. No 3ds Max SDK.
//
// The geometry slot (a SimpleObject2) asks its cartridge for a mesh:
//
//     BuildMesh(params, time) -> {"verts": [[x, y, z], ...], "faces": [[a, b, c], ...]}
//
// The faces are triangles of 0-based vertex indices, the mesh in object space. The slot fills its
// Mesh from them and does the rest - display, hit-test, render, convert. This payload returns a cube
// whose edge is `size`, and touches neither the viewport nor the SDK. It also answers the panel, so
// the C++ lane stands alone.
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

// The cube's edge, in system units - the declared default.
const double kDefaultSize = 30.0;

// The eight corners of a unit cube (half-edge 1), and its twelve triangles, wound outward.
const double kCorners[8][3] = { {-1,-1,-1}, {1,-1,-1}, {1,1,-1}, {-1,1,-1},
                                {-1,-1,1}, {1,-1,1}, {1,1,1}, {-1,1,1} };
const int kTris[12][3] = { {0,2,1},{0,3,2}, {4,5,6},{4,6,7}, {0,1,5},{0,5,4},
                           {1,2,6},{1,6,5}, {2,3,7},{2,7,6}, {3,0,4},{3,4,7} };

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

JsonValue BuildMesh(const JsonValue& Args)
{
    const double Size = SizeOf(Args);
    static bool bSaidHello = false;
    if (!bSaidHello)
    {
        bSaidHello = true;
        Say(("Hello World - Barebones Geometry (C++) is live; this line came from its payload on the "
             "first evaluation (BuildMesh), a cube of edge " + std::to_string(Size) + ".").c_str());
    }
    const double Half = Size * 0.5;
    JsonValue Verts = JsonValue::Array();
    for (const auto& C : kCorners)
    {
        JsonValue V = JsonValue::Array();
        V.Push(JsonValue::Number(C[0] * Half));
        V.Push(JsonValue::Number(C[1] * Half));
        V.Push(JsonValue::Number(C[2] * Half));
        Verts.Push(V);
    }
    JsonValue Faces = JsonValue::Array();
    for (const auto& T : kTris)
    {
        JsonValue F = JsonValue::Array();
        F.Push(JsonValue::Number(T[0]));
        F.Push(JsonValue::Number(T[1]));
        F.Push(JsonValue::Number(T[2]));
        Faces.Push(F);
    }
    JsonValue Out = JsonValue::Object();
    Out.Set("verts", Verts);
    Out.Set("faces", Faces);
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
    Title->Text = "Cartridge Geometry";
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
    std::strncpy(OutInfo->Name, "slot_geometry", sizeof(OutInfo->Name) - 1);
    std::strncpy(OutInfo->Version, CARTRIDGE_VERSION_STRING, sizeof(OutInfo->Version) - 1);
    std::strncpy(OutInfo->Variant, "slot_geometry_native", sizeof(OutInfo->Variant) - 1);
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
    if (std::strcmp(Function, "BuildMesh") == 0) { Result = BuildMesh(Args); }
    else if (std::strcmp(Function, "describe_params") == 0) { Result = DescribeParams(); }
    else if (std::strcmp(Function, "describe_ui") == 0) { Result = DescribeUi(Args); }
    else if (std::strcmp(Function, "on_ui_event") == 0) { Result = OnUiEvent(); }
    else
    {
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
            std::string("Barebones Geometry (C++) native payload loaded: v") + CARTRIDGE_VERSION_STRING
            + " built " + CARTRIDGE_BUILD_STAMP
            + ". This is the load report, not the greeting - the greeting comes from the first "
              "evaluation.";
        Sink(Context, 2 /* Display */, Line.c_str());
    }
}

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
    nullptr,   // no host callbacks declared: BuildMesh is asked by the slot, not by 3ds Max
};

}

extern "C" __declspec(dllexport) const MaxMcpPayloadApi* MaxMcpGetPayload(uint32_t AbiVersion)
{
    return AbiVersion == MAXMCP_PAYLOAD_ABI ? &GPayloadApi : nullptr;
}
