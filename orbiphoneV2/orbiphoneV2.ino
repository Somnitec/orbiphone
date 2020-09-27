//SETTINGS
#define defaultSensorMaxRange 100 //before touching, what is assumed is the touch range
#define autocalibTime 8000//ms of stableness before an autocalibration happens

#define datapointsFast 20//how many measurements for the fast moving average
#define datapointsSlow 50//how many measurements for the slow moving average

#define sensorReadFastUpdateTime 3//ms
#define sensorReadSlowUpdateTime 30//ms
#define knobsUpdateTime 30//ms
#define audioUpdateTime 3//ms
#define serialPrintUpdateTime 50//ms
#define midiUpdateTime 10//ms
#define ledUpdateTime 1000/100 //Hz
////
#include <Metro.h>
#include "RunningAverage.h"

int sensor[12] = {0, 1, 25, 17, 16, 15, 32, 18, 33, 19, 22, 23};
float ampl[12];

Metro sensorReadFast = Metro(sensorReadFastUpdateTime);
Metro sensorReadSlow = Metro(sensorReadSlowUpdateTime);
Metro knobsLoop = Metro(knobsUpdateTime);
Metro audioLoop = Metro(audioUpdateTime);
Metro serialPrintLoop = Metro(serialPrintUpdateTime);
Metro midiLoop = Metro(midiUpdateTime);
Metro ledLoop = Metro(ledUpdateTime);

RunningAverage bufferFast0(datapointsFast);
RunningAverage bufferSlow0(datapointsFast);
RunningAverage bufferFast1(datapointsFast);
RunningAverage bufferSlow1(datapointsFast);
RunningAverage bufferFast2(datapointsFast);
RunningAverage bufferSlow2(datapointsFast);
RunningAverage bufferFast3(datapointsFast);
RunningAverage bufferSlow3(datapointsFast);
RunningAverage bufferFast4(datapointsFast);
RunningAverage bufferSlow4(datapointsFast);
RunningAverage bufferFast5(datapointsFast);
RunningAverage bufferSlow5(datapointsFast);
RunningAverage bufferFast6(datapointsFast);
RunningAverage bufferSlow6(datapointsFast);
RunningAverage bufferFast7(datapointsFast);
RunningAverage bufferSlow7(datapointsFast);
RunningAverage bufferFast8(datapointsFast);
RunningAverage bufferSlow8(datapointsFast);
RunningAverage bufferFast9(datapointsFast);
RunningAverage bufferSlow9(datapointsFast);
RunningAverage bufferFast10(datapointsFast);
RunningAverage bufferSlow10(datapointsFast);
RunningAverage bufferFast11(datapointsFast);
RunningAverage bufferSlow11(datapointsFast);

int encClicks = 0;

void setup() {
  initializingStuff();
}

void loop() {
  if (sensorReadFast.check() == 1) {
    doSensorReadFast();
  }
  if (sensorReadSlow.check() == 1) {
    doSensorReadSlow();
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
    //ledUpdate();
  }
}
