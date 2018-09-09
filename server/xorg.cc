#include<node.h>
#include<X11/Xlib.h>
#include<X11/X.h>
#include <X11/extensions/XTest.h>

Display *display;

void mousedown(const v8::FunctionCallbackInfo<v8::Value>& args) {
  XTestFakeButtonEvent(display, 1, true, 0);
  XFlush(display);
};

void mouseup(const v8::FunctionCallbackInfo<v8::Value>& args) {
  XTestFakeButtonEvent(display, 1, false, 0);
  XFlush(display);
};

void mouseclick(const v8::FunctionCallbackInfo<v8::Value>& args) {
  XTestFakeButtonEvent(display, 1, true, 0);
  XTestFakeButtonEvent(display, 1, false, 10);
  XFlush(display);
};

void mousemove(const v8::FunctionCallbackInfo<v8::Value>& args) {
  int x = (int)(args[0]->Int32Value());
  int y = (int)(args[1]->Int32Value());
  XWarpPointer(display, None, None, 0, 0, 0, 0, x, y);
  XFlush(display);
};

void Initialize(v8::Local<v8::Object> exports) {
  display = XOpenDisplay(0);
  NODE_SET_METHOD(exports, "mousedown", mousedown);
  NODE_SET_METHOD(exports, "mouseup", mouseup);
  NODE_SET_METHOD(exports, "mouseclick", mouseclick);
  NODE_SET_METHOD(exports, "mousemove", mousemove);
};

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);
