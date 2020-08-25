

#define lowThreshold 5 //a value to reach before the thing gets triggered
#define maxRange 250 //the maximum range of the sensors

#define numReadings  75// running average of the sensor values

#define autoCalibTime 3000 //ms how long the values should be stable before autoCalib
#define autoCalibRange 20 // how stable the values should be for the timer to start
#define autoCalibSoundRange 0.02 //how much the volume should stay the same for recalibration
#define calibCycles 50 // it will average this amount of cycles when calibrating

elapsedMillis calibrationUpdateTimer;
elapsedMillis stableTimer;
elapsedMillis stableAudioTimer;
float previousPeak;

void calibrationUpdate() {
  if (calibrationUpdateTimer > calibrationUpdateTime) {
    calibrationUpdateTimer = 0;
    for (int i = 0; i < NUM_PADS; i++) {
      if (range[i] > autoCalibRange)stableTimer = 0;//||peak1.read()<0.01
    }

    float currentPeak = rms1.read();
    if (currentPeak > autoCalibSoundRange)stableAudioTimer = 0;
    //previousPeak = currentPeak;

    if (stableTimer > autoCalibTime || stableAudioTimer > autoCalibTime) {
      Serial.println("RECALIBRATION TIME, AW YIZZ");
      baselineCalibration();
      stableTimer = 0;
      stableAudioTimer = 0;
    }

  }
}

void baselineCalibration() {

  for (int i = 0; i < NUM_PADS; i++) {
    int readAverage = 0;
    for (int j = 0; j < calibCycles; j++) {
      readAverage += touchRead(sensor[i]);
    }
    lowCal[i] = readAverage / calibCycles + lowThreshold;
    highCal[i] = lowCal[i] + maxRange;
  }
  Serial.println("CALIBRATION");
}
