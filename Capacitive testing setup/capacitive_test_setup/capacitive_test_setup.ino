#define NUM_PADS 12

#include <FastLED.h>
#define DATA_PIN 22
CRGB leds[NUM_PADS];

#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

#define AUTOCONFIG

Adafruit_MPR121 cap = Adafruit_MPR121();

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_PADS);

  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
  //cap.writeRegister(MPR121_AUTOCONFIG0, 0x3F);
}

void loop() {
 
    Serial.print("raw data: ");
    for (uint8_t i = 0; i < 12; i++) {
      int data = cap.filteredData(i);
      //data = max( map(data,0,cap.baselineData(i),255,0)-3,0);
      Serial.print(data); Serial.print("\t");
      leds[i] = CHSV(data+192, 255, data);
    }
    Serial.print(touchRead(0));
    Serial.println();

    
    FastLED.show();
    delay(10);
    
  }
