//WIRES
//gnd   BLACK  BLUE
//vcc   RED    ORANGE
//touch GREEN  BROWN
//led   PURPLE YELLOW

//PINS
//0 t  touchpad 0
//1 t  touchpad 1
//2    IRQ (interrupt from motion sensors)
//3     LED1
//4     LED0
//5   AMP_EN  set High to enable amplifier
//6   MEM_CS  memory  (pull Low to access memory)
//7    audio jack connected    ((disconnected //LED_EN  set High to send LED data//))
//8     LED4
//9     LED3
//10    LED2
//11   MOSI memory,led  SPI Data
//12   MISO memory  SPI Data
//13   SCK  memory,led  SPI Clock
//14    enc but0
//15 t touchpad 3
//16 t touchpad 2
//17 t touchpad 4
//18 t SDA0   LED10
//19 t SCL0   touchpad 10
//20    LED6
//21    LED5
//22 t touchpad 5
//23 t touchpad 6
// ---backside
//24    LED7
//25 t touchpad 7
//26   LED9
//27    enc1
//28    enc0
//29   SCL1  - I2C Clock for motion sensors   (IMPORT wire1.h!)
//30   SDA1  - I2C Data for motion sensors    (IMPORT wire1.h!)
//31   LED8
//32 t touchpad 8
//33 t touchpad 9
//A10 (34)
//A11 (35)
//A12 (36) ??? volume???
//A13 (37)
//(38) internal temp sensor


//went into touch.c and changed the following values:
//#define CURRENT   15 // 0 to 15 - current to use, value is 2*(current+1)
//#define NSCAN     7// number of times to scan, 0 to 31, value is nscan+1
//#define PRESCALE  5 // prescaler, 0 to 7 - value is 2^(prescaler+1)

#include <FastLED.h>
#include <Encoder.h>
#include <Audio.h>

AudioSynthToneSweep myEffect;
AudioOutputAnalog      audioOutput;        // audio shield: headphones & line-out

// The tone sweep goes to left and right channels
AudioConnection c1(myEffect, 0, audioOutput, 0);
AudioConnection c2(myEffect, 0, audioOutput, 1);

float t_ampx = 0.1;
int t_lox = 20;
int t_hix = 2200;
// Length of time for the sweep in seconds
float t_timex = 10;

const int tonesAmount = 11;
const int touchPins[11] = {0, 1, 16, 15, 17, 22, 23, 25, 32, 33, 19};
const int encPins[] = {28, 27, 14};
const int audioSwitchPin = 7;
const int volumePin = 36;

Encoder encoder(encPins[0], encPins[1]);

#define BRIGHTNESS  255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[tonesAmount];

int cycle = 0;

void setup() {
  Serial.begin(9600);


  FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(leds, 0, 1);
  FastLED.addLeds<LED_TYPE, 3, COLOR_ORDER>(leds, 1, 1);
  FastLED.addLeds<LED_TYPE, 10, COLOR_ORDER>(leds, 2, 1);
  FastLED.addLeds<LED_TYPE, 9, COLOR_ORDER>(leds, 3, 1);
  FastLED.addLeds<LED_TYPE, 8, COLOR_ORDER>(leds, 4, 1);
  FastLED.addLeds<LED_TYPE, 21, COLOR_ORDER>(leds, 5, 1);
  FastLED.addLeds<LED_TYPE, 20, COLOR_ORDER>(leds, 6, 1);
  FastLED.addLeds<LED_TYPE, 24, COLOR_ORDER>(leds, 7, 1);
  FastLED.addLeds<LED_TYPE, 31, COLOR_ORDER>(leds, 8, 1);
  FastLED.addLeds<LED_TYPE, 26, COLOR_ORDER>(leds, 9, 1);
  FastLED.addLeds<LED_TYPE, 18, COLOR_ORDER>(leds, 10, 1);

  FastLED.setBrightness(  BRIGHTNESS );

  pinMode(encPins[2], INPUT_PULLUP);
  pinMode(audioSwitchPin, INPUT_PULLUP);

  AudioMemory(10);

  audioOutput.analogReference(EXTERNAL); // much louder!
  delay(50);             // time for DAC voltage stable
  pinMode(5, OUTPUT);
  digitalWrite(5, HIGH); // turn on the amplifier
  delay(10);

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Serial.println("setup done");


}

void loop() {
  digitalWrite(5, !digitalRead(audioSwitchPin));


  if (!myEffect.isPlaying() && !digitalRead(encPins[2])) {
    if (!myEffect.play(t_ampx, t_lox, t_hix, t_timex)) {
      Serial.println("AudioSynthToneSweep - begin failed");
      while (1);
    }
  }

  elapsedMicros measuretime = 0;
  for (int i = 0; i < tonesAmount; i++) {
    Serial.print(i);
    Serial.print(":");
    Serial.print(touchRead(touchPins[i]));
    Serial.print('\t');
  }
 
  Serial.print("measuretime:");
  Serial.print(measuretime);
  Serial.print('\t');
  //  int i = 8;
  //  Serial.print(i);
  //  Serial.print(":");
  //  Serial.print(touchRead(touchPins[i]));
  //  Serial.print('\t');

  Serial.print("enc:");
  Serial.print((abs(encoder.read())/4)%3);
  Serial.print('\t');
  Serial.print("encbut:");
  Serial.print(digitalRead(encPins[2]));
  Serial.print('\t');
  Serial.print("volume:");
  Serial.print(analogRead(volumePin));
  Serial.print('\t');
  Serial.print("audioswitch:");
  Serial.print(digitalRead(audioSwitchPin));
  Serial.println('\t');



  //leds[(cycle % (tonesAmount*10))/10] = CHSV( 0,0,0);
  cycle++;
  leds[(cycle % (tonesAmount * 10)) / 10] = CHSV( (millis() / 20) % 255, 255, 255);

  FastLED.show();


  delay(10);
}
