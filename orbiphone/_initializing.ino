#include <Audio.h>
#include <FastLED.h>
#include <Bounce2.h>

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

#define BRIGHTNESS  255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[TONESAMOUNT];

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       osc0;           //xy=76.88333129882812,62.883331298828125
AudioSynthWaveform       osc1;           //xy=76.88333129882812,99.88333129882812
AudioSynthWaveform       osc2;           //xy=76.88333129882812,138.88333129882812
AudioSynthWaveform       osc3;           //xy=76.88333129882812,177.88333129882812
AudioSynthWaveform       osc4;           //xy=76.88333129882812,213.88333129882812
AudioSynthWaveform       osc5;           //xy=76.88333129882812,254.88333129882812
AudioSynthWaveform       osc6;           //xy=76.88333129882812,293.8833312988281
AudioSynthWaveform       osc7;           //xy=76.88333129882812,331.8833312988281
AudioSynthWaveform       osc8;           //xy=76.88333129882812,368.8833312988281
AudioSynthWaveform       osc9;           //xy=76.88333129882812,405.8833312988281
AudioSynthWaveform       osc10;          //xy=76.88333129882812,443.8833312988281
AudioSynthWaveform       osc11; //xy=77.88333129882812,480.8833312988281
AudioSynthWaveformSine   subosc0;          //xy=76.88333129882812,576.88330078125
AudioSynthWaveformSine   subosc2; //xy=78.88333129882812,656.183349609375
AudioSynthWaveformSine   subosc1; //xy=79.88333129882812,613.88330078125
AudioSynthWaveformSine   subosc6; //xy=79.88333129882812,799.183349609375
AudioSynthWaveformSine   subosc4; //xy=80.88333129882812,726.183349609375
AudioSynthWaveformSine   subosc8; //xy=80.88333129882812,875.183349609375
AudioSynthWaveformSine   subosc3; //xy=81.88333129882812,693.183349609375
AudioSynthWaveformSine   subosc7; //xy=82.88333129882812,836.183349609375
AudioSynthWaveformSine   subosc5; //xy=83.88333129882812,763.183349609375
AudioSynthWaveformSine   subosc9; //xy=83.88333129882812,912.183349609375
AudioSynthWaveformSine   subosc10; //xy=83.88333129882812,948.183349609375
AudioSynthWaveformSine   subosc11; //xy=86.88333129882812,985.183349609375
AudioMixer4              mixer3;         //xy=246.88333129882812,324.8833312988281
AudioMixer4              mixer1;         //xy=247.88333129882812,192.88333129882812
AudioMixer4              mixer2;         //xy=247.88333129882812,257.8833312988281
AudioMixer4              mixer5; //xy=274.8833312988281,825.88330078125
AudioMixer4              mixer6; //xy=275.8833312988281,693.88330078125
AudioMixer4              mixer7; //xy=275.8833312988281,758.88330078125
AudioMixer4              mixer4;         //xy=412.8833312988281,273.8833312988281
AudioMixer4              mixer8; //xy=440.8833312988281,774.88330078125
AudioAnalyzePeak         peak1;          //xy=504.8833312988281,148.88333892822266
AudioAmplifier           amp1;           //xy=553.88330078125,271.8833312988281
AudioAmplifier           amp2; //xy=567.88330078125,774.0833129882812
AudioAnalyzeRMS          rms1;           //xy=592.88330078125,191.88333129882812
AudioOutputPWM           pwm1;           //xy=695.88330078125,774.88330078125
AudioOutputAnalog        dac1;           //xy=716.88330078125,268.8833312988281
AudioConnection          patchCord1(osc0, 0, mixer1, 0);
AudioConnection          patchCord2(osc1, 0, mixer1, 1);
AudioConnection          patchCord3(osc2, 0, mixer1, 2);
AudioConnection          patchCord4(osc3, 0, mixer1, 3);
AudioConnection          patchCord5(osc4, 0, mixer2, 0);
AudioConnection          patchCord6(osc5, 0, mixer2, 1);
AudioConnection          patchCord7(osc6, 0, mixer2, 2);
AudioConnection          patchCord8(osc7, 0, mixer2, 3);
AudioConnection          patchCord9(osc8, 0, mixer3, 0);
AudioConnection          patchCord10(osc9, 0, mixer3, 1);
AudioConnection          patchCord11(osc10, 0, mixer3, 2);
AudioConnection          patchCord13(osc11, 0, mixer3, 3);
AudioConnection          patchCord12(subosc0, 0, mixer6, 0);
AudioConnection          patchCord14(subosc2, 0, mixer6, 2);
AudioConnection          patchCord15(subosc1, 0, mixer6, 1);
AudioConnection          patchCord16(subosc6, 0, mixer7, 2);
AudioConnection          patchCord17(subosc4, 0, mixer7, 0);
AudioConnection          patchCord18(subosc8, 0, mixer5, 0);
AudioConnection          patchCord19(subosc3, 0, mixer6, 3);
AudioConnection          patchCord20(subosc7, 0, mixer7, 3);
AudioConnection          patchCord21(subosc5, 0, mixer7, 1);
AudioConnection          patchCord22(subosc9, 0, mixer5, 1);
AudioConnection          patchCord23(subosc10, 0, mixer5, 2);
AudioConnection          patchCord24(subosc11, 0, mixer5, 3);
AudioConnection          patchCord25(mixer3, 0, mixer4, 2);
AudioConnection          patchCord26(mixer1, 0, mixer4, 0);
AudioConnection          patchCord27(mixer2, 0, mixer4, 1);
AudioConnection          patchCord28(mixer5, 0, mixer8, 2);
AudioConnection          patchCord29(mixer6, 0, mixer8, 0);
AudioConnection          patchCord30(mixer7, 0, mixer8, 1);
AudioConnection          patchCord31(mixer4, peak1);
AudioConnection          patchCord32(mixer4, rms1);
AudioConnection          patchCord33(mixer4, amp1);
AudioConnection          patchCord34(mixer8, amp2);
AudioConnection          patchCord35(amp1, dac1);
AudioConnection          patchCord36(amp2, pwm1);
// GUItool: end automatically generated code






