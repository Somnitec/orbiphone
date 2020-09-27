void doSensorReadFast() {

  bufferFast0.addValue(touchRead(sensor[0]));
  ampl[0] = fmap(touchRead(sensor[0]), bufferSlow0.getMin(), bufferSlow0.getMax() + 1, lowerThreshold, 1.);

  bufferFast1.addValue(touchRead(sensor[1]));
  ampl[1] = fmap(touchRead(sensor[1]), bufferSlow1.getMin(), bufferSlow1.getMax() + 1, lowerThreshold, 1.);

  bufferFast2.addValue(touchRead(sensor[2]));
  ampl[2] = fmap(touchRead(sensor[2]), bufferSlow2.getMin(), bufferSlow2.getMax() + 1, lowerThreshold, 1.);

  bufferFast3.addValue(touchRead(sensor[3]));
  ampl[3] = fmap(touchRead(sensor[3]), bufferSlow3.getMin(), bufferSlow3.getMax() + 1, lowerThreshold, 1.);

  bufferFast4.addValue(touchRead(sensor[4]));
  ampl[4] = fmap(touchRead(sensor[4]), bufferSlow4.getMin(), bufferSlow4.getMax() + 1, lowerThreshold, 1.);

  bufferFast5.addValue(touchRead(sensor[5]));
  ampl[5] = fmap(touchRead(sensor[5]), bufferSlow5.getMin(), bufferSlow5.getMax() + 1, lowerThreshold, 1.);

  bufferFast6.addValue(touchRead(sensor[6]));
  ampl[6] = fmap(touchRead(sensor[6]), bufferSlow6.getMin(), bufferSlow6.getMax() + 1, lowerThreshold, 1.);

  bufferFast7.addValue(touchRead(sensor[7]));
  ampl[7] = fmap(touchRead(sensor[7]), bufferSlow7.getMin(), bufferSlow7.getMax() + 1, lowerThreshold, 1.);

  bufferFast8.addValue(touchRead(sensor[8]));
  ampl[8] = fmap(touchRead(sensor[8]), bufferSlow8.getMin(), bufferSlow8.getMax() + 1, lowerThreshold, 1.);

  bufferFast9.addValue(touchRead(sensor[9]));
  ampl[9] = fmap(touchRead(sensor[9]), bufferSlow9.getMin(), bufferSlow9.getMax() + 1, lowerThreshold, 1.);

  bufferFast10.addValue(touchRead(sensor[10]));
  ampl[10] = fmap(touchRead(sensor[10]), bufferSlow10.getMin(), bufferSlow10.getMax() + 1, lowerThreshold, 1.);

  bufferFast11.addValue(touchRead(sensor[11]));
  ampl[11] = fmap(touchRead(sensor[11]), bufferSlow11.getMin(), bufferSlow11.getMax() + 1, lowerThreshold, 1.);

}

void doSensorReadSlow(int mod) {
  bufferSlow0.addValue(bufferFast0.getAverage() + mod);
  bufferSlow1.addValue(bufferFast1.getAverage() + mod);
  bufferSlow2.addValue(bufferFast2.getAverage() + mod);
  bufferSlow3.addValue(bufferFast3.getAverage() + mod);
  bufferSlow4.addValue(bufferFast4.getAverage() + mod);
  bufferSlow5.addValue(bufferFast5.getAverage() + mod);
  bufferSlow6.addValue(bufferFast6.getAverage() + mod);
  bufferSlow7.addValue(bufferFast7.getAverage() + mod);
  bufferSlow8.addValue(bufferFast8.getAverage() + mod);
  bufferSlow9.addValue(bufferFast9.getAverage() + mod);
  bufferSlow10.addValue(bufferFast10.getAverage() + mod);
  bufferSlow11.addValue(bufferFast11.getAverage() + mod);
}

void baseLineCalibration() {
  resetRunningAverages();
  for (int i = 0; i < max(datapointsFast, datapointsSlow); i++) {
    doSensorReadFast();
    doSensorReadSlow(defaultSensorMaxRange);

    delay(1);
  }
  //Serial.println("recalibrated");
}
