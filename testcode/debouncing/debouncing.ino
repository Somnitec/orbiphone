#include <Bounce2.h>

#define BUTTON1PIN            10
#define BUTTON2PIN            11
#define BUTTON3PIN            12
#define DEBOUNCEINTERVAL       5//ms

Bounce button1 = Bounce();
Bounce button2 = Bounce();
Bounce button3 = Bounce();

boolean button1state = 0;
boolean button2state = 0;
boolean button3state = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON1PIN,INPUT_PULLUP);
  button1.attach(BUTTON1PIN);
  button1.interval(DEBOUNCEINTERVAL);
  pinMode(BUTTON2PIN,INPUT_PULLUP);
  button2.attach(BUTTON2PIN);
  button2.interval(DEBOUNCEINTERVAL);
  pinMode(BUTTON3PIN,INPUT_PULLUP);
  button3.attach(BUTTON3PIN);
  button3.interval(DEBOUNCEINTERVAL);
}

void loop() {
  button1.update();
  button2.update();
  button3.update();
  if(button1.fell())button1state=!button1state;
  if(button2.fell())button2state=!button2state;
  if(button3.fell())button3state=!button3state;
  Serial.print(millis());
  Serial.print('\t');
  Serial.print(button1state);
  Serial.print('\t');
  Serial.print(button2state);
  Serial.print('\t');
  Serial.print(button3state);
  Serial.println('\t');
  delay(10);
}
