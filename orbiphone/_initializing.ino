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
#define LEDPIN9          24
#define LEDPIN10         18

#define BRIGHTNESS  255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[TONESAMOUNT];

// GUItool: begin automatically generated code
AudioSynthWaveformSineHires sine1;   //xy=301,889
AudioSynthWaveformSineHires sine2;    //xy=323,771
AudioSynthWaveformSineHires sine3;   //xy=334,840
AudioSynthWaveformSineHires sine4;    //xy=348,808
AudioSynthWaveformSineHires sine5;    //xy=351,481
AudioSynthWaveformSineHires sine6;    //xy=351,528
AudioSynthWaveformSineHires sine7;    //xy=351,677
AudioSynthWaveformSineHires sine8;    //xy=353,435
AudioSynthWaveformSineHires sine9;    //xy=356,720
AudioSynthWaveformSineHires sine10;    //xy=365,628
AudioSynthWaveformSineHires sine11;    //xy=386,571
AudioMixer4              mixer1;         //xy=645,747
AudioMixer4              mixer2;         //xy=665,618
AudioMixer4              mixer3;         //xy=678,503
AudioMixer4              mixer4;         //xy=899,621
AudioAnalyzePeak         peak1;          //xy=1070,500
AudioAnalyzeRMS          rms1;          //xy=1080,510
AudioOutputAnalog        dac1;           //xy=1078,625
//AudioOutputUSB           usb1;
AudioConnection          patchCord1( sine1,  0, mixer1, 0);
AudioConnection          patchCord2( sine2,  0, mixer1, 1);
AudioConnection          patchCord3( sine3,  0, mixer1, 2);
AudioConnection          patchCord4( sine4,  0, mixer1, 3);
AudioConnection          patchCord5( sine5,  0, mixer2, 0);
AudioConnection          patchCord6( sine6,  0, mixer2, 1);
AudioConnection          patchCord7( sine7,  0, mixer2, 2);
AudioConnection          patchCord8( sine8,  0, mixer2, 3);
AudioConnection          patchCord9( sine9,  0, mixer3, 0);
AudioConnection          patchCord10(sine10, 0, mixer3, 1);
AudioConnection          patchCord11(sine11, 0, mixer3, 2);
AudioConnection          patchCord12(mixer1, 0, mixer4, 0);
AudioConnection          patchCord13(mixer2, 0, mixer4, 1);
AudioConnection          patchCord14(mixer3, 0, mixer4, 2);
AudioConnection          patchCord15(mixer4, dac1);
AudioConnection          patchCord16(mixer4, peak1);
AudioConnection          patchCord17(mixer4, rms1);
//AudioConnection          patchCord18(mixer4,0, usb1,0);
//AudioConnection          patchCord19(mixer4,0, usb1,1);
// GUItool: end automatically generated code

const int encPins[] = {28, 27, 14};
const int audioSwitchPin = 7;
const int volumePin = 36;
#define DEBOUNCEINTERVAL       5//ms

Bounce audioSwitch = Bounce();
Bounce encButton = Bounce();


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
int readings[11][numReadings];
int lowCal[11];
int highCal[11];
int average[11];
int range[11];
float freq[11];
float ampl[11];
int buttonState[4]= {0,0,0,0};
float totalAverage;

int readIndex = 0;

void initializingStuff() {

  Serial.begin(115200);

  AudioMemory(12);//increase if the are glitches
  dac1.analogReference(EXTERNAL);//EXTERNAL is louder, but actually too loud

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

  baselineCalibration();

  //set up push buttons
  pinMode(audioSwitchPin, INPUT_PULLUP);
  audioSwitch.attach(audioSwitchPin);
  audioSwitch.interval(DEBOUNCEINTERVAL);
  pinMode(encPins[2], INPUT_PULLUP);
  encButton.attach(encPins[2]);
  encButton.interval(DEBOUNCEINTERVAL);

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
}

float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  float value =  (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return constrain(value, out_min, out_max);
}
