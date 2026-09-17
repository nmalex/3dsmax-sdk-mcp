// Barebones Light - native lane. A warm-white omni light. No 3ds Max SDK.
//     LightState(params, time) -> {"color": [r, g, b], "intensity": f}
#include "CartridgePayloadApi.h"
#include "MaxFacadeApi.h"
#include "Json.h"
#include "PayloadUi.h"
#include "VersionGenerated.h"
#include <cstring>
#include <memory>
#include <string>
namespace {
using maxmcp::JsonValue; using maxmcp::ParseJson;
MaxMcpPayloadLogSink GSink = nullptr; void* GSinkContext = nullptr;
void Say(const char* L){ if(GSink) GSink(GSinkContext,2,L); }
bool WriteReply(const JsonValue& R, char* J, size_t C){ const std::string T=R.Serialize(); if(!J||T.size()+1>C) return false; std::memcpy(J,T.c_str(),T.size()+1); return true; }
JsonValue LightState(){
    static bool said=false;
    if(!said){ said=true; Say("Hello World - Barebones Light (C++) is live; this line came from its payload on the first LightState, a warm-white omni light."); }
    JsonValue col=JsonValue::Array(); col.Push(JsonValue::Number(1.0)); col.Push(JsonValue::Number(0.9)); col.Push(JsonValue::Number(0.75));
    JsonValue o=JsonValue::Object(); o.Set("color",col); o.Set("intensity",JsonValue::Number(1.0)); return o;
}
JsonValue DescribeUi(){ namespace ui=maxmcp::payloadui; ui::VBoxWidget R; auto t=std::make_shared<ui::LabelWidget>(); t->Text="Cartridge Light"; R.Children.push_back(t); R.Children.push_back(std::make_shared<ui::SpacerWidget>()); auto l=std::make_shared<ui::LabelWidget>(); l->Text="A warm-white omni light."; R.Children.push_back(l); return ui::Build(R); }
JsonValue OnUiEvent(){ JsonValue o=JsonValue::Object(); o.Set("invalidate",JsonValue::Bool(true)); o.Set("rebuild",JsonValue::Bool(false)); o.Set("updates",JsonValue::Array()); return o; }
void PayloadDescribe(MaxMcpPayloadInfo* I){ if(!I) return; I->AbiVersion=MAXMCP_PAYLOAD_ABI; std::strncpy(I->Name,"slot_light",sizeof(I->Name)-1); std::strncpy(I->Version,CARTRIDGE_VERSION_STRING,sizeof(I->Version)-1); std::strncpy(I->Variant,"slot_light_native",sizeof(I->Variant)-1); }
void* CreateInstance(void){ return nullptr; } void DestroyInstance(void*){}
MaxMcpPayloadResult Call(void*, const char* F, const char* A, char* J, size_t C){
    if(!F) return MAXMCP_PAYLOAD_NO_FUNCTION; JsonValue Args; ParseJson(A?A:"{}",Args); JsonValue Res;
    if(!std::strcmp(F,"LightState")) Res=LightState();
    else if(!std::strcmp(F,"describe_ui")) Res=DescribeUi();
    else if(!std::strcmp(F,"on_ui_event")) Res=OnUiEvent();
    else return MAXMCP_PAYLOAD_NO_FUNCTION;
    JsonValue Rep=JsonValue::Object(); Rep.Set("ok",JsonValue::Bool(true)); Rep.Set("result",Res);
    return WriteReply(Rep,J,C)?MAXMCP_PAYLOAD_OK:MAXMCP_PAYLOAD_REPLY_TOO_LARGE;
}
MaxMcpPayloadResult CallBuffers(void*, const char*, const MaxMcpBuffer*, size_t, const char*, char*, size_t){ return MAXMCP_PAYLOAD_NO_FUNCTION; }
void SetLogSink(MaxMcpPayloadLogSink S, void* C){ GSink=S; GSinkContext=C; if(S){ const std::string L=std::string("Barebones Light (C++) native payload loaded: v")+CARTRIDGE_VERSION_STRING+" built "+CARTRIDGE_BUILD_STAMP+". This is the load report, not the greeting."; S(C,2,L.c_str()); } }
void SetFacade(const MaxMcpFacadeApi*){}
const MaxMcpPayloadApi GApi={ &PayloadDescribe,&CreateInstance,&DestroyInstance,&Call,&CallBuffers,&SetLogSink,&SetFacade,nullptr };
}
extern "C" __declspec(dllexport) const MaxMcpPayloadApi* MaxMcpGetPayload(uint32_t A){ return A==MAXMCP_PAYLOAD_ABI?&GApi:nullptr; }
