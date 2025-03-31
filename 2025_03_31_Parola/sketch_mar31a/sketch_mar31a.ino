#include <MD_MAX72xx.h>
#include <MD_Parola.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1

#define CLK_PIN  5 // 13
#define CS_PIN   6 // 10
#define DATA_PIN 13 // 11

MD_Parola p = MD_Parola(HARDWARE_TYPE, 
                        DATA_PIN,
                        CLK_PIN,
                        CS_PIN, 
                        MAX_DEVICES);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
