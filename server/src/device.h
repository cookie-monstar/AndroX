#ifndef DEVICE_H
#define DEVICE_H
#include <vector>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <linux/uinput.h>

using std::vector;

class Device {
  int fd;
  protected:
    void start(uinput_setup usetup, vector<int> keys, vector<int> rels);
  public:
     Device();
    ~Device();
    void emit(int type, int code, int val);
};

class Mouse: public Device {
 public:
   Mouse();
};

class Keyboard: public Device {
  public:
    Keyboard();
};

class Gamepad: public Device {
 public:
   Gamepad();
};

#endif