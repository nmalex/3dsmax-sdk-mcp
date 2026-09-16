// @DISPLAY_NAME@ - an exporter cartridge, native lane. The slot walks the scene; you format the text.
//
// SAME CONTRACT AS THE PYTHON LANE, same six calls, same JSON. What differs is only that you are
// compiled: the slot hands you a JSON string and a reply buffer instead of keyword arguments.
//
//     describe_ui           once, when the host is prompting
//     format_header         once, first
//     format_material_list  when the scene had materials
//     format_group_open     before a group head and its descendants
//     format_node           once per node, depth-first, pre-order
//     format_group_close    after a group's descendants
//
// EVERY format_* REPLY IS {"ok": true, "result": {"text": "..."}} - the text including its trailing
// newline. The slot writes it verbatim. A function you do not serve returns NO_FUNCTION, and the
// slot then tries the Python lane; that is how one cartridge can be half native.
//
// NO 3DS MAX SDK ANYWHERE IN THIS PROJECT, and that is the architecture rather than a shortcut. A
// payload that never touches the SDK loads into a bare interpreter for testing, can be hot-swapped
// while the host is running, and is not tied to the 3ds Max version it was built against. The slot
// holds every SDK call on the other side of this boundary.
//
// TWO FACTS ABOUT THE MESH THAT WILL BITE YOU IF YOU ASSUME OTHERWISE:
//   * vertices arrive in WORLD space - do not multiply by the node transform again;
//   * face corner order is already corrected for negatively-scaled nodes - do not re-wind it.

#include "CartridgePayloadApi.h"
#include "Json.h"

#include "VersionGenerated.h"

#include <cstring>
#include <string>

using maxmcp::JsonValue;

