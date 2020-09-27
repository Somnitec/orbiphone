#include <Audio.h>
#include <FastLED.h>
#include <Bounce2.h>

#include "RunningAverage.h"
#include <Encoder.h>



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

#define ampPin 21

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

// storage of "temporal window" of 50 data points:
RunningAverage xFast0(datapointsFast);   // to store x data (time)
RunningAverage yFast0(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast0(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast0(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow0(datapointsSlow);   // to store x data (time)
RunningAverage ySlow0(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow0(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow0(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast0 = 0;
float slopeSlow0 = 0;

RunningAverage xFast1(datapointsFast);   // to store x data (time)
RunningAverage yFast1(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast1(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast1(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow1(datapointsSlow);   // to store x data (time)
RunningAverage ySlow1(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow1(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow1(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast1 = 0;
float slopeSlow1 = 0;

RunningAverage xFast2(datapointsFast);   // to store x data (time)
RunningAverage yFast2(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast2(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast2(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow2(datapointsSlow);   // to store x data (time)
RunningAverage ySlow2(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow2(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow2(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast2 = 0;
float slopeSlow2 = 0;

RunningAverage xFast3(datapointsFast);   // to store x data (time)
RunningAverage yFast3(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast3(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast3(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow3(datapointsSlow);   // to store x data (time)
RunningAverage ySlow3(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow3(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow3(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast3 = 0;
float slopeSlow3 = 0;

RunningAverage xFast4(datapointsFast);   // to store x data (time)
RunningAverage yFast4(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast4(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast4(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow4(datapointsSlow);   // to store x data (time)
RunningAverage ySlow4(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow4(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow4(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast4 = 0;
float slopeSlow4 = 0;

RunningAverage xFast5(datapointsFast);   // to store x data (time)
RunningAverage yFast5(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast5(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast5(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow5(datapointsSlow);   // to store x data (time)
RunningAverage ySlow5(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow5(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow5(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast5 = 0;
float slopeSlow5 = 0;

RunningAverage xFast6(datapointsFast);   // to store x data (time)
RunningAverage yFast6(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast6(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast6(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow6(datapointsSlow);   // to store x data (time)
RunningAverage ySlow6(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow6(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow6(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast6 = 0;
float slopeSlow6 = 0;

RunningAverage xFast7(datapointsFast);   // to store x data (time)
RunningAverage yFast7(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast7(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast7(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow7(datapointsSlow);   // to store x data (time)
RunningAverage ySlow7(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow7(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow7(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast7 = 0;
float slopeSlow7 = 0;

RunningAverage xFast8(datapointsFast);   // to store x data (time)
RunningAverage yFast8(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast8(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast8(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow8(datapointsSlow);   // to store x data (time)
RunningAverage ySlow8(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow8(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow8(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast8 = 0;
float slopeSlow8 = 0;

RunningAverage xFast9(datapointsFast);   // to store x data (time)
RunningAverage yFast9(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast9(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast9(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow9(datapointsSlow);   // to store x data (time)
RunningAverage ySlow9(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow9(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow9(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast9 = 0;
float slopeSlow9 = 0;

RunningAverage xFast10(datapointsFast);   // to store x data (time)
RunningAverage yFast10(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast10(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast10(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow10(datapointsSlow);   // to store x data (time)
RunningAverage ySlow10(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow10(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow10(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast10 = 0;
float slopeSlow10 = 0;

RunningAverage xFast11(datapointsFast);   // to store x data (time)
RunningAverage yFast11(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast11(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast11(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow11(datapointsSlow);   // to store x data (time)
RunningAverage ySlow11(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow11(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow11(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast11 = 0;
float slopeSlow11 = 0;



bool stable = false;
long stableTimer = 0;




const int encPins[] = {12, 11, 24};

const int volumePin = 34;
#define DEBOUNCEINTERVAL       5//ms

//Bounce audioSwitch = Bounce();
Bounce encButton = Bounce();

Encoder encoder(encPins[1], encPins[0]);


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
  pinMode(ampPin, OUTPUT);
  digitalWrite(ampPin, LOW); // turn on the amplifier

  Serial.begin(115200);

  //set up push buttons
  //pinMode(audioSwitchPin, INPUT_PULLUP);
  //audioSwitch.attach(audioSwitchPin);
  //audioSwitch.interval(DEBOUNCEINTERVAL);
  pinMode(encPins[2], INPUT_PULLUP);
  encButton.attach(encPins[2]);
  encButton.interval(DEBOUNCEINTERVAL);

  encoder.write(1000);

  AudioMemory(15);//increase if the are glitches

  int filtFreq = 1;
  filter0.frequency(filtFreq);
  filter1.frequency(filtFreq);
  filter2.frequency(filtFreq);
  filter3.frequency(filtFreq);
  filter4.frequency(filtFreq);
  filter5.frequency(filtFreq);
  filter6.frequency(filtFreq);
  filter7.frequency(filtFreq);
  filter8.frequency(filtFreq);
  filter9.frequency(filtFreq);
  filter10.frequency(filtFreq);
  filter11.frequency(filtFreq);

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
  mixer3.gain(3, 0);

  mixer1sub.gain(0, 0);
  mixer1sub.gain(1, 0);
  mixer1sub.gain(2, 0);
  mixer1sub.gain(3, 0);
  mixer2sub.gain(0, 0);
  mixer2sub.gain(1, 0);
  mixer2sub.gain(2, 0);
  mixer2sub.gain(3, 0);
  mixer3sub.gain(0, 0);
  mixer3sub.gain(1, 0);
  mixer3sub.gain(2, 0);
  mixer3sub.gain(3, 0);


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
  // time for DAC voltage stable

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


  if (digitalRead(encPins[2])) {
    delay(50);
    pinMode(ampPin, INPUT);
    delay(50);
  };


  amp1.gain(1.0);
  amp1sub.gain(1.0);

  delay(500);
  audioUpdate();
  baselineCalibration();
}

float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  float value =  (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return constrain(value, out_min, out_max);
}
