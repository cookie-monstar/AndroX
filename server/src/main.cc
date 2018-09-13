#include<node.h>
#include "device.h"

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

Mouse mouse;

void emit(const FunctionCallbackInfo<Value>& args) {
    mouse.emit((int)(args[0]->Int32Value()), (int)(args[1]->Int32Value()), (int)(args[2]->Int32Value()));
    mouse.emit(EV_SYN, SYN_REPORT, 0);
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "emit", emit);
  NODE_DEFINE_CONSTANT(exports, EV_KEY);
  NODE_DEFINE_CONSTANT(exports, EV_REL);
  NODE_DEFINE_CONSTANT(exports, BTN_LEFT);
  NODE_DEFINE_CONSTANT(exports, BTN_RIGHT);
  NODE_DEFINE_CONSTANT(exports, BTN_MIDDLE);
  NODE_DEFINE_CONSTANT(exports, REL_X);
  NODE_DEFINE_CONSTANT(exports, REL_Y);
  NODE_DEFINE_CONSTANT(exports, REL_WHEEL);
  NODE_DEFINE_CONSTANT(exports, ABS_X);
  NODE_DEFINE_CONSTANT(exports, ABS_Y);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);
