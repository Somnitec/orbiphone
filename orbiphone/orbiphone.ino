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


#define TONESAMOUNT 11 // amount of pads active
float sineMaxAmplitude = 1.0/TONESAMOUNT + .11; //about one divided by the amount of tones available (.11 is the safest value)

#define debugUpdateTime 250//in ms
#define audioUpdateTime 100//in us   =1ms
#define ledUpdateTime 10//in ms    10ms = 100Hz
#define buttonUpdateTime 1//in ms
#define calibrationUpdateTime 5//in ms

#define lowThreshold 5 //a value to reach before the thing gets triggered
#define maxRange 250 //the maximum range of the sensors
#define glide 10    //glide time for frequency change

#define numReadings  75// running average of the sensor values

#define autoCalibTime 3000 //ms how long the values should be stable before autoCalib
#define autoCalibRange 20 // how stable the values should be for the timer to start
#define autoCalibSoundRange 0.02 //how much the volume should stay the same for recalibration
#define calibCycles 50 // it will average this amount of cycles when calibrating

#define midiUpdateTime 5//in ms

void setup() {
  initializingStuff();
}

void loop() {
  
  calibrationUpdate();
  buttonUpdate();
  audioUpdate();
  ledUpdate();
  debugUpdate();
  midiUpdate();

  
  
}
