#include "pgg_obj.h"
#include "pgg_gpg.h"

Pgg::Pgg(){
  //FIXME: get protocol from constructor
  gpgme_protocol_t protocol = GPGME_PROTOCOL_OpenPGP;
  PggGpg::Init(protocol);
}
Pgg::~Pgg(){}

Persistent<Function> Pgg::constructor;

NAN_METHOD(Pgg::New) {
  NanScope();
  if (args.IsConstructCall()) {
    Pgg *obj = new Pgg();
    obj->Wrap(args.This());
    NanReturnValue(args.This());
  }
  NanReturnValue(NanNew(constructor)->NewInstance());
}

NAN_METHOD(Pgg::Version) {
  NanScope();
  NanReturnValue(NanNew<String>(PggGpg::Version()));
}

NAN_METHOD(Pgg::EngineInfo) {
  NanScope();
  gpgme_engine_info_t info;
  PggGpg::EngineInfo(info);
  size_t i = 0;
  Local<Array> engineInfoList = NanNew<Array>();
  for (; info; info = info->next) {
    Local<Object> engineInfo = NanNew<Object>(); 
    engineInfo->Set(NanNew("protocol"), NanNew<Integer>(info->protocol));
    engineInfo->Set(NanNew("fileName"), NanNew<String>(info->file_name));
    engineInfo->Set(NanNew("version"), NanNew<String>(info->version));
    engineInfo->Set(NanNew("reqVersion"), NanNew<String>(info->req_version));
    engineInfo->Set(NanNew("homeDir"), NanNew<String>(info->home_dir ? info->home_dir : "[default]"));
    engineInfoList->Set(i++, engineInfo);
  }
  NanReturnValue(engineInfoList);
}

void Pgg::Init(Handle<Object> exports) {
  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);
  tpl->SetClassName(NanNew("Pgg"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  
  // set methods
  Local<ObjectTemplate> proto = tpl->PrototypeTemplate();
  proto->Set(NanNew("version"), NanNew<FunctionTemplate>(Version)->GetFunction());
  proto->Set(NanNew("engineInfo"), NanNew<FunctionTemplate>(EngineInfo)->GetFunction());

  NanAssignPersistent<Function>(constructor, tpl->GetFunction());
  exports->Set(NanNew("Pgg"), tpl->GetFunction());
}
