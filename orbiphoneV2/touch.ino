void doSensorReadFast() {

  bufferFast0.addValue(touchRead(sensor[0]));
  ampl[0] = fmap(touchRead(sensor[0]), bufferSlow0.getMin(), bufferSlow0.getMax() + 1, 0., 1.);

  bufferFast1.addValue(sensor[1]);
  ampl[1] = fmap(touchRead(sensor[1]), bufferSlow1.getMin(), bufferSlow1.getMax() + 1, 0., 1.);

  bufferFast2.addValue(sensor[2]);
  ampl[2] = fmap(touchRead(sensor[2]), bufferSlow2.getMin(), bufferSlow2.getMax() + 1, 0., 1.);

  bufferFast3.addValue(sensor[3]);
  ampl[3] = fmap(touchRead(sensor[3]), bufferSlow3.getMin(), bufferSlow3.getMax() + 1, 0., 1.);

  bufferFast4.addValue(sensor[4]);
  ampl[4] = fmap(touchRead(sensor[4]), bufferSlow4.getMin(), bufferSlow4.getMax() + 1, 0., 1.);

  bufferFast5.addValue(sensor[5]);
  ampl[5] = fmap(touchRead(sensor[5]), bufferSlow5.getMin(), bufferSlow5.getMax() + 1, 0., 1.);

  bufferFast6.addValue(sensor[6]);
  ampl[6] = fmap(touchRead(sensor[6]), bufferSlow6.getMin(), bufferSlow6.getMax() + 1, 0., 1.);

  bufferFast7.addValue(sensor[7]);
  ampl[7] = fmap(touchRead(sensor[7]), bufferSlow7.getMin(), bufferSlow7.getMax() + 1, 0., 1.);

  bufferFast8.addValue(sensor[8]);
  ampl[8] = fmap(touchRead(sensor[8]), bufferSlow8.getMin(), bufferSlow8.getMax() + 1, 0., 1.);

  bufferFast9.addValue(sensor[9]);
  ampl[9] = fmap(touchRead(sensor[9]), bufferSlow9.getMin(), bufferSlow9.getMax() + 1, 0., 1.);

  bufferFast10.addValue(sensor[10]);
  ampl[10] = fmap(touchRead(sensor[10]), bufferSlow10.getMin(), bufferSlow10.getMax() + 1, 0., 1.);

  bufferFast11.addValue(sensor[11]);
  ampl[11] = fmap(touchRead(sensor[11]), bufferSlow11.getMin(), bufferSlow11.getMax() + 1, 0., 1.);

}

void doSensorReadSlow() {
  bufferSlow0.addValue(bufferFast0.getAverage());
  bufferSlow1.addValue(bufferFast1.getAverage());
  bufferSlow2.addValue(bufferFast2.getAverage());
  bufferSlow3.addValue(bufferFast3.getAverage());
  bufferSlow4.addValue(bufferFast4.getAverage());
  bufferSlow5.addValue(bufferFast5.getAverage());
  bufferSlow6.addValue(bufferFast6.getAverage());
  bufferSlow7.addValue(bufferFast7.getAverage());
  bufferSlow8.addValue(bufferFast8.getAverage());
  bufferSlow9.addValue(bufferFast9.getAverage());
  bufferSlow10.addValue(bufferFast10.getAverage());
  bufferSlow11.addValue(bufferFast11.getAverage());
}
