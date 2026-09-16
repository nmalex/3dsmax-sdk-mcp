// Barebones Manipulator - native lane. A plain DLL the slot loads; 3ds Max never sees it. No 3ds Max SDK.
//
// WHAT THIS SHOWS. The whole native-payload skeleton - the one export MaxMcpGetPayload, the ABI
// match, the log sink - and then the thing the skeleton is for: this payload DRAWS. It builds a
// wireframe tetrahedron in the viewport, edge by edge, through the host facade. The geometry you see
// is described here, in a cartridge, and nothing in this file touches the 3ds Max SDK.
//
// THE TWO LANES, AND HOW EACH REACHES THE FACADE. This is the clearest place in the kit to see the
// difference:
//
//   native (here)   the shell hands the facade table straight to the payload, once, through
//                   SetFacade. GFacade below is that table; there is no address to look up.
//   Python (../../python/slot_manipulator.py)
//                   every callback event carries `slot`, the table's address as a decimal string,
//                   and mcp_facade.from_address(slot) turns it back into the callable table.
//
// Same table, same entries, same tetrahedron - two ways of being handed the pointer, because one
// lane has a C ABI to pass it across and the other has JSON.
//
// NO SDK, ON PURPOSE. This links lib\mcpjson.lib and includes the facade contract, which is not the
// SDK: it is plain C over opaque handles. A payload that never touches the SDK loads into a bare
// interpreter for testing, hot-swaps while the host runs, and is not tied to the 3ds Max version it
// was built against. Everything the SDK is for happens on the other side of the boundary, in the
// slot. See LAW.md, LAW-1.
#include "CartridgePayloadApi.h"
#include "MaxFacadeApi.h"
#include "Json.h"

#include "VersionGenerated.h"

#include <cstring>
#include <string>

