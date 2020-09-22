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


#define TONESAMOUNT 11 // amount of pads active
float sineMaxAmplitude = 1.0 / TONESAMOUNT + .41; //about one divided by the amount of tones available (.11 is the safest value)

#define debugUpdateTime 50//in ms
#define audioUpdateTime 100//in us   =1ms
#define ledUpdateTime 10//in ms    10ms = 100Hz
#define buttonUpdateTime 1//in ms
#define calibrationUpdateTime 5//in ms

#define lowThreshold 15 //a value to reach before the thing gets triggered
#define maxRange 250 //the maximum range of the sensors
#define glide 10    //glide time for frequency change

#define numReadings  10 // running average of the sensor values

#define autoCalibTime 5000 //ms how long the values should be stable before autoCalib
#define autoCalibRange 20 // how stable the values should be for the timer to start
#define autoCalibSoundRange 0.02 //how much the volume should stay the same for recalibration

#define numReadingsCal  10 // running average of the sensor values
#define calibCycles 10 // it will average this amount of cycles when calibrating

#define midiUpdateTime 5//in ms

int encClicks = 0;

void setup() {
  initializingStuff();
}
bool firstTime = true;
void loop() {

  calibrationUpdate();
  buttonUpdate();
  audioUpdate();
  ledUpdate();
  debugUpdate();
  midiUpdate();

  if (firstTime) {
    baselineCalibration();
    firstTime = false;
  }

}
