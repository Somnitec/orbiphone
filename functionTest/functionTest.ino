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

#include <FastLED.h>
#include <Encoder.h>

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

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {

  for (int i = 0; i < tonesAmount; i++) {
    Serial.print(i);
    Serial.print(":");
    Serial.print(touchRead(touchPins[i]));
    Serial.print('\t');
  }


  Serial.print("enc:");
  Serial.print(encoder.read());
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
  leds[(cycle % (tonesAmount*10))/10] = CHSV( (millis() / 20) % 255, 255, 255);

  //FastLED.show();


  delay(10);
}
