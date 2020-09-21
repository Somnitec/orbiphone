#define debugUpdateTime 10//in ms
#define calibrationUpdateTime 5//in ms
#define NUM_PADS 12

#include <FastLED.h>
#define DATA_PIN 22
CRGB leds[NUM_PADS];

#include <Wire.h>
#include "Adafruit_MPR121.h"

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
  //calibrationUpdate();

  debugUpdate();



}

elapsedMillis debugUpdateTimer;
void debugUpdate() {
  if (debugUpdateTimer > debugUpdateTime) {
    debugUpdateTimer = 0;
    
    long totalData = 0;
    int sensorAmount = 2;
    for (uint8_t i = 0; i <sensorAmount; i++) {
      int data = cap.filteredData(i);
      totalData += data;
      //data = max( map(data,0,cap.baselineData(i),255,0)-3,0);
      Serial.print("data");Serial.print(i);Serial.print(":");Serial.print(data); Serial.print("\t");
      leds[i] = CHSV(data + 192, 255, data);
    }
    Serial.print("sum:");
    Serial.print(totalData/sensorAmount);Serial.print('\t');
    Serial.print("difference:");
    Serial.print(cap.filteredData(0)-cap.filteredData(1));Serial.print('\t');
    //Serial.print(touchRead(0));
    Serial.println();
    FastLED.show();
  }
}
