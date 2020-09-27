//SETTINGS
#define TONESAMOUNT 11 // amount of pads active
#define LEDBRIGHTNESS  255

//sound settings
#define oscMaxAmplitude 0.5//some lower value to avoid the oscilators to distort
#define glide 20    //glide time for frequency change (is affected by audioUpdateTime)

//calibration settings
#define defaultSensorMaxRange 200 //before touching, what is assumed is the touch range
#define autocalibTime 8000//ms of stableness before an autocalibration happens
#define lowerThreshold -.1//value to have a safe margin, should be a small negative float
#define standardDevRange 100// the max value of the rate of change measurement

#define datapointsFast 10//how many measurements for the fast moving average
#define datapointsSlow 25//how many measurements for the slow moving average

#define buttonDebounceTime       5//ms

//scheduler settings
#define sensorReadFastUpdateTime 3//ms
#define sensorReadSlowUpdateTime 10//ms
#define knobsUpdateTime 30//ms
#define audioUpdateTime 10//ms
#define serialPrintUpdateTime 20//ms
#define midiUpdateTime 10//ms
#define ledUpdateTime 1000/100 //Hz

////

//went into touch.c and changed the following values:
//#define CURRENT   15 //(default 2) 0 to 15 - current to use, value is 2*(current+1)
//#define NSCAN     15//(default 9) number of times to scan, 0 to 31, value is nscan+1
//#define PRESCALE  5 //(default 2) prescaler, 0 to 7 - value is 2^(prescaler+1)