#include <Encoder.h>


const int encPins[] = {12, 11, 24};
const int audioSwitchPin = 10;
const int volumePin = 34;
#define DEBOUNCEINTERVAL       5//ms

Bounce audioSwitch = Bounce();
Bounce encButton = Bounce();

Encoder encoder(encPins[0], encPins[1]);


int valueArray[11][6] = {//pin, lowcal,highcal,average,range,frequency
  {0, 600, 700, 0, 0, 0},
  {1, 600, 700, 0, 0, 0},
  {25, 600, 700, 0, 0, 0},
  {17, 600, 700, 0, 0, 0},
  {16, 600, 700, 0, 0, 0},
  {15, 600, 700, 0, 0, 0},
  {32, 600, 700, 0, 0, 0},
  {18, 600, 700, 0, 0, 0},
  {33, 600, 700, 0, 0, 0},
  {19, 600, 700, 0, 0, 0},
  {22, 600, 700, 0, 0, 0}
};
int sensor[12] = {0, 1, 25, 17, 16, 15, 32, 18, 33, 19, 22, 23};
int readings[TONESAMOUNT][numReadings];
int lowCal[TONESAMOUNT];
int highCal[TONESAMOUNT];
int average[TONESAMOUNT];
int range[TONESAMOUNT];
float freq[TONESAMOUNT];
float ampl[TONESAMOUNT];
int buttonState[4] = {0, 0, 0, 0};
float totalAverage;

int readIndex = 0;

void initializingStuff() {

  Serial.begin(115200);

  AudioMemory(15);//increase if the are glitches

  //filter1.frequency(400);

  //setting all the oscillators off
  mixer1.gain(0, 0);
  mixer1.gain(1, 0);
  mixer1.gain(2, 0);
  mixer1.gain(3, 0);
  mixer2.gain(0, 0);
  mixer2.gain(1, 0);
  mixer2.gain(2, 0);
  mixer2.gain(3, 0);
  mixer3.gain(0, 0);
  mixer3.gain(1, 0);
  mixer3.gain(2, 0);

  float noteVol = 0.4;
  osc0.begin(noteVol, 220, WAVEFORM_SINE);
  osc1.begin(noteVol, 220, WAVEFORM_SINE);
  osc2.begin(noteVol, 220, WAVEFORM_SINE);
  osc3.begin(noteVol, 220, WAVEFORM_SINE);
  osc4.begin(noteVol, 220, WAVEFORM_SINE);
  osc5.begin(noteVol, 220, WAVEFORM_SINE);
  osc6.begin(noteVol, 220, WAVEFORM_SINE);
  osc7.begin(noteVol, 220, WAVEFORM_SINE);
  osc8.begin(noteVol, 220, WAVEFORM_SINE);
  osc9.begin(noteVol, 220, WAVEFORM_SINE);
  osc10.begin(noteVol, 220, WAVEFORM_SINE);


  dac1.analogReference(EXTERNAL);//EXTERNAL is louder, but actually to loud
  delay(50);             // time for DAC voltage stable
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH); // turn on the amplifier
  delay(10);

  FastLED.addLeds<LED_TYPE, LEDPIN0, COLOR_ORDER>(leds, 0, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN1, COLOR_ORDER>(leds, 1, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN2, COLOR_ORDER>(leds, 2, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN3, COLOR_ORDER>(leds, 3, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN4, COLOR_ORDER>(leds, 4, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN5, COLOR_ORDER>(leds, 5, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN6, COLOR_ORDER>(leds, 6, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN7, COLOR_ORDER>(leds, 7, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN8, COLOR_ORDER>(leds, 8, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN9, COLOR_ORDER>(leds, 9, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN10, COLOR_ORDER>(leds, 10, 1);
  FastLED.setBrightness(  BRIGHTNESS );

  //pinMode(13, OUTPUT); // turn of the led as this might interfer with SPI
  //digitalWrite(13, HIGH);



  //set up push buttons
  pinMode(audioSwitchPin, INPUT_PULLUP);
  audioSwitch.attach(audioSwitchPin);
  audioSwitch.interval(DEBOUNCEINTERVAL);
  pinMode(encPins[2], INPUT_PULLUP);
  encButton.attach(encPins[2]);
  encButton.interval(DEBOUNCEINTERVAL);





  amp1.gain(1.0);

  //delay(500);
  baselineCalibration();
}

float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  float value =  (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return constrain(value, out_min, out_max);
}
