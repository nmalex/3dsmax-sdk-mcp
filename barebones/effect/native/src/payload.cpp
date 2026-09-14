// Barebones Render Effect - native lane. A plain DLL the slot loads; 3ds Max never sees it. No 3ds Max SDK.
//
// WHAT THIS SHOWS. The whole native-payload skeleton: the one export MaxMcpGetPayload, the ABI
// match, and the log sink. It says "hello" once, when the slot loads it, through the sink - the
// native lane's equivalent of the Python lane's logged line, and it lands in the same place
// (cartridge_logs -module slot_effect). The type's own functions are left to the default here; the
// Python lane in ../python/slot_effect.py shows their shape, and PayloadCall below is where a native
// author serves them.
//
// NO SDK, ON PURPOSE. This links lib/mcpjson.lib only. A payload that never touches the SDK loads
// into a bare interpreter for testing, hot-swaps while the host runs, and is not tied to the 3ds
// Max version it was built against. Everything the SDK is for happens on the other side of the
// boundary, in the slot.
#include "CartridgePayloadApi.h"
#include "Json.h"

#include "VersionGenerated.h"

#include <cstring>
#include <string>

namespace
{

MaxMcpPayloadLogSink GSink = nullptr;
void* GSinkContext = nullptr;

void PayloadDescribe(MaxMcpPayloadInfo* OutInfo)
{
    if (OutInfo == nullptr) { return; }
    OutInfo->AbiVersion = MAXMCP_PAYLOAD_ABI;
    std::strncpy(OutInfo->Name, "slot_effect", sizeof(OutInfo->Name) - 1);
    std::strncpy(OutInfo->Version, CARTRIDGE_VERSION_STRING, sizeof(OutInfo->Version) - 1);
    std::strncpy(OutInfo->Variant, "slot_effect_native", sizeof(OutInfo->Variant) - 1);
}

// Instance state is CACHES ONLY, never parameters - every call carries what it needs. None here.
void* PayloadCreateInstance(void) { return nullptr; }
void PayloadDestroyInstance(void*) {}

MaxMcpPayloadResult PayloadCall(void*, const char* Function, const char* /*ArgsJson*/,
                                char* /*ReplyJson*/, size_t /*ReplyCapacity*/)
{
    // The native lane serves the same named functions the Python lane does (see ../python/slot_effect.py).
    // This barebones leaves them to the default so the load-time hello is the whole example. To add
    // behaviour: match Function, parse ArgsJson with maxmcp::ParseJson, and write a JSON reply.
    (void)Function;
    return MAXMCP_PAYLOAD_NO_FUNCTION;
}

MaxMcpPayloadResult PayloadCallBuffers(void*, const char*, const MaxMcpBuffer*, size_t,
                                       const char*, char*, size_t)
{
    // Buffers carry bulk data (a modifier's vertex array). Not served by this inert example.
    return MAXMCP_PAYLOAD_NO_FUNCTION;
}

void PayloadSetLogSink(MaxMcpPayloadLogSink Sink, void* Context)
{
    GSink = Sink;
    GSinkContext = Context;
    if (Sink != nullptr)
    {
        const std::string Line =
            std::string("Hello World - Barebones Render Effect (C++) native payload loaded: v")
            + CARTRIDGE_VERSION_STRING + " built " + CARTRIDGE_BUILD_STAMP;
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
    nullptr,   // no host facade: this cartridge asks the host nothing.
    nullptr,   // no host callbacks declared.
};

}

extern "C" __declspec(dllexport) const MaxMcpPayloadApi* MaxMcpGetPayload(uint32_t AbiVersion)
{
    return AbiVersion == MAXMCP_PAYLOAD_ABI ? &GPayloadApi : nullptr;
}