#include <FastLED.h>
#include <Bounce2.h>
#include <Metro.h>
#include "RunningAverage.h"
#include <Encoder.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       osc0;           //xy=63.383331298828125,27.5
AudioSynthWaveform       osc1;           //xy=63.383331298828125,64.5
AudioSynthWaveform       osc2;           //xy=63.383331298828125,103.5
AudioSynthWaveform       osc3;           //xy=63.383331298828125,142.5
AudioSynthWaveform       osc4;           //xy=63.383331298828125,178.5
AudioSynthWaveform       osc5;           //xy=63.383331298828125,219.5
AudioSynthWaveform       osc6;           //xy=63.383331298828125,258.5
AudioSynthWaveform       osc7;           //xy=63.383331298828125,296.5
AudioSynthWaveform       osc8;           //xy=63.383331298828125,333.5
AudioSynthWaveform       osc9;           //xy=63.383331298828125,370.5
AudioSynthWaveform       osc10;          //xy=63.383331298828125,408.5
AudioSynthWaveformSine   subosc0;        //xy=63.383331298828125,541.5
AudioSynthWaveform       osc11;          //xy=64.38333129882812,445.5
AudioSynthWaveformSine   subosc2;        //xy=65.38333129882812,621.5
AudioSynthWaveformSine   subosc1;        //xy=66.38333129882812,578.5
AudioSynthWaveformSine   subosc6;        //xy=66.38333129882812,764.5
AudioSynthWaveformSine   subosc4;        //xy=67.38333129882812,691.5
AudioSynthWaveformSine   subosc8;        //xy=67.38333129882812,840.5
AudioSynthWaveformSine   subosc3;        //xy=68.38333129882812,658.5
AudioSynthWaveformSine   subosc7;        //xy=69.38333129882812,801.5
AudioSynthWaveformSine   subosc5;        //xy=70.38333129882812,728.5
AudioSynthWaveformSine   subosc9;        //xy=70.38333129882812,877.5
AudioSynthWaveformSine   subosc10;       //xy=70.38333129882812,913.5
AudioSynthWaveformSine   subosc11;       //xy=73.38333129882812,950.5
AudioFilterStateVariable        filter1; //xy=244.31483459472656,70.98148345947266
AudioFilterStateVariable        filter3; //xy=245.4259796142578,156.53705215454102
AudioFilterStateVariable        filter0;        //xy=247.64813232421875,25.425922393798828
AudioFilterStateVariable        filter2; //xy=248.75927734375,110.98149108886719
AudioFilterStateVariable        filter5; //xy=250.98153686523438,244.31483840942383
AudioFilterStateVariable        filter7;  //xy=250.98153686523438,335.42595291137695
AudioFilterStateVariable        filter4; //xy=254.31483459472656,198.75927734375
AudioFilterStateVariable        filter6; //xy=254.31483459472656,289.8703918457031
AudioFilterStateVariable        filter9; //xy=260.9815216064453,422.0926094055176
AudioMixer4              mixer3sub;         //xy=261.3833312988281,790.5
AudioMixer4              mixer1sub;         //xy=262.3833312988281,658.5
AudioFilterStateVariable        filter11; //xy=263.20375061035156,505.42595291137695
AudioMixer4              mixer2sub;         //xy=262.3833312988281,723.5
AudioFilterStateVariable        filter8; //xy=264.3148193359375,376.53704833984375
AudioFilterStateVariable        filter10; //xy=266.53704833984375,459.8703918457031
AudioMixer4              mixer4sub;         //xy=427.3833312988281,739.5
AudioMixer4              mixer3;         //xy=432.2722396850586,279.50000762939453
AudioMixer4              mixer1;         //xy=433.2722396850586,147.50000762939453
AudioMixer4              mixer2;         //xy=433.2722396850586,212.50000762939453
AudioAmplifier           amp1sub;           //xy=554.3833312988281,739.5
AudioMixer4              mixer4;         //xy=598.2722396850586,228.50000762939453
AudioOutputPWM           pwm1;           //xy=682.3833312988281,739.5
AudioAnalyzePeak         peak1;          //xy=690.2722396850586,103.50000762939453
AudioAmplifier           amp1;           //xy=739.2722396850586,226.50000762939453
AudioAnalyzeRMS          rms1;           //xy=778.2722396850586,146.50000762939453
AudioOutputAnalog        dac1;           //xy=902.2722396850586,223.50000762939453
AudioConnection          patchCord1(osc0, filter0);
AudioConnection          patchCord2(osc1, filter1);
AudioConnection          patchCord3(osc2, filter2);
AudioConnection          patchCord4(osc3, filter3);
AudioConnection          patchCord5(osc4, filter4);
AudioConnection          patchCord6(osc5, filter5);
AudioConnection          patchCord7(osc6, filter6);
AudioConnection          patchCord8(osc7, filter7);
AudioConnection          patchCord9(osc8, filter8);
AudioConnection          patchCord10(osc9, filter9);
AudioConnection          patchCord11(osc10, filter10);
AudioConnection          patchCord12(subosc0, 0, mixer1sub, 0);
AudioConnection          patchCord13(osc11, filter11);
AudioConnection          patchCord14(subosc2, 0, mixer1sub, 2);
AudioConnection          patchCord15(subosc1, 0, mixer1sub, 1);
AudioConnection          patchCord16(subosc6, 0, mixer2sub, 2);
AudioConnection          patchCord17(subosc4, 0, mixer2sub, 0);
AudioConnection          patchCord18(subosc8, 0, mixer3sub, 0);
AudioConnection          patchCord19(subosc3, 0, mixer1sub, 3);
AudioConnection          patchCord20(subosc7, 0, mixer2sub, 3);
AudioConnection          patchCord21(subosc5, 0, mixer2sub, 1);
AudioConnection          patchCord22(subosc9, 0, mixer3sub, 1);
AudioConnection          patchCord23(subosc10, 0, mixer3sub, 2);
AudioConnection          patchCord24(subosc11, 0, mixer3sub, 3);
AudioConnection          patchCord25(filter1, 0, mixer1, 1);
AudioConnection          patchCord26(filter3, 0, mixer1, 3);
AudioConnection          patchCord27(filter0, 0, mixer1, 0);
AudioConnection          patchCord28(filter2, 0, mixer1, 2);
AudioConnection          patchCord29(filter5, 0, mixer2, 1);
AudioConnection          patchCord30(filter7, 0, mixer2, 3);
AudioConnection          patchCord31(filter4, 0, mixer2, 0);
AudioConnection          patchCord32(filter6, 0, mixer2, 2);
AudioConnection          patchCord33(filter9, 0, mixer3, 1);
AudioConnection          patchCord34(mixer3sub, 0, mixer4sub, 2);
AudioConnection          patchCord35(mixer1sub, 0, mixer4sub, 0);
AudioConnection          patchCord36(filter11, 0, mixer3, 3);
AudioConnection          patchCord37(mixer2sub, 0, mixer4sub, 1);
AudioConnection          patchCord38(filter8, 0, mixer3, 0);
AudioConnection          patchCord39(filter10, 0, mixer3, 2);
AudioConnection          patchCord40(mixer4sub, amp1sub);
AudioConnection          patchCord41(mixer3, 0, mixer4, 2);
AudioConnection          patchCord42(mixer1, 0, mixer4, 0);
AudioConnection          patchCord43(mixer2, 0, mixer4, 1);
AudioConnection          patchCord44(amp1sub, pwm1);
AudioConnection          patchCord45(mixer4, peak1);
AudioConnection          patchCord46(mixer4, rms1);
AudioConnection          patchCord47(mixer4, amp1);
AudioConnection          patchCord48(amp1, dac1);
// GUItool: end automatically generated code

int sensor[12] = {0, 1, 25, 17, 16, 15, 32, 18, 33, 19, 22, 23};
float ampl[12];
float amplChange[12];
float freq[12];

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

const int encPins[] = {12, 11, 24};
const int volumePin = 34;
Bounce encButton = Bounce();
Encoder encoder(encPins[1], encPins[0]);

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
int encoderState=0;
bool freqStable = false;

void setup() {
  initializingStuff();
}

bool firstTime = true;
void loop() {
  if (sensorReadFast.check() == 1) {
    doSensorReadFast();
  }
  if (sensorReadSlow.check() == 1) {
    doSensorReadSlow(0);
  }
  if (knobsLoop.check() == 1) {
    knobUpdate();
  }
  if (audioLoop.check() == 1) {
    audioUpdate();
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

  if (firstTime && millis() > 1000) {
    baseLineCalibration();
    firstTime = false;
  }
}