namespace
{

using maxmcp::JsonValue;
using maxmcp::ParseJson;

MaxMcpPayloadLogSink GSink = nullptr;
void* GSinkContext = nullptr;

// The host facade, handed over once at load by SetFacade below. Null until then, and null forever
// in a shell that publishes none - so every use is guarded rather than assumed.
const MaxMcpFacadeApi* GFacade = nullptr;

// The callback the manipulator slot relays on every viewport redraw of the gizmo. The name is the
// contract; the slot tries the native lane first and falls through to Python when this answers
// NO_FUNCTION.
const char* const kUpdateShapes = "ManipUpdateShapes";

// Half-edge of the tetrahedron, in 3ds Max system units: four alternate corners of a cube.
const float kSize = 15.0f;

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

// Four polylines: the closed base triangle, then one edge up to the apex from each of its corners.
// Every call goes through the borrowed builder token; the GizmoShape the slot owns never crosses.
int DrawTetrahedron(MaxMcpHeld Builder)
{
    const MaxMcpPoint3 Apex = { kSize, kSize, kSize };
    const MaxMcpPoint3 Base[3] = {
        { kSize, -kSize, -kSize }, { -kSize, kSize, -kSize }, { -kSize, -kSize, kSize },
    };

    int Runs = 0;
    if (GFacade->GizmoShapeAppendPolyline(GFacade->Context, Builder, Base, 3, 1)
        == MAXMCP_FACADE_OK)
    {
        ++Runs;
    }
    for (int i = 0; i < 3; ++i)
    {
        const MaxMcpPoint3 Edge[2] = { Apex, Base[i] };
        if (GFacade->GizmoShapeAppendPolyline(GFacade->Context, Builder, Edge, 2, 0)
            == MAXMCP_FACADE_OK)
        {
            ++Runs;
        }
    }

    // Cyan, so it reads as "the cartridge drew this" rather than as the slot's fallback circle.
    const MaxMcpPoint3 Colour = { 0.2f, 0.8f, 1.0f };
    GFacade->GizmoBuildSetAppearance(GFacade->Context, Builder, &Colour, 0);
    return Runs;
}

MaxMcpPayloadResult HandleUpdateShapes(const char* ArgumentsJson, char* ReplyJson,
                                       size_t ReplyCapacity)
{
    JsonValue Args;
    ParseJson(ArgumentsJson != nullptr ? ArgumentsJson : "{}", Args);
    const JsonValue& Event = Args.At("event");

    // THE PROBE CONTRACT. The shell calls every declared name once at load with this set, to prove
    // the function exists before 3ds Max is ever told about it. A handler MUST return without doing
    // its work - the probe is about existence, not behaviour.
    JsonValue Reply = JsonValue::Object();
    Reply.Set("ok", JsonValue::Bool(true));
    if (Event.At("probe").AsNumber(0.0) != 0.0)
    {
        return WriteReply(Reply, ReplyJson, ReplyCapacity) ? MAXMCP_PAYLOAD_OK
                                                           : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
    }

    static bool bSaidHello = false;
    if (!bSaidHello)
    {
        bSaidHello = true;
        Say("Hello World - Barebones Manipulator (C++) is live; this line came from its payload on "
            "the first display (ManipUpdateShapes).");
    }

    if (GFacade == nullptr || GFacade->ManipCurrentGizmoBuild == nullptr
        || GFacade->GizmoShapeAppendPolyline == nullptr)
    {
        // Answered, and honest about answering with nothing: the slot then draws its own fallback.
        Reply.Set("why", JsonValue::String("this shell published no gizmo-build facade"));
        return WriteReply(Reply, ReplyJson, ReplyCapacity) ? MAXMCP_PAYLOAD_OK
                                                           : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
    }

    // The EMPTY GizmoShape the slot borrowed for exactly this callback's span. Outside it the token
    // is stale and every accessor refuses - which is the borrow rule working, not a failure.
    int32_t Active = 0;
    MaxMcpHeld Builder = 0;
    if (GFacade->ManipCurrentGizmoBuild(GFacade->Context, &Active, &Builder) != MAXMCP_FACADE_OK
        || Active == 0 || Builder == 0)
    {
        Reply.Set("why", JsonValue::String("no gizmo build is in progress"));
        return WriteReply(Reply, ReplyJson, ReplyCapacity) ? MAXMCP_PAYLOAD_OK
                                                           : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
    }

    const int Runs = DrawTetrahedron(Builder);

    // Said ONCE, on the first gizmo actually built. A drawing is evidence only to somebody looking
    // at the viewport; this line is the same fact in the log, where a verifier can read it.
    static bool bSaidDrew = false;
    if (!bSaidDrew)
    {
        bSaidDrew = true;
        Say((std::string("Barebones Manipulator drew a wireframe tetrahedron: ")
             + std::to_string(Runs)
             + " polyline run(s) appended to the borrowed GizmoShape through the facade, from C++.")
                .c_str());
    }

    Reply.Set("runs", JsonValue::Number(static_cast<double>(Runs)));
    Reply.Set("shapes", JsonValue::String("tetrahedron"));
    return WriteReply(Reply, ReplyJson, ReplyCapacity) ? MAXMCP_PAYLOAD_OK
                                                       : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
}

void PayloadDescribe(MaxMcpPayloadInfo* OutInfo)
{
    if (OutInfo == nullptr) { return; }
    OutInfo->AbiVersion = MAXMCP_PAYLOAD_ABI;
    std::strncpy(OutInfo->Name, "slot_manipulator", sizeof(OutInfo->Name) - 1);
    std::strncpy(OutInfo->Version, CARTRIDGE_VERSION_STRING, sizeof(OutInfo->Version) - 1);
    std::strncpy(OutInfo->Variant, "slot_manipulator_native", sizeof(OutInfo->Variant) - 1);
}

// Instance state is CACHES ONLY, never parameters - every call carries what it needs. None here.
void* PayloadCreateInstance(void) { return nullptr; }
void PayloadDestroyInstance(void*) {}

MaxMcpPayloadResult PayloadCall(void*, const char* Function, const char* ArgumentsJson,
                                char* ReplyJson, size_t ReplyCapacity)
{
    if (Function != nullptr && std::strcmp(Function, kUpdateShapes) == 0)
    {
        return HandleUpdateShapes(ArgumentsJson, ReplyJson, ReplyCapacity);
    }
    // Anything else falls through to the Python lane - the routing answer, not a failure. It is also
    // what makes the load-time probe work: a name this function does not know answers NO_FUNCTION.
    return MAXMCP_PAYLOAD_NO_FUNCTION;
}

MaxMcpPayloadResult PayloadCallBuffers(void*, const char*, const MaxMcpBuffer*, size_t,
                                       const char*, char*, size_t)
{
    // Buffers carry bulk data (a modifier's vertex array). Not used by this example.
    return MAXMCP_PAYLOAD_NO_FUNCTION;
}

void PayloadSetLogSink(MaxMcpPayloadLogSink Sink, void* Context)
{
    GSink = Sink;
    GSinkContext = Context;
    if (Sink != nullptr)
    {
        const std::string Line =
            std::string("Barebones Manipulator (C++) native payload loaded: v")
            + CARTRIDGE_VERSION_STRING + " built " + CARTRIDGE_BUILD_STAMP
            + ". This is the load report, not the greeting - the greeting comes from the first "
              "gizmo display.";
        Sink(Context, 2 /* Display */, Line.c_str());
    }
}

// THE FACADE, handed over once at load and held for the module's life. The table belongs to the
// shell and outlives every payload generation, so holding this pointer is safe in a way that holding
// anything from the 3ds Max SDK never would be.
void PayloadSetFacade(const MaxMcpFacadeApi* Slot) { GFacade = Slot; }

const MaxMcpPayloadApi GPayloadApi =
{
    &PayloadDescribe,
    &PayloadCreateInstance,
    &PayloadDestroyInstance,
    &PayloadCall,
    &PayloadCallBuffers,
    &PayloadSetLogSink,
    &PayloadSetFacade,
    nullptr,   // no host callbacks DECLARED: ManipUpdateShapes is relayed by the slot that hosts
               // this kind, not registered with 3ds Max by name. DeclareCallbacks is for a payload
               // that wants a NOTIFICATION or a plugin virtual of its own.
};

}

extern "C" __declspec(dllexport) const MaxMcpPayloadApi* MaxMcpGetPayload(uint32_t AbiVersion)
{
    return AbiVersion == MAXMCP_PAYLOAD_ABI ? &GPayloadApi : nullptr;
}
