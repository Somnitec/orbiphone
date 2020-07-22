#define TONESAMOUNT 7 // amount of pads active
float sineMaxAmplitude = 1.0/TONESAMOUNT + .03; //about one divided by the amount of tones available (.11 is the safest value)

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
