#include"header.h"

Mouse::Mouse() {
  struct uinput_setup usetup;
  this->fd = open("/dev/uinput", O_WRONGLY|O_NONBLOCK);
  ioctl(this->fd, UI_SET_EVBIT, EV_KEY);
  ioctl(this->fd, UI_DEV_KEYBIT, KEY_SPACE);
}

Mouse::~Mouse() {

}
