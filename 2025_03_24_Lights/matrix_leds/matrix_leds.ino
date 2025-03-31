#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1

#define CLK_PIN  5 // 13
#define CS_PIN   6 // 10
#define DATA_PIN 13 // 11

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, 
                           DATA_PIN, 
                           CLK_PIN, 
                           CS_PIN,
                           MAX_DEVICES);


void setup() {
  Serial.begin(57600);
  if (!mx.begin()) {
    Serial.print("\n Existe un error en la configuracion");
  }
}
uint8_t control = 0;
void loop() {
    square1();
    delay(200);
    square2();
    delay(200);
    square3();
    delay(200);
    square4();
    delay(200);
}                           

void square1() {
    mx.setRow(0, 0x00); // 
    mx.setRow(1, 0x00);
    mx.setRow(2, 0x00);
    mx.setRow(3, 0x18);
    mx.setRow(4, 0x18);
    mx.setRow(5, 0x00);
    mx.setRow(6, 0x00);
    mx.setRow(7, 0x00);
}

void square2() {
    mx.setRow(0, 0x00);
    mx.setRow(1, 0x00);
    mx.setRow(2, 0x3C);
    mx.setRow(3, 0x24);
    mx.setRow(4, 0x24);
    mx.setRow(5, 0x3C);
    mx.setRow(6, 0x00);
    mx.setRow(7, 0x00);
}

void square3() {
    mx.setRow(0, 0x00);
    mx.setRow(1, 0x7E);
    mx.setRow(2, 0x42);
    mx.setRow(3, 0x42);
    mx.setRow(4, 0x42);
    mx.setRow(5, 0x42);
    mx.setRow(6, 0x7E);
    mx.setRow(7, 0x00);
}

void square4() {
    mx.setRow(0, 0xFF);
    mx.setRow(1, 0x81);
    mx.setRow(2, 0x81);
    mx.setRow(3, 0x81);
    mx.setRow(4, 0x81);
    mx.setRow(5, 0x81);
    mx.setRow(6, 0x81);
    mx.setRow(7, 0xFF);
}
