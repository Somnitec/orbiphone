void doSensorReadFast() {
  float value[12];
  for (int i = 0; i < TONESAMOUNT; i++) {
    value[i] = touchRead(sensor[i]); //just to get some empty values out of the way
  }

  //if (1) { //direct sensor reading version
  //value = touchRead(sensor[0]);
  bufferFast0.addValue(value[0]);
  ampl[0] = fmap(value[0], bufferSlow0.getMin(), bufferSlow0.getMax() + 1, lowerThreshold, 1. + topAdjust);

  //value = touchRead(sensor[1]);
  bufferFast1.addValue(value[1]);
  ampl[1] = fmap(value[1], bufferSlow1.getMin(), bufferSlow1.getMax() + 1, lowerThreshold, 1. + topAdjust);

  //value = touchRead(sensor[2]);
  bufferFast2.addValue(value[2]);
  ampl[2] = fmap(value[2], bufferSlow2.getMin(), bufferSlow2.getMax() + 1, lowerThreshold, 1. + topAdjust);

  //value = touchRead(sensor[3]);
  bufferFast3.addValue(value[3]);
  ampl[3] = fmap(value[3], bufferSlow3.getMin(), bufferSlow3.getMax() + 1, lowerThreshold, 1. + topAdjust);

  //value = touchRead(sensor[4]);
  bufferFast4.addValue(value[4]);
  ampl[4] = fmap(value[4], bufferSlow4.getMin(), bufferSlow4.getMax() + 1, lowerThreshold, 1. + topAdjust);

  //value = touchRead(sensor[5]);
  bufferFast5.addValue(value[5]);
  ampl[5] = fmap(value[5], bufferSlow5.getMin(), bufferSlow5.getMax() + 1, lowerThreshold, 1. + topAdjust);

  //value = touchRead(sensor[6]);
  bufferFast6.addValue(value[6]);
  ampl[6] = fmap(value[6], bufferSlow6.getMin(), bufferSlow6.getMax() + 1, lowerThreshold, 1. + topAdjust);

  //value = touchRead(sensor[7]);
  bufferFast7.addValue(value[7]);
  ampl[7] = fmap(value[7], bufferSlow7.getMin(), bufferSlow7.getMax() + 1, lowerThreshold, 1. + topAdjust);

  //value = touchRead(sensor[8]);
  bufferFast8.addValue(value[8]);
  ampl[8] = fmap(value[8], bufferSlow8.getMin(), bufferSlow8.getMax() + 1, lowerThreshold, 1. + topAdjust);

  //value = touchRead(sensor[9]);
  bufferFast9.addValue(value[9]);
  ampl[9] = fmap(value[9], bufferSlow9.getMin(), bufferSlow9.getMax() + 1, lowerThreshold, 1. + topAdjust);

  //value = touchRead(sensor[10]);
  bufferFast10.addValue(value[10]);
  ampl[10] = fmap(value[10], bufferSlow10.getMin(), bufferSlow10.getMax() + 1, lowerThreshold, 1. + topAdjust);

  //value = touchRead(sensor[11]);
  bufferFast11.addValue(value[11]);
  ampl[11] = fmap(value[11], bufferSlow11.getMin(), bufferSlow11.getMax() + 1, lowerThreshold, 1. + topAdjust);
  //}
  //   if (false) { //averaged sensor reading version
  //
  //    value = touchRead(sensor[0]);
  //    bufferFast0.addValue(value);
  //    ampl[0] = fmap(bufferFast0.getAverage(), bufferSlow0.getMin(), bufferSlow0.getMax() + 1, lowerThreshold, 1.);
  //
  //    value = touchRead(sensor[1]);
  //    bufferFast1.addValue(value);
  //    ampl[1] = fmap(bufferFast1.getAverage(), bufferSlow1.getMin(), bufferSlow1.getMax() + 1, lowerThreshold, 1.);
  //
  //    value = touchRead(sensor[2]);
  //    bufferFast2.addValue(value);
  //    ampl[2] = fmap(bufferFast2.getAverage(), bufferSlow2.getMin(), bufferSlow2.getMax() + 1, lowerThreshold, 1.);
  //
  //    value = touchRead(sensor[3]);
  //    bufferFast3.addValue(value);
  //    ampl[3] = fmap(bufferFast3.getAverage(), bufferSlow3.getMin(), bufferSlow3.getMax() + 1, lowerThreshold, 1.);
  //
  //    value = touchRead(sensor[4]);
  //    bufferFast4.addValue(value);
  //    ampl[4] = fmap(bufferFast4.getAverage(), bufferSlow4.getMin(), bufferSlow4.getMax() + 1, lowerThreshold, 1.);//some weird bug makes the slow min bug
  //
  //    value = touchRead(sensor[5]);
  //    bufferFast5.addValue(value);
  //    ampl[5] = fmap(bufferFast5.getAverage(), bufferSlow5.getMin(), bufferSlow5.getMax() + 1, lowerThreshold, 1.);
  //
  //    value = touchRead(sensor[6]);
  //    bufferFast6.addValue(value);
  //    ampl[6] = fmap(bufferFast6.getAverage(), bufferSlow6.getMin(), bufferSlow6.getMax() + 1, lowerThreshold, 1.);
  //
  //    value = touchRead(sensor[7]);
  //    bufferFast7.addValue(value);
  //    ampl[7] = fmap(bufferFast7.getAverage(), bufferSlow7.getMin(), bufferSlow7.getMax() + 1, lowerThreshold, 1.);
  //
  //    value = touchRead(sensor[8]);
  //    bufferFast8.addValue(value);
  //    ampl[8] = fmap(bufferFast8.getAverage(), bufferSlow8.getMin(), bufferSlow8.getMax() + 1, lowerThreshold, 1.);
  //
  //    value = touchRead(sensor[9]);
  //    bufferFast9.addValue(value);
  //    ampl[9] = fmap(bufferFast9.getAverage(), bufferSlow9.getMin(), bufferSlow9.getMax() + 1, lowerThreshold, 1.);
  //
  //    value = touchRead(sensor[10]);
  //    bufferFast10.addValue(value);
  //    ampl[10] = fmap(bufferFast10.getAverage(), bufferSlow10.getMin(), bufferSlow10.getMax() + 1, lowerThreshold, 1.);
  //
  //    value = touchRead(sensor[11]);
  //    bufferFast11.addValue(value);
  //    ampl[11] = fmap(bufferFast11.getAverage(), bufferSlow11.getMin(), bufferSlow11.getMax() + 1, lowerThreshold, 1.);
  //  }


}

