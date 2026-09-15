// Barebones Bake Map (C++ native lane) - documents the shape - this super-class is not third-party registerable.
//
// A Bake To Texture common bake map - one bakeable channel in the Bake To Texture dialog. SuperClassID COMMON_BAKE_MAP_CLASS_ID. No slot ships for this type, and none ever will - the super-class is not open to third-party registration (see this example's README for the SDK-checked reason); this is the shape.
// Says hello on load through the log sink once a slot hosts it. Links lib/mcpjson.lib only; no SDK.
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
    std::strncpy(OutInfo->Name, "slot_bakemap", sizeof(OutInfo->Name) - 1);
    std::strncpy(OutInfo->Version, CARTRIDGE_VERSION_STRING, sizeof(OutInfo->Version) - 1);
    std::strncpy(OutInfo->Variant, "slot_bakemap_native", sizeof(OutInfo->Variant) - 1);
}

void* PayloadCreateInstance(void) { return nullptr; }
void PayloadDestroyInstance(void*) {}

MaxMcpPayloadResult PayloadCall(void*, const char* Function, const char*, char*, size_t)
{
    (void)Function;
    return MAXMCP_PAYLOAD_NO_FUNCTION;
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
            std::string("Hello World - Barebones Bake Map (C++) native payload loaded: v")
            + CARTRIDGE_VERSION_STRING + " built " + CARTRIDGE_BUILD_STAMP;
        Sink(Context, 2 /* Display */, Line.c_str());
    }
}

const MaxMcpPayloadApi GPayloadApi =
{
    &PayloadDescribe, &PayloadCreateInstance, &PayloadDestroyInstance,
    &PayloadCall, &PayloadCallBuffers, &PayloadSetLogSink, nullptr, nullptr,
};
}

extern "C" __declspec(dllexport) const MaxMcpPayloadApi* MaxMcpGetPayload(uint32_t AbiVersion)
{
    return AbiVersion == MAXMCP_PAYLOAD_ABI ? &GPayloadApi : nullptr;
}
