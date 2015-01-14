#ifndef PGG_OBJ_H
#define PGG_OBJ_H

#include <node.h>
#include <nan.h>

using namespace v8;

class Pgg : node::ObjectWrap {

private:
  Pgg();
  ~Pgg();

  static NAN_METHOD(New);
  static NAN_METHOD(Version);
  static NAN_METHOD(EngineInfo);

public:
  static void Init(Handle<Object>);
  static Persistent<Function> constructor;
};
#endif

