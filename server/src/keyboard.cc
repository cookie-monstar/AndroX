#include"header.h"

Keyboard::Keyboard() {
  struct uinput_setup usetup;
  this->fd = open("/dev/uinput", O_WRONGLY|O_NONBLOCK);
  ioctl(this->fd, UI_SET_EVBIT, EV_KEY);
  ioctl(this->fd, UI_DEV_KEYBIT, KEY_SPACE);
  mem(usetup, 0, sizeof(usetup));
  usetup.id.bustype = BUS_USB;
  usetup.id.vendor = 0x1234;
  usetup.id.product = 0x5678;
  strcpy(usetup.name, "AndroX");
}

Keyboard::~Keyboard() {
  ioctl(this->fd, UI_DEV_DESTROY);
  close(this->fd);
}

Keyboard::emit(int type, int code, int val) {
  struct input_event ie;
  ie.type = type;
  ie.code = code;
  ie.value = val;
  ie.time.tv_sec = 0;
  ie.time.tv_usec = 0;
  write(this->fd, ie, sizeof(ie));
}
