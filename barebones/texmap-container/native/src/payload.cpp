// Barebones Texmap Container - native lane. A container that holds no texmaps. No 3ds Max SDK.
#include "CartridgePayloadApi.h"
#include "MaxFacadeApi.h"
#include "Json.h"
#include "VersionGenerated.h"
#include <cstring>
#include <string>
namespace {
using maxmcp::JsonValue; using maxmcp::ParseJson;
MaxMcpPayloadLogSink GSink=nullptr; void* GCtx=nullptr;
void Say(const char* L){ if(GSink) GSink(GCtx,2,L); }
bool WriteReply(const JsonValue& R,char* J,size_t C){ const std::string T=R.Serialize(); if(!J||T.size()+1>C) return false; std::memcpy(J,T.c_str(),T.size()+1); return true; }
JsonValue Describe(){
    static bool said=false;
    if(!said){ said=true; Say("Hello World - Barebones Texmap Container (C++) is live; this line came from its payload the first time the host asked the container for its class name."); }
    JsonValue o=JsonValue::Object(); o.Set("name",JsonValue::String("Cartridge Texmap Container")); return o;
}
void PDescribe(MaxMcpPayloadInfo* I){ if(!I) return; I->AbiVersion=MAXMCP_PAYLOAD_ABI; std::strncpy(I->Name,"slot_texcontainer",sizeof(I->Name)-1); std::strncpy(I->Version,CARTRIDGE_VERSION_STRING,sizeof(I->Version)-1); std::strncpy(I->Variant,"slot_texcontainer_native",sizeof(I->Variant)-1); }
void* Ci(void){ return nullptr; } void Di(void*){}
MaxMcpPayloadResult Call(void*,const char* F,const char* A,char* J,size_t C){
    if(!F) return MAXMCP_PAYLOAD_NO_FUNCTION; JsonValue Args; ParseJson(A?A:"{}",Args); JsonValue Res;
    if(!std::strcmp(F,"Describe")) Res=Describe(); else return MAXMCP_PAYLOAD_NO_FUNCTION;
    JsonValue Rep=JsonValue::Object(); Rep.Set("ok",JsonValue::Bool(true)); Rep.Set("result",Res);
    return WriteReply(Rep,J,C)?MAXMCP_PAYLOAD_OK:MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
}
MaxMcpPayloadResult CallB(void*,const char*,const MaxMcpBuffer*,size_t,const char*,char*,size_t){ return MAXMCP_PAYLOAD_NO_FUNCTION; }
void SetSink(MaxMcpPayloadLogSink S,void* C){ GSink=S; GCtx=C; if(S){ const std::string L=std::string("Barebones Texmap Container (C++) native payload loaded: v")+CARTRIDGE_VERSION_STRING+". This is the load report, not the greeting."; S(C,2,L.c_str()); } }
void SetFacade(const MaxMcpFacadeApi*){}
const MaxMcpPayloadApi GApi={ &PDescribe,&Ci,&Di,&Call,&CallB,&SetSink,&SetFacade,nullptr };
}
extern "C" __declspec(dllexport) const MaxMcpPayloadApi* MaxMcpGetPayload(uint32_t A){ return A==MAXMCP_PAYLOAD_ABI?&GApi:nullptr; }