namespace
{

MaxMcpPayloadLogSink GSink = nullptr;
void* GSinkContext = nullptr;

// The one reply shape every format_* function returns.
bool WriteTextReply(const std::string& Text, char* ReplyJson, size_t ReplyCapacity)
{
    JsonValue Result = JsonValue::Object();
    Result.Set("text", JsonValue::String(Text));
    JsonValue Reply = JsonValue::Object();
    Reply.Set("ok", JsonValue::Bool(true));
    Reply.Set("result", Result);
    const std::string Serialized = Reply.Serialize();
    if (Serialized.size() + 1 > ReplyCapacity) { return false; }
    std::memcpy(ReplyJson, Serialized.c_str(), Serialized.size() + 1);
    return true;
}

void PayloadDescribe(MaxMcpPayloadInfo* OutInfo)
{
    if (OutInfo == nullptr) { return; }
    OutInfo->AbiVersion = MAXMCP_PAYLOAD_ABI;
    std::strncpy(OutInfo->Name, "@MODULE@", sizeof(OutInfo->Name) - 1);
    std::strncpy(OutInfo->Version, CARTRIDGE_VERSION_STRING, sizeof(OutInfo->Version) - 1);
    std::strncpy(OutInfo->Variant, "@MODULE@_native", sizeof(OutInfo->Variant) - 1);
}

// Instance state is CACHES ONLY and never parameters - every call carries what it needs. This
// cartridge keeps none, so there is nothing to create and nothing to destroy.
void* PayloadCreateInstance(void) { return nullptr; }
void PayloadDestroyInstance(void*) {}

// The whole cartridge. Arguments arrive as one JSON object; which keys are present depends on which
// function the slot is calling - see the Python template's docstrings for the full argument tables.
MaxMcpPayloadResult PayloadCall(void*, const char* Function, const char* ArgsJson,
                                char* ReplyJson, size_t ReplyCapacity)
{
    if (Function == nullptr) { return MAXMCP_PAYLOAD_NO_FUNCTION; }

    JsonValue Args;
    if (ArgsJson != nullptr && *ArgsJson != '\0') { maxmcp::ParseJson(ArgsJson, Args); }

    if (std::strcmp(Function, "format_header") == 0)
    {
        const std::string Scene = Args.At("scene").At("name").AsString();
        return WriteTextReply("# @DISPLAY_NAME@\n# scene: " + (Scene.empty() ? "untitled" : Scene) + "\n",
                              ReplyJson, ReplyCapacity)
            ? MAXMCP_PAYLOAD_OK : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
    }

    if (std::strcmp(Function, "format_material_list") == 0)
    {
        // The walk order IS the reference numbering - a node naming material 2 means the third
        // entry here. Do not sort it.
        const size_t Count = Args.At("materials").AsArray().size();
        return WriteTextReply("# materials: " + std::to_string(Count) + "\n",
                              ReplyJson, ReplyCapacity)
            ? MAXMCP_PAYLOAD_OK : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
    }

    if (std::strcmp(Function, "format_group_open") == 0)
    {
        return WriteTextReply("# group " + Args.At("node").At("name").AsString() + "\n",
                              ReplyJson, ReplyCapacity)
            ? MAXMCP_PAYLOAD_OK : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
    }

    if (std::strcmp(Function, "format_group_close") == 0)
    {
        return WriteTextReply("# end group\n", ReplyJson, ReplyCapacity)
            ? MAXMCP_PAYLOAD_OK : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
    }

    if (std::strcmp(Function, "format_node") == 0)
    {
        const JsonValue& Node = Args.At("node");
        const size_t Vertices = Node.At("vertices").AsArray().size() / 3;
        const size_t Faces = Node.At("faces").AsArray().size() / 3;
        const std::string Line = Node.At("name").AsString()
            + "  kind=" + Node.At("kind").AsString()
            + "  verts=" + std::to_string(Vertices)
            + "  faces=" + std::to_string(Faces) + "\n";
        return WriteTextReply(Line, ReplyJson, ReplyCapacity)
            ? MAXMCP_PAYLOAD_OK : MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
    }

    // describe_ui is left to the Python lane by returning NO_FUNCTION: the options panel is
    // composition, which is where a language with closures earns its keep. Serve it here too if you
    // would rather have one lane.
    return MAXMCP_PAYLOAD_NO_FUNCTION;
}

MaxMcpPayloadResult PayloadCallBuffers(void*, const char*, const MaxMcpBuffer*, size_t,
                                       const char*, char*, size_t)
{
    // Buffers are for payloads handed bulk data - a modifier's vertex array. An exporter is called
    // with JSON, so this lane is not served.
    return MAXMCP_PAYLOAD_NO_FUNCTION;
}

void PayloadSetLogSink(MaxMcpPayloadLogSink Sink, void* Context)
{
    GSink = Sink;
    GSinkContext = Context;
    if (Sink != nullptr)
    {
        const std::string Line = std::string("native payload up: v") + CARTRIDGE_VERSION_STRING
            + " built " + CARTRIDGE_BUILD_STAMP;
        Sink(Context, 2 /* Display */, Line.c_str());
    }
}

const MaxMcpPayloadApi GPayloadApi =
{
    &PayloadDescribe,
    &PayloadCreateInstance,
    &PayloadDestroyInstance,
    &PayloadCall,
    &PayloadCallBuffers,
    &PayloadSetLogSink,
    // No host facade: this cartridge formats what it is handed and asks the host nothing. Stated
    // rather than left off the end of the initialiser, so the next reader knows it is a decision.
    nullptr,
    // No host callbacks declared.
    nullptr,
};

}

// The one export. The slot asks for a table at the ABI it was built against, and a mismatch answers
// null rather than handing over a table whose shape has changed underneath it.
extern "C" __declspec(dllexport) const MaxMcpPayloadApi* MaxMcpGetPayload(uint32_t AbiVersion)
{
    return AbiVersion == MAXMCP_PAYLOAD_ABI ? &GPayloadApi : nullptr;
}
