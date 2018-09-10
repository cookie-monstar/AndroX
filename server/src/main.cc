#include"header.h"

int main() {
  Keyboard newOne;
  sleep(30);
  newOne.emit(EV_KEY, KEY_SPACE, 1);
  newOne.emit(EV_SYN, SYN_REPORT, 0);
  newOne.emit(EV_KEY, KEY_SPACE, 0);
  newOne.emit(EV_SYN, SYN_REPORT, 0);
  sleep(30);
  return 0;
}