void doSensorReadSlow(int mod) {
  //  bufferSlow0.addValue(bufferFast0.getAverage() + mod);
  //  bufferSlow1.addValue(bufferFast1.getAverage() + mod);
  //  bufferSlow2.addValue(bufferFast2.getAverage() + mod);
  //  bufferSlow3.addValue(bufferFast3.getAverage() + mod);
  //  bufferSlow4.addValue(bufferFast4.getAverage() + mod);
  //  bufferSlow5.addValue(bufferFast5.getAverage() + mod);
  //  bufferSlow6.addValue(bufferFast6.getAverage() + mod);
  //  bufferSlow7.addValue(bufferFast7.getAverage() + mod);
  //  bufferSlow8.addValue(bufferFast8.getAverage() + mod);
  //  bufferSlow9.addValue(bufferFast9.getAverage() + mod);
  //  bufferSlow10.addValue(bufferFast10.getAverage() + mod);
  //  bufferSlow11.addValue(bufferFast11.getAverage() + mod);

  bufferSlow0.addValue( touchRead(sensor[0]) + mod);
  bufferSlow1.addValue( touchRead(sensor[1]) + mod);
  bufferSlow2.addValue( touchRead(sensor[2]) + mod);
  bufferSlow3.addValue( touchRead(sensor[3]) + mod);
  bufferSlow4.addValue( touchRead(sensor[4]) + mod);
  bufferSlow5.addValue( touchRead(sensor[5]) + mod);
  bufferSlow6.addValue( touchRead(sensor[6]) + mod);
  bufferSlow7.addValue( touchRead(sensor[7]) + mod);
  bufferSlow8.addValue( touchRead(sensor[8]) + mod);
  bufferSlow9.addValue( touchRead(sensor[9]) + mod);
  bufferSlow10.addValue( touchRead(sensor[10]) + mod);
  bufferSlow11.addValue( touchRead(sensor[11]) + mod);

  amplChange[0] = bufferSlow0.getStandardDeviation();
  amplChange[1] = bufferSlow1.getStandardDeviation();
  amplChange[2] = bufferSlow2.getStandardDeviation();
  amplChange[3] = bufferSlow3.getStandardDeviation();
  amplChange[4] = bufferSlow4.getStandardDeviation();
  amplChange[5] = bufferSlow5.getStandardDeviation();
  amplChange[6] = bufferSlow6.getStandardDeviation();
  amplChange[7] = bufferSlow7.getStandardDeviation();
  amplChange[8] = bufferSlow8.getStandardDeviation();
  amplChange[9] = bufferSlow9.getStandardDeviation();
  amplChange[10] = bufferSlow10.getStandardDeviation();
  amplChange[11] = bufferSlow11.getStandardDeviation();

}

void baseLineCalibration() {
  resetRunningAverages();
  delay(10);
  for (int i = 0; i < 8; i++) {//throwing out x readings to make sure we start with an actual one
    for (int i = 0; i < TONESAMOUNT; i++) {
      touchRead(sensor[i]);//just to get some empty values out of the way
    }
  }

  for (int i = 0; i < datapointsFast + datapointsSlow; i++) {
    doSensorReadFast();
    doSensorReadSlow(defaultSensorMaxRange);

    //delay(10);
  }
  //Serial.println("recalibrated");
}

void resetRunningAverages() {
  bufferFast0.clear();
  bufferSlow0.clear();
  bufferFast1.clear();
  bufferSlow1.clear();
  bufferFast2.clear();
  bufferSlow2.clear();
  bufferFast3.clear();
  bufferSlow3.clear();
  bufferFast4.clear();
  bufferSlow4.clear();
  bufferFast5.clear();
  bufferSlow5.clear();
  bufferFast6.clear();
  bufferSlow6.clear();
  bufferFast7.clear();
  bufferSlow7.clear();
  bufferFast8.clear();
  bufferSlow8.clear();
  bufferFast9.clear();
  bufferSlow9.clear();
  bufferFast10.clear();
  bufferSlow10.clear();
  bufferFast11.clear();
  bufferSlow11.clear();
}
