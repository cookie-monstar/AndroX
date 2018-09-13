#include "device.h"

Device::Device() {
  uinput_setup usetup;
  memset(&usetup, 0, sizeof(usetup));
  strcpy(usetup.name, "AndroX Device");
  usetup.id.bustype = BUS_USB;
  usetup.id.vendor = 0x1234;
  usetup.id.product = 0x5678;
  vector<int> keys = { };
  vector<int> rels = { };
  Device::start(usetup, keys, rels);
}

void Device::start(uinput_setup usetup, vector<int> keys, vector<int> rels) {
  this->fd = open("/dev/uinput", O_WRONLY|O_NONBLOCK);
  if(keys.begin() != keys.end()) {
    ioctl(this->fd, UI_SET_EVBIT, EV_KEY);
    for(vector<int>::iterator key = keys.begin(); key != keys.end(); ++key) {
      ioctl(this->fd, UI_SET_KEYBIT, *key);
    }
  }
  if(rels.begin() != rels.end()) {
    ioctl(this->fd, UI_SET_EVBIT, EV_REL);
    for(vector<int>::iterator rel = rels.begin(); rel != rels.end(); ++rel) {
      ioctl(this->fd, UI_SET_RELBIT, *rel);
    }
  }
  ioctl(this->fd, UI_DEV_SETUP, &usetup);
  ioctl(this->fd, UI_DEV_CREATE);
}

Device::~Device() {
  ioctl(this->fd, UI_DEV_DESTROY);
  close(fd);
}

void Device::emit(int type, int code, int val) {
  input_event ie;
  ie.type = type;
  ie.code = code;
  ie.value = val;
  ie.time.tv_sec = 0;
  ie.time.tv_usec = 0;
  write(this->fd, &ie, sizeof(ie));
}

Mouse::Mouse() {
 uinput_setup usetup;
 memset(&usetup, 0, sizeof(usetup));
 strcpy(usetup.name, "AndroX Mouse");
 usetup.id.bustype = BUS_USB;
 usetup.id.vendor = 0x1234;
 usetup.id.product = 0x5678;
 vector<int> keys = { BTN_LEFT, BTN_RIGHT, BTN_MIDDLE };
 vector<int> rels = { REL_X, REL_Y, REL_WHEEL, ABS_X, ABS_Y };
 Device::start(usetup, keys, rels);
}

Keyboard::Keyboard() {
  uinput_setup usetup;
  memset(&usetup, 0, sizeof(usetup));
  strcpy(usetup.name, "AndroX Keyboard");
  usetup.id.bustype = BUS_USB;
  usetup.id.vendor = 0x1234;
  usetup.id.product = 0x5678;
  vector<int> keys = { KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G };
  vector<int> rels = { };
  Device::start(usetup, keys, rels);
 }

Gamepad::Gamepad() {
 uinput_setup usetup;
 memset(&usetup, 0, sizeof(usetup));
 strcpy(usetup.name, "AndroX Gamepad");
 usetup.id.bustype = BUS_USB;
 usetup.id.vendor = 0x1234;
 usetup.id.product = 0x5678;
 vector<int> keys = {
                     BTN_A, BTN_B, BTN_X, BTN_Y,
                     BTN_DPAD_UP, BTN_DPAD_RIGHT, BTN_DPAD_DOWN, BTN_DPAD_LEFT,
                     BTN_TL, BTN_TR, BTN_TL2, BTN_TR2,
                     BTN_SELECT, BTN_START, BTN_MODE,
                     BTN_THUMBL, BTN_THUMBR
                    };
 vector<int> rels = { REL_X, REL_Y, REL_Z, REL_RZ, ABS_X, ABS_Y, ABS_Z, ABS_RZ };
 Device::start(usetup, keys, rels);
}
