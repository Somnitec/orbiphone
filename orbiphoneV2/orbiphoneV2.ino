//SETTINGS
#define TONESAMOUNT 11 // amount of pads active
#define LEDBRIGHTNESS  255

//sound settings
#define oscMaxAmplitude 0.5//some lower value to avoid the oscilators to distort
#define glide 20    //glide time for frequency change (is affected by audioUpdateTime)

//calibration settings
#define defaultSensorMaxRange 200 //before touching, what is assumed is the touch range
#define autocalibTime 8000//ms of stableness before an autocalibration happens
#define lowerThreshold -.2//value to have a safe margin, should be a small negative float
#define standardDevRange 100// the max value of the rate of change measurement

#define topAdjust 0.5// a modifier to remove sensitivity on top of the range, to make it a bit less hard to trigger some pads fully

#define datapointsFast 10//how many measurements for the fast moving average
#define datapointsSlow 25//how many measurements for the slow moving average

#define buttonDebounceTime       5//ms

//scheduler settings
#define sensorReadFastUpdateTime 3//ms
#define sensorReadSlowUpdateTime 10//ms
#define knobsUpdateTime 30//ms
#define audioUpdateTime 30//ms
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
AudioSynthWaveformSine   subosc2;        //xy=57.5,1247.4444580078125
AudioSynthWaveformSine   subosc1;        //xy=58.5,1204.4444580078125
AudioSynthWaveformSine   subosc6;        //xy=58.5,1390.4444580078125
AudioSynthWaveformSine   subosc0;        //xy=59.5,1168.4444885253906
AudioSynthWaveformSine   subosc4;        //xy=59.5,1317.4444580078125
AudioSynthWaveformSine   subosc8;        //xy=59.5,1466.4444580078125
AudioSynthWaveformSine   subosc3;        //xy=60.5,1284.4444580078125
AudioSynthWaveformSine   subosc7;        //xy=61.5,1427.4444580078125
AudioSynthWaveformSine   subosc5;        //xy=62.5,1354.4444580078125
AudioSynthWaveformSine   subosc9;        //xy=62.5,1503.4444580078125
AudioSynthWaveformSine   subosc10;       //xy=62.5,1539.4444580078125
AudioSynthWaveformSine   subosc11;       //xy=65.5,1576.4444580078125
AudioSynthWaveformDc     envelope0;            //xy=214.99998474121094,74.00001001358032
AudioSynthWaveform       osc0;           //xy=215.55555725097656,38.4629921913147
AudioSynthWaveformDc     envelope1; //xy=222.3277587890625,160.42034912109375
AudioSynthWaveform       osc1; //xy=222.88333129882812,124.88333129882812
AudioSynthWaveformDc     envelope3; //xy=231.3277587890625,331.42034912109375
AudioSynthWaveform       osc3; //xy=231.88333129882812,295.8833312988281
AudioEffectMultiply      multiplysub3; //xy=230.88333129882812,1286.683349609375
AudioSynthWaveformDc     envelope2; //xy=236.3277587890625,245.42034912109375
AudioSynthWaveform       osc2; //xy=236.88333129882812,209.88333129882812
AudioEffectMultiply      multiplysub7; //xy=233.88333129882812,1444.683349609375
AudioSynthWaveformDc     envelope4; //xy=238.3277587890625,419.42034912109375
AudioSynthWaveform       osc4; //xy=238.88333129882812,383.8833312988281
AudioEffectMultiply      multiplysub4; //xy=236.88333129882812,1325.683349609375
AudioEffectMultiply      multiplysub6; //xy=238.88333129882812,1401.683349609375
AudioEffectMultiply      multiplysub8; //xy=238.88333129882812,1489.683349609375
AudioEffectMultiply      multiplysub2; //xy=239.88333129882812,1242.683349609375
AudioEffectMultiply      multiplysub5; //xy=239.88333129882812,1364.683349609375
AudioEffectMultiply      multiplysub9; //xy=239.88333129882812,1527.683349609375
AudioSynthWaveformDc     envelope8; //xy=243.3277587890625,764.4203186035156
AudioSynthWaveformDc     envelope9; //xy=243.3277587890625,841.4203186035156
AudioSynthWaveformDc     envelope6; //xy=244.3277587890625,593.4203186035156
AudioSynthWaveform       osc8; //xy=243.88333129882812,728.88330078125
AudioSynthWaveform       osc9; //xy=243.88333129882812,805.88330078125
AudioSynthWaveform       osc6; //xy=244.88333129882812,557.88330078125
AudioSynthWaveformDc     envelope10; //xy=244.3277587890625,917.7203674316406
AudioSynthWaveformDc     envelope5; //xy=246.3277587890625,513.4203491210938
AudioSynthWaveform       osc10; //xy=244.88333129882812,882.183349609375
AudioSynthWaveform       osc5; //xy=246.88333129882812,477.8833312988281
AudioSynthWaveformDc     envelope7; //xy=246.3277587890625,674.4203186035156
AudioSynthWaveform       osc7;  //xy=246.88333129882812,638.88330078125
AudioEffectMultiply      multiplysub1; //xy=244.88333129882812,1202.683349609375
AudioSynthWaveformDc     envelope11; //xy=247.3277587890625,1001.2203674316406
AudioSynthWaveform       osc11; //xy=247.88333129882812,965.683349609375
AudioEffectMultiply      multiply0sub; //xy=248.88333129882812,1164.683349609375
AudioEffectMultiply      multiplysub10; //xy=247.88333129882812,1571.683349609375
AudioEffectMultiply      multiplysub11; //xy=247.88333129882812,1606.683349609375
AudioEffectMultiply      multiply0;      //xy=367.12403869628906,49.90186548233032
AudioEffectMultiply      multiply1; //xy=374.4518127441406,136.32220458984375
AudioSynthWaveformDc     filterMod0; //xy=378.88331604003906,95.88334131240845
AudioEffectMultiply      multiply3; //xy=383.4518127441406,307.32220458984375
AudioSynthWaveformDc     filterMod1; //xy=386.2110900878906,182.30368041992188
AudioEffectMultiply      multiply2; //xy=388.4518127441406,221.32220458984375
AudioEffectMultiply      multiply4; //xy=390.4518127441406,395.32220458984375
AudioSynthWaveformDc     filterMod3; //xy=395.2110900878906,353.3036804199219
AudioEffectMultiply      multiply8; //xy=395.4518127441406,740.3221740722656
AudioEffectMultiply      multiply9; //xy=395.4518127441406,817.3221740722656
AudioEffectMultiply      multiply6; //xy=396.4518127441406,569.3221740722656
AudioEffectMultiply      multiply10; //xy=396.4518127441406,893.6222229003906
AudioEffectMultiply      multiply5; //xy=398.4518127441406,489.32220458984375
AudioEffectMultiply      multiply7; //xy=398.4518127441406,650.3221740722656
AudioSynthWaveformDc     filterMod2; //xy=400.2110900878906,267.3036804199219
AudioEffectMultiply      multiply11; //xy=399.4518127441406,977.1222229003906
AudioSynthWaveformDc     filterMod4; //xy=402.2110900878906,441.3036804199219
AudioSynthWaveformDc     filterMod8; //xy=407.2110900878906,786.3036499023438
AudioSynthWaveformDc     filterMod9; //xy=407.2110900878906,863.3036499023438
AudioSynthWaveformDc     filterMod6; //xy=408.2110900878906,615.3036499023438
AudioSynthWaveformDc     filterMod10; //xy=408.2110900878906,939.6036987304688
AudioSynthWaveformDc     filterMod5; //xy=410.2110900878906,535.3036804199219
AudioSynthWaveformDc     filterMod7; //xy=410.2110900878906,696.3036499023438
AudioSynthWaveformDc     filterMod11; //xy=411.2110900878906,1023.1036987304688
AudioMixer4              mixer3sub;      //xy=426.3148193359375,1432.4444580078125
AudioMixer4              mixer1sub;      //xy=427.3148193359375,1300.4444580078125
AudioMixer4              mixer2sub;      //xy=427.3148193359375,1365.4444580078125
AudioFilterStateVariable filter0;        //xy=541.5555419921875,99.46298217773438
AudioFilterStateVariable filter1; //xy=548.8833160400391,185.8833212852478
AudioFilterStateVariable filter3; //xy=557.8833160400391,356.8833212852478
AudioFilterStateVariable filter2; //xy=562.8833160400391,270.8833212852478
AudioFilterStateVariable filter4; //xy=564.8833160400391,444.8833212852478
AudioFilterStateVariable filter8; //xy=569.8833160400391,789.8832907676697
AudioFilterStateVariable filter9; //xy=569.8833160400391,866.8832907676697
AudioFilterStateVariable filter6; //xy=570.8833160400391,618.8832907676697
AudioFilterStateVariable filter10; //xy=570.8833160400391,943.1833395957947
AudioFilterStateVariable filter5; //xy=572.8833160400391,538.8833212852478
AudioFilterStateVariable filter7; //xy=572.8833160400391,699.8832907676697
AudioFilterStateVariable filter11; //xy=573.8833160400391,1026.6833395957947
AudioMixer4              mixer4sub;      //xy=592.3148193359375,1381.4444580078125
AudioAmplifier           amp1sub;        //xy=719.3148193359375,1381.4444580078125
AudioMixer4              mixer3;         //xy=726.5555572509766,383.46297216415405
AudioMixer4              mixer1;         //xy=727.5555572509766,251.46297216415405
AudioMixer4              mixer2;         //xy=727.5555572509766,316.46297216415405
AudioOutputPWM           pwm1;           //xy=847.3148193359375,1381.4444580078125
AudioMixer4              mixer4;         //xy=892.5555572509766,332.46297216415405
AudioAnalyzePeak         peak1;          //xy=984.5555572509766,207.46297216415405
AudioAmplifier           amp1;           //xy=1033.5555572509766,330.46297216415405
AudioAnalyzeRMS          rms1;           //xy=1072.5555572509766,250.46297216415405
AudioOutputAnalog        dac1;           //xy=1196.5555572509766,327.46297216415405
AudioConnection          patchCord1(subosc2, 0, multiplysub2, 0);
AudioConnection          patchCord2(subosc1, 0, multiplysub1, 0);
AudioConnection          patchCord3(subosc6, 0, multiplysub6, 0);
AudioConnection          patchCord4(subosc0, 0, multiply0sub, 0);
AudioConnection          patchCord5(subosc4, 0, multiplysub4, 0);
AudioConnection          patchCord6(subosc8, 0, multiplysub8, 0);
AudioConnection          patchCord7(subosc3, 0, multiplysub3, 0);
AudioConnection          patchCord8(subosc7, 0, multiplysub7, 0);
AudioConnection          patchCord9(subosc5, 0, multiplysub5, 0);
AudioConnection          patchCord10(subosc9, 0, multiplysub9, 0);
AudioConnection          patchCord11(subosc10, 0, multiplysub10, 0);
AudioConnection          patchCord12(subosc11, 0, multiplysub11, 0);
AudioConnection          patchCord13(envelope0, 0, multiply0, 1);
AudioConnection          patchCord14(envelope0, 0, multiply0sub, 1);
AudioConnection          patchCord15(osc0, 0, multiply0, 0);
AudioConnection          patchCord16(envelope1, 0, multiply1, 1);
AudioConnection          patchCord17(envelope1, 0, multiplysub1, 1);
AudioConnection          patchCord18(osc1, 0, multiply1, 0);
AudioConnection          patchCord19(envelope3, 0, multiply3, 1);
AudioConnection          patchCord20(envelope3, 0, multiplysub3, 1);
AudioConnection          patchCord21(osc3, 0, multiply3, 0);
AudioConnection          patchCord22(multiplysub3, 0, mixer1sub, 3);
AudioConnection          patchCord23(envelope2, 0, multiply2, 1);
AudioConnection          patchCord24(envelope2, 0, multiplysub2, 1);
AudioConnection          patchCord25(osc2, 0, multiply2, 0);
AudioConnection          patchCord26(multiplysub7, 0, mixer2sub, 3);
AudioConnection          patchCord27(envelope4, 0, multiply4, 1);
AudioConnection          patchCord28(envelope4, 0, multiplysub4, 1);
AudioConnection          patchCord29(osc4, 0, multiply4, 0);
AudioConnection          patchCord30(multiplysub4, 0, mixer2sub, 0);
AudioConnection          patchCord31(multiplysub6, 0, mixer2sub, 2);
AudioConnection          patchCord32(multiplysub8, 0, mixer3sub, 0);
AudioConnection          patchCord33(multiplysub2, 0, mixer1sub, 2);
AudioConnection          patchCord34(multiplysub5, 0, mixer2sub, 1);
AudioConnection          patchCord35(multiplysub9, 0, mixer3sub, 1);
AudioConnection          patchCord36(envelope8, 0, multiply8, 1);
AudioConnection          patchCord37(envelope8, 0, multiplysub8, 1);
AudioConnection          patchCord38(envelope9, 0, multiply9, 1);
AudioConnection          patchCord39(envelope9, 0, multiplysub9, 1);
AudioConnection          patchCord40(envelope6, 0, multiply6, 1);
AudioConnection          patchCord41(envelope6, 0, multiplysub6, 1);
AudioConnection          patchCord42(osc8, 0, multiply8, 0);
AudioConnection          patchCord43(osc9, 0, multiply9, 0);
AudioConnection          patchCord44(osc6, 0, multiply6, 0);
AudioConnection          patchCord45(envelope10, 0, multiply10, 1);
AudioConnection          patchCord46(envelope10, 0, multiplysub10, 1);
AudioConnection          patchCord47(envelope5, 0, multiply5, 1);
AudioConnection          patchCord48(envelope5, 0, multiplysub5, 1);
AudioConnection          patchCord49(osc10, 0, multiply10, 0);
AudioConnection          patchCord50(osc5, 0, multiply5, 0);
AudioConnection          patchCord51(envelope7, 0, multiply7, 1);
AudioConnection          patchCord52(envelope7, 0, multiplysub7, 1);
AudioConnection          patchCord53(osc7, 0, multiply7, 0);
AudioConnection          patchCord54(multiplysub1, 0, mixer1sub, 1);
AudioConnection          patchCord55(envelope11, 0, multiply11, 1);
AudioConnection          patchCord56(envelope11, 0, multiplysub11, 1);
AudioConnection          patchCord57(osc11, 0, multiply11, 0);
AudioConnection          patchCord58(multiply0sub, 0, mixer1sub, 0);
AudioConnection          patchCord59(multiplysub10, 0, mixer3sub, 2);
AudioConnection          patchCord60(multiplysub11, 0, mixer3sub, 3);
AudioConnection          patchCord61(multiply0, 0, filter0, 0);
AudioConnection          patchCord62(multiply1, 0, filter1, 0);
AudioConnection          patchCord63(filterMod0, 0, filter0, 1);
AudioConnection          patchCord64(multiply3, 0, filter3, 0);
AudioConnection          patchCord65(filterMod1, 0, filter1, 1);
AudioConnection          patchCord66(multiply2, 0, filter2, 0);
AudioConnection          patchCord67(multiply4, 0, filter4, 0);
AudioConnection          patchCord68(filterMod3, 0, filter3, 1);
AudioConnection          patchCord69(multiply8, 0, filter8, 0);
AudioConnection          patchCord70(multiply9, 0, filter9, 0);
AudioConnection          patchCord71(multiply6, 0, filter6, 0);
AudioConnection          patchCord72(multiply10, 0, filter10, 0);
AudioConnection          patchCord73(multiply5, 0, filter5, 0);
AudioConnection          patchCord74(multiply7, 0, filter7, 0);
AudioConnection          patchCord75(filterMod2, 0, filter2, 1);
AudioConnection          patchCord76(multiply11, 0, filter11, 0);
AudioConnection          patchCord77(filterMod4, 0, filter4, 1);
AudioConnection          patchCord78(filterMod8, 0, filter8, 1);
AudioConnection          patchCord79(filterMod9, 0, filter9, 1);
AudioConnection          patchCord80(filterMod6, 0, filter6, 1);
AudioConnection          patchCord81(filterMod10, 0, filter10, 1);
AudioConnection          patchCord82(filterMod5, 0, filter5, 1);
AudioConnection          patchCord83(filterMod7, 0, filter7, 1);
AudioConnection          patchCord84(filterMod11, 0, filter11, 1);
AudioConnection          patchCord85(mixer3sub, 0, mixer4sub, 2);
AudioConnection          patchCord86(mixer1sub, 0, mixer4sub, 0);
AudioConnection          patchCord87(mixer2sub, 0, mixer4sub, 1);
AudioConnection          patchCord88(filter0, 0, mixer1, 0);
AudioConnection          patchCord89(filter1, 0, mixer1, 1);
AudioConnection          patchCord90(filter3, 0, mixer1, 3);
AudioConnection          patchCord91(filter2, 0, mixer1, 2);
AudioConnection          patchCord92(filter4, 0, mixer2, 0);
AudioConnection          patchCord93(filter8, 0, mixer3, 0);
AudioConnection          patchCord94(filter9, 0, mixer3, 1);
AudioConnection          patchCord95(filter6, 0, mixer2, 2);
AudioConnection          patchCord96(filter10, 0, mixer3, 2);
AudioConnection          patchCord97(filter5, 0, mixer2, 1);
AudioConnection          patchCord98(filter7, 0, mixer2, 3);
AudioConnection          patchCord99(filter11, 0, mixer3, 3);
AudioConnection          patchCord100(mixer4sub, amp1sub);
AudioConnection          patchCord101(amp1sub, pwm1);
AudioConnection          patchCord102(mixer3, 0, mixer4, 2);
AudioConnection          patchCord103(mixer1, 0, mixer4, 0);
AudioConnection          patchCord104(mixer2, 0, mixer4, 1);
AudioConnection          patchCord105(mixer4, peak1);
AudioConnection          patchCord106(mixer4, rms1);
AudioConnection          patchCord107(mixer4, amp1);
AudioConnection          patchCord108(amp1, dac1);
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

#define ampPin 21

const int encPins[] = {12, 11, 24};
const int volumePin = 34;
Bounce encButton = Bounce();
Encoder encoder(encPins[0], encPins[1]);

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
int encoderState = 0;
bool freqStable = false;

void setup() {
  setLeds();
  pinMode(ampPin, OUTPUT);
  digitalWrite(ampPin, LOW); // turn on the amplifier before anything else
  
  Serial.begin(115200);
  setKnobs();
  
  startAudio();

  baseLineCalibration();
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

  if (firstTime && millis() > 500) {
    baseLineCalibration();
    firstTime = false;
    fadeOut();
  }
}



float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  float value =  (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return constrain(value, out_min, out_max);
}
