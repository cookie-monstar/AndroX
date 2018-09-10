#ifndef HEADER_H
#define HEADER_H

//#include<node.h>
#include<unistd.h>
#include<fcntl.h>
#include<linux/input.h>

/*using v8::FunctionCallBackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;*/

//class Mouse {
//  int fd;
//public:
//  Mouse();
//  void press(int button, int is_press);
//  void moveBy(int x, int y);
//  void moveTo(int x, int y);
//}

class Keyboard {
  int fd;
public:
  Keyboard();
  ~Keyboard();
  void emit(int type, int code, int value);
};

#endif
