#include "EasyBuzzer.h"
unsigned int frequency = 1000;
unsigned int beeps = 1000;

void setup() {
  EasyBuzzer.setPin(3);
  EasyBuzzer.beep(frequency, beeps);
}

void loop() {
  EasyBuzzer.update();
}
