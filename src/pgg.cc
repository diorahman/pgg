#include <node.h>
#include "./pgg_obj.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
  Pgg::Init(exports);  
}

NODE_MODULE(pgg, InitAll);
