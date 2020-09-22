//WIRES
//gnd   BLACK  BLUE
//vcc   RED    ORANGE
//touch GREEN  BROWN
//led   PURPLE YELLOW

//PINS
//0 t  touchpad 0
//1 t  touchpad 1
//2    LED0
//3    pwmAudio1
//4    pwmAudio0
//5    LED1
//6    LED2
//7    LED3
//8    LED4
//9    LED5
//10   - (jack sensor -> disconnected)
//11   enc1
//12   enc0
//13   teensy led
//14   LED6
//15 t touchpad 5
//16 t touchpad 4
//17 t touchpad 3
//18 t touchpad 7
//19 t touchpad 9
//20    LED11
//21    ampEnable (potswitch -> switched around)
//22 t touchpad 10
//23 t touchpad 11
// ---backside
//24   encSwitch
//25 t touchpad 2
//26   LED9
//27   LED8
//28   LED7
//29   - (SCL1   (IMPORT wire1.h!))
//30   - (SDA1   (IMPORT wire1.h!))
//31   LED10
//32 t touchpad 6
//33 t touchpad 8
//A10 (34) Potentiometer
//A11 (35) - (battery sensor -> disconnected)
//A12 (36)
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
AudioOutputPWM      audioOutput2;
// The tone sweep goes to left and right channels
AudioConnection c1(myEffect, 0, audioOutput, 0);
AudioConnection c2(myEffect, 0, audioOutput2, 0);

float t_ampx = 0.1;
int t_lox = 20;
int t_hix = 2200;
// Length of time for the sweep in seconds
float t_timex = 10;

const int tonesAmount = 11;
const int touchPins[12] = {0, 1, 25, 17, 16, 15, 32, 18, 33, 19, 22, 23};
const int encPins[] = {12, 11, 24};
const int audioSwitchPin = 10;
const int volumePin = 34;

Encoder encoder(encPins[0], encPins[1]);

#define BRIGHTNESS  255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[tonesAmount];

int cycle = 0;

void setup() {
  pinMode(21, OUTPUT);
  digitalWrite(21, LOW); // turn off the amplifier
  Serial.begin(9600);


  FastLED.addLeds<LED_TYPE, 2, COLOR_ORDER>(leds, 0, 1);
  FastLED.addLeds<LED_TYPE, 5, COLOR_ORDER>(leds, 1, 1);
  FastLED.addLeds<LED_TYPE, 6, COLOR_ORDER>(leds, 2, 1);
  FastLED.addLeds<LED_TYPE, 7, COLOR_ORDER>(leds, 3, 1);
  FastLED.addLeds<LED_TYPE, 8, COLOR_ORDER>(leds, 4, 1);
  FastLED.addLeds<LED_TYPE, 9, COLOR_ORDER>(leds, 5, 1);
  FastLED.addLeds<LED_TYPE, 14, COLOR_ORDER>(leds, 6, 1);
  FastLED.addLeds<LED_TYPE, 28, COLOR_ORDER>(leds, 7, 1);
  FastLED.addLeds<LED_TYPE, 27, COLOR_ORDER>(leds, 8, 1);
  FastLED.addLeds<LED_TYPE, 26, COLOR_ORDER>(leds, 9, 1);
  FastLED.addLeds<LED_TYPE, 31, COLOR_ORDER>(leds, 10, 1);
  FastLED.addLeds<LED_TYPE, 20, COLOR_ORDER>(leds, 11, 1);

  FastLED.setBrightness(  BRIGHTNESS );

  //pinMode(encPins[0], INPUT_PULLUP);
  //pinMode(encPins[1], INPUT_PULLUP);
  pinMode(encPins[2], INPUT_PULLUP);
  //pinMode(audioSwitchPin, INPUT_PULLUP);

  AudioMemory(10);

  audioOutput.analogReference(EXTERNAL); // much louder!
  delay(50);             // time for DAC voltage stable
  pinMode(21, INPUT);// float the amplifier to turn it on

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
  Serial.print(encoder.read()/4);//4 steps per click
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
