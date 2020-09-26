elapsedMillis calibrationUpdateTimer;
elapsedMillis stableTimer;
elapsedMillis stableAudioTimer;
float previousPeak;

void calibrationUpdate() {
  if (calibrationUpdateTimer > calibrationUpdateTime) {
    calibrationUpdateTimer = 0;
    for (int i = 0; i < TONESAMOUNT; i++) {
      if (range[i] > autoCalibRange)stableTimer = 0;//||peak1.read()<0.01
    }

    float currentPeak = rms1.read();
    if (currentPeak > autoCalibSoundRange)stableAudioTimer = 0;
    //previousPeak = currentPeak;

    //something broken here?
    if (stableTimer > autoCalibTime && stableAudioTimer > autoCalibTime) {
      Serial.println();
      Serial.println("RECALIBRATION TIME, AW YIZZ");
      baselineCalibration();
      stableTimer = 0;
      stableAudioTimer = 0;
    }

  }
}

void baselineCalibration() {
  // old calibration with some problems
  for (int i = 0; i < TONESAMOUNT; i++) {
    long readAverage = 0;
    for (int j = 0; j < calibCycles; j++) {
      readAverage += touchRead(sensor[i]);
      delay(1);
    }
    lowCal[i] = readAverage / calibCycles + lowThreshold;
    highCal[i] = lowCal[i] + maxRange;
    delay(10);
  }
  //Serial.println("CALIBRATION");


  //  long total[TONESAMOUNT];
  //  for (int i = 0; i < TONESAMOUNT; i++) {
  //    total[i] = 0;
  //  }
  //  for (int h = 0; h < calibCycles; h++) {
  //    long suboscTotal[TONESAMOUNT];
  //    for (int i = 0; i < TONESAMOUNT; i++) {
  //      suboscTotal[i] = 0;
  //    }
  //    for (int i = 0; i < TONESAMOUNT; i++) {
  //      for (int j = 0; j < numReadingsCal; j++) {
  //
  //        suboscTotal[i] +=  touchRead(sensor[i]);
  //      }
  //    }
  //    for (int i = 0; i < TONESAMOUNT; i++) {
  //      total[i] += suboscTotal[i]  / numReadingsCal;
  //      if (i == 4) {
  //        Serial.println(total[i] / h);
  //      }
  //    }
  //
  //  }
  //
  //  for (int i = 0; i < TONESAMOUNT; i++) {
  //
  //    int totalCalc = (total[i]  / calibCycles);
  //    lowCal[i] = totalCalc + lowThreshold;
  //    highCal[i] = lowCal[i] + maxRange;
  //  }

  //an attempt to preset the calibration values, but it don't work when the instrument is in a different location or the cable is unplugged
  //  int calVals[] = {4750, 5030, 4805, 4369, 5135, 4715, 5112, 4060, 4138, 3788, 3783};
  //  for (int i = 0; i < TONESAMOUNT; i++) {
  //
  //    lowCal[i] = calVals[i] + lowThreshold;
  //    highCal[i] = lowCal[i] + maxRange;
  //  }
}
