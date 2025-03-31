#include <MD_MAX72xx.h>
#include <MD_Parola.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN  5 // 13
#define CS_PIN   6 // 10
#define DATA_PIN 13 // 11

MD_Parola p = MD_Parola(HARDWARE_TYPE, 
                        DATA_PIN,
                        CLK_PIN,
                        CS_PIN, 
                        MAX_DEVICES);

void setup() {
  p.begin();
}
void loop() {
  uint8_t scrollSpeed = 100;    // default frame delay value
  textEffect_t scrollEffect = PA_SCROLL_LEFT;
  textPosition_t scrollAlign = PA_LEFT;
  uint16_t scrollPause = 2000; // in milliseconds
  
  if (p.displayAnimate())
     p.displayText("Programar es chido!", 
                    scrollAlign, 
                    scrollSpeed, 
                    scrollPause, 
                    scrollEffect, 
                    scrollEffect);
}
