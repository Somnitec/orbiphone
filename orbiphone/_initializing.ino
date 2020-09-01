#include <Audio.h>
#include <FastLED.h>
#include <Bounce2.h>

#define LEDPIN0          4
#define LEDPIN1          3
#define LEDPIN2          10
#define LEDPIN3          9
#define LEDPIN4          8
#define LEDPIN5          21
#define LEDPIN6          20
#define LEDPIN7          24
#define LEDPIN8          31
#define LEDPIN9          26
#define LEDPIN10         18

#define BRIGHTNESS  255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[TONESAMOUNT];

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform sine1;          //xy=1090,693
AudioSynthWaveform sine2;          //xy=1112,575
AudioSynthWaveform sine3;          //xy=1123,644
AudioSynthWaveform sine4;          //xy=1137,612
AudioSynthWaveform sine5;          //xy=1140,285
AudioSynthWaveform sine6;          //xy=1140,332
AudioSynthWaveform sine7;          //xy=1140,481
AudioSynthWaveform sine8;          //xy=1142,239
AudioSynthWaveform sine9;          //xy=1145,524
AudioSynthWaveform sine10;         //xy=1154,432
AudioSynthWaveform sine11;         //xy=1175,375
AudioMixer4              mixer1;         //xy=1434,551
AudioMixer4              mixer2;         //xy=1454,422
AudioMixer4              mixer3;         //xy=1467,307
AudioMixer4              mixer4;         //xy=1688,425
AudioAnalyzePeak         peak1;          //xy=1859,304
AudioAmplifier           amp1;           //xy=1866,434
AudioAnalyzeRMS          rms1;           //xy=1869,314
AudioOutputAnalog        dac1;           //xy=2008,426
AudioConnection          patchCord1(sine1, 0, mixer1, 0);
AudioConnection          patchCord2(sine2, 0, mixer1, 1);
AudioConnection          patchCord3(sine3, 0, mixer1, 2);
AudioConnection          patchCord4(sine4, 0, mixer1, 3);
AudioConnection          patchCord5(sine5, 0, mixer2, 0);
AudioConnection          patchCord6(sine6, 0, mixer2, 1);
AudioConnection          patchCord7(sine7, 0, mixer2, 2);
AudioConnection          patchCord8(sine8, 0, mixer2, 3);
AudioConnection          patchCord9(sine9, 0, mixer3, 0);
AudioConnection          patchCord10(sine10, 0, mixer3, 1);
AudioConnection          patchCord11(sine11, 0, mixer3, 2);
AudioConnection          patchCord12(mixer1, 0, mixer4, 0);
AudioConnection          patchCord13(mixer2, 0, mixer4, 1);
AudioConnection          patchCord14(mixer3, 0, mixer4, 2);
AudioConnection          patchCord15(mixer4, peak1);
AudioConnection          patchCord16(mixer4, rms1);
AudioConnection          patchCord17(mixer4, amp1);
AudioConnection          patchCord18(amp1, dac1);
// GUItool: end automatically generated code


#include <Encoder.h>


const int encPins[] = {28, 27, 14};
const int audioSwitchPin = 7;
const int volumePin = 36;
#define DEBOUNCEINTERVAL       5//ms

Bounce audioSwitch = Bounce();
Bounce encButton = Bounce();

Encoder encoder(encPins[0], encPins[1]);


int valueArray[11][6] = {//pin, lowcal,highcal,average,range,frequency
  {0, 600, 700, 0, 0, 0},
  {1, 600, 700, 0, 0, 0},
  {16, 600, 700, 0, 0, 0},
  {15, 600, 700, 0, 0, 0},
  {17, 600, 700, 0, 0, 0},
  {22, 600, 700, 0, 0, 0},
  {23, 600, 700, 0, 0, 0},
  {25, 600, 700, 0, 0, 0},
  {32, 600, 700, 0, 0, 0},
  {33, 600, 700, 0, 0, 0},
  {19, 600, 700, 0, 0, 0}
};
int sensor[11] = {0, 1, 16, 15, 17, 22, 23, 25, 32, 33, 19};
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

  AudioMemory(12);//increase if the are glitches


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
  sine1.begin(noteVol, 220, WAVEFORM_SINE);
  sine2.begin(noteVol, 220, WAVEFORM_SINE);
  sine3.begin(noteVol, 220, WAVEFORM_SINE);
  sine4.begin(noteVol, 220, WAVEFORM_SINE);
  sine5.begin(noteVol, 220, WAVEFORM_SINE);
  sine6.begin(noteVol, 220, WAVEFORM_SINE);
  sine7.begin(noteVol, 220, WAVEFORM_SINE);
  sine8.begin(noteVol, 220, WAVEFORM_SINE);
  sine9.begin(noteVol, 220, WAVEFORM_SINE);
  sine10.begin(noteVol, 220, WAVEFORM_SINE);
  sine11.begin(noteVol, 220, WAVEFORM_SINE);


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
