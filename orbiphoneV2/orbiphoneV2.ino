//SETTINGS
#define TONESAMOUNT 11 // amount of pads active

#define defaultSensorMaxRange 100 //before touching, what is assumed is the touch range
#define autocalibTime 8000//ms of stableness before an autocalibration happens
#define lowerThreshold -.05//value to have a safe margin, should be a small negative float

#define datapointsFast 20//how many measurements for the fast moving average
#define datapointsSlow 50//how many measurements for the slow moving average

#define sensorReadFastUpdateTime 3//ms
#define sensorReadSlowUpdateTime 30//ms
#define knobsUpdateTime 30//ms
#define audioUpdateTime 3//ms
#define serialPrintUpdateTime 20//ms
#define midiUpdateTime 10//ms
#define ledUpdateTime 1000/100 //Hz

#define LEDBRIGHTNESS  255
////
#include <FastLED.h>
#include <Bounce2.h>
#include <Metro.h>
#include "RunningAverage.h"
#include <Encoder.h>

int sensor[12] = {0, 1, 25, 17, 16, 15, 32, 18, 33, 19, 22, 23};
float ampl[12];


#define LEDPIN0          2
#define LEDPIN1          5
#define LEDPIN2          6
#define LEDPIN3          7
#define LEDPIN4          8
#define LEDPIN5          9
#define LEDPIN6          14
#define LEDPIN7          28
#define LEDPIN8          27
#define LEDPIN9          26
#define LEDPIN10         31
#define LEDPIN11         20


#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[TONESAMOUNT];

Metro sensorReadFast = Metro(sensorReadFastUpdateTime);
Metro sensorReadSlow = Metro(sensorReadSlowUpdateTime);
Metro knobsLoop = Metro(knobsUpdateTime);
Metro audioLoop = Metro(audioUpdateTime);
Metro serialPrintLoop = Metro(serialPrintUpdateTime);
Metro midiLoop = Metro(midiUpdateTime);
Metro ledLoop = Metro(ledUpdateTime);

RunningAverage bufferFast0(datapointsFast);
RunningAverage bufferSlow0(datapointsSlow);
RunningAverage bufferFast1(datapointsFast);
RunningAverage bufferSlow1(datapointsSlow);
RunningAverage bufferFast2(datapointsFast);
RunningAverage bufferSlow2(datapointsSlow);
RunningAverage bufferFast3(datapointsFast);
RunningAverage bufferSlow3(datapointsSlow);
RunningAverage bufferFast4(datapointsFast);
RunningAverage bufferSlow4(datapointsSlow);
RunningAverage bufferFast5(datapointsFast);
RunningAverage bufferSlow5(datapointsSlow);
RunningAverage bufferFast6(datapointsFast);
RunningAverage bufferSlow6(datapointsSlow);
RunningAverage bufferFast7(datapointsFast);
RunningAverage bufferSlow7(datapointsSlow);
RunningAverage bufferFast8(datapointsFast);
RunningAverage bufferSlow8(datapointsSlow);
RunningAverage bufferFast9(datapointsFast);
RunningAverage bufferSlow9(datapointsSlow);
RunningAverage bufferFast10(datapointsFast);
RunningAverage bufferSlow10(datapointsSlow);
RunningAverage bufferFast11(datapointsFast);
RunningAverage bufferSlow11(datapointsSlow);

int encClicks = 0;

void setup() {
  initializingStuff();
}

void loop() {
  if (sensorReadFast.check() == 1) {
    doSensorReadFast();
  }
  if (sensorReadSlow.check() == 1) {
    doSensorReadSlow(0);
  }
  if (knobsLoop.check() == 1) {
    //buttonUpdate();
  }
  if (audioLoop.check() == 1) {
    //audioUpdate();
  }
  if (serialPrintLoop.check() == 1) {
    debugUpdate();
  }
  if (midiLoop.check() == 1) {
    //midiUpdate();
  }
  if (ledLoop.check() == 1) {
    ledUpdate();
  }
}
