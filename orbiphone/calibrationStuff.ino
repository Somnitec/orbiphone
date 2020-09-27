elapsedMillis calibrationUpdateTimer;

elapsedMillis stableAudioTimer;
float previousPeak;


void doSensorReadFast() {
  float yn = 0;
  float xn = 0;
  float xFastVal = 0;

  yn = touchRead(sensor[0]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast0.addValue(yn);          // add y variable to storing array
  xFast0.addValue(xn);          // add x variable to storing array
  xyFast0.addValue(xn * yn); // same for x*y
  x2Fast0.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast0.getAverage();
  slopeFast0 = (xyFast0.getAverage() - (xFastVal * yFast0.getAverage())) / (x2Fast0.getAverage() - (xFastVal * xFastVal));
  ampl[0] = fmap(yFast0.getAverage(), ySlow0.getMin(), ySlow0.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[1]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast1.addValue(yn);          // add y variable to storing array
  xFast1.addValue(xn);          // add x variable to storing array
  xyFast1.addValue(xn * yn); // same for x*y
  x2Fast1.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast1.getAverage();
  slopeFast1 = (xyFast1.getAverage() - (xFastVal * yFast1.getAverage())) / (x2Fast1.getAverage() - (xFastVal * xFastVal));
  ampl[1] = fmap(yFast1.getAverage(), ySlow1.getMin(), ySlow1.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[2]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast2.addValue(yn);          // add y variable to storing array
  xFast2.addValue(xn);          // add x variable to storing array
  xyFast2.addValue(xn * yn); // same for x*y
  x2Fast2.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast2.getAverage();
  slopeFast2 = (xyFast2.getAverage() - (xFastVal * yFast2.getAverage())) / (x2Fast2.getAverage() - (xFastVal * xFastVal));
  ampl[2] = fmap(yFast2.getAverage(), ySlow2.getMin(), ySlow2.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[3]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast3.addValue(yn);          // add y variable to storing array
  xFast3.addValue(xn);          // add x variable to storing array
  xyFast3.addValue(xn * yn); // same for x*y
  x2Fast3.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast3.getAverage();
  slopeFast3 = (xyFast3.getAverage() - (xFastVal * yFast3.getAverage())) / (x2Fast3.getAverage() - (xFastVal * xFastVal));
  ampl[3] = fmap(yFast3.getAverage(), ySlow3.getMin(), ySlow3.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[4]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast4.addValue(yn);          // add y variable to storing array
  xFast4.addValue(xn);          // add x variable to storing array
  xyFast4.addValue(xn * yn); // same for x*y
  x2Fast4.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast4.getAverage();
  slopeFast4 = (xyFast4.getAverage() - (xFastVal * yFast4.getAverage())) / (x2Fast4.getAverage() - (xFastVal * xFastVal));
  ampl[4] = fmap(yFast4.getAverage(), ySlow4.getMin(), ySlow4.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[5]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast5.addValue(yn);          // add y variable to storing array
  xFast5.addValue(xn);          // add x variable to storing array
  xyFast5.addValue(xn * yn); // same for x*y
  x2Fast5.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast5.getAverage();
  slopeFast5 = (xyFast5.getAverage() - (xFastVal * yFast5.getAverage())) / (x2Fast5.getAverage() - (xFastVal * xFastVal));
  ampl[5] = fmap(yFast5.getAverage(), ySlow5.getMin(), ySlow5.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[6]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast6.addValue(yn);          // add y variable to storing array
  xFast6.addValue(xn);          // add x variable to storing array
  xyFast6.addValue(xn * yn); // same for x*y
  x2Fast6.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast6.getAverage();
  slopeFast6 = (xyFast6.getAverage() - (xFastVal * yFast6.getAverage())) / (x2Fast6.getAverage() - (xFastVal * xFastVal));
  ampl[6] = fmap(yFast6.getAverage(), ySlow6.getMin(), ySlow6.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[7]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast7.addValue(yn);          // add y variable to storing array
  xFast7.addValue(xn);          // add x variable to storing array
  xyFast7.addValue(xn * yn); // same for x*y
  x2Fast7.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast7.getAverage();
  slopeFast7 = (xyFast7.getAverage() - (xFastVal * yFast7.getAverage())) / (x2Fast7.getAverage() - (xFastVal * xFastVal));
  ampl[7] = fmap(yFast7.getAverage(), ySlow7.getMin(), ySlow7.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[8]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast8.addValue(yn);          // add y variable to storing array
  xFast8.addValue(xn);          // add x variable to storing array
  xyFast8.addValue(xn * yn); // same for x*y
  x2Fast8.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast8.getAverage();
  slopeFast8 = (xyFast8.getAverage() - (xFastVal * yFast8.getAverage())) / (x2Fast8.getAverage() - (xFastVal * xFastVal));
  ampl[8] = fmap(yFast8.getAverage(), ySlow8.getMin(), ySlow8.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[9]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast9.addValue(yn);          // add y variable to storing array
  xFast9.addValue(xn);          // add x variable to storing array
  xyFast9.addValue(xn * yn); // same for x*y
  x2Fast9.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast9.getAverage();
  slopeFast9 = (xyFast9.getAverage() - (xFastVal * yFast9.getAverage())) / (x2Fast9.getAverage() - (xFastVal * xFastVal));
  ampl[9] = fmap(yFast9.getAverage(), ySlow9.getMin(), ySlow9.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[10]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast10.addValue(yn);          // add y variable to storing array
  xFast10.addValue(xn);          // add x variable to storing array
  xyFast10.addValue(xn * yn); // same for x*y
  x2Fast10.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast10.getAverage();
  slopeFast10 = (xyFast10.getAverage() - (xFastVal * yFast10.getAverage())) / (x2Fast10.getAverage() - (xFastVal * xFastVal));
  ampl[10] = fmap(yFast10.getAverage(), ySlow10.getMin(), ySlow10.getMax() + 1, 0., 1.);

 }

void doSensorReadSlow(float mod) {

  float yn = 0;
  float xn = 0;
  float xvalSlow = 0;

  yn = mod + touchRead( sensor[0]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow0.addValue(yn);          // add y variable to storing array
  xSlow0.addValue(xn);          // add x variable to storing array
  xySlow0.addValue(xn * yn); // same for x*y
  x2Slow0.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow0.getAverage();
  slopeSlow0 = (xySlow0.getAverage() - (xvalSlow * ySlow0.getAverage())) / (x2Slow0.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[1]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow1.addValue(yn);          // add y variable to storing array
  xSlow1.addValue(xn);          // add x variable to storing array
  xySlow1.addValue(xn * yn); // same for x*y
  x2Slow1.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow1.getAverage();
  slopeSlow1 = (xySlow1.getAverage() - (xvalSlow * ySlow1.getAverage())) / (x2Slow1.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[2]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow2.addValue(yn);          // add y variable to storing array
  xSlow2.addValue(xn);          // add x variable to storing array
  xySlow2.addValue(xn * yn); // same for x*y
  x2Slow2.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow2.getAverage();
  slopeSlow2 = (xySlow2.getAverage() - (xvalSlow * ySlow2.getAverage())) / (x2Slow2.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[3]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow3.addValue(yn);          // add y variable to storing array
  xSlow3.addValue(xn);          // add x variable to storing array
  xySlow3.addValue(xn * yn); // same for x*y
  x2Slow3.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow3.getAverage();
  slopeSlow3 = (xySlow3.getAverage() - (xvalSlow * ySlow3.getAverage())) / (x2Slow3.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[4]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow4.addValue(yn);          // add y variable to storing array
  xSlow4.addValue(xn);          // add x variable to storing array
  xySlow4.addValue(xn * yn); // same for x*y
  x2Slow4.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow4.getAverage();
  slopeSlow4 = (xySlow4.getAverage() - (xvalSlow * ySlow4.getAverage())) / (x2Slow4.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[5]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow5.addValue(yn);          // add y variable to storing array
  xSlow5.addValue(xn);          // add x variable to storing array
  xySlow5.addValue(xn * yn); // same for x*y
  x2Slow5.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow5.getAverage();
  slopeSlow5 = (xySlow5.getAverage() - (xvalSlow * ySlow5.getAverage())) / (x2Slow5.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[6]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow6.addValue(yn);          // add y variable to storing array
  xSlow6.addValue(xn);          // add x variable to storing array
  xySlow6.addValue(xn * yn); // same for x*y
  x2Slow6.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow6.getAverage();
  slopeSlow6 = (xySlow6.getAverage() - (xvalSlow * ySlow6.getAverage())) / (x2Slow6.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[7]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow7.addValue(yn);          // add y variable to storing array
  xSlow7.addValue(xn);          // add x variable to storing array
  xySlow7.addValue(xn * yn); // same for x*y
  x2Slow7.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow7.getAverage();
  slopeSlow7 = (xySlow7.getAverage() - (xvalSlow * ySlow7.getAverage())) / (x2Slow7.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[8]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow8.addValue(yn);          // add y variable to storing array
  xSlow8.addValue(xn);          // add x variable to storing array
  xySlow8.addValue(xn * yn); // same for x*y
  x2Slow8.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow8.getAverage();
  slopeSlow8 = (xySlow8.getAverage() - (xvalSlow * ySlow8.getAverage())) / (x2Slow8.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[9]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow9.addValue(yn);          // add y variable to storing array
  xSlow9.addValue(xn);          // add x variable to storing array
  xySlow9.addValue(xn * yn); // same for x*y
  x2Slow9.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow9.getAverage();
  slopeSlow9 = (xySlow9.getAverage() - (xvalSlow * ySlow9.getAverage())) / (x2Slow9.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[10]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow10.addValue(yn);          // add y variable to storing array
  xSlow10.addValue(xn);          // add x variable to storing array
  xySlow10.addValue(xn * yn); // same for x*y
  x2Slow10.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow10.getAverage();
  slopeSlow10 = (xySlow10.getAverage() - (xvalSlow * ySlow10.getAverage())) / (x2Slow10.getAverage() - (xvalSlow * xvalSlow));


}

void baselineCalibration() {
   // explicitly start clean
  xFast0.clear();
  yFast0.clear();
  xyFast0.clear();
  x2Fast0.clear();
  xSlow0.clear();
  ySlow0.clear();
  xySlow0.clear();
  x2Slow0.clear();

  xFast1.clear();
  yFast1.clear();
  xyFast1.clear();
  x2Fast1.clear();
  xSlow1.clear();
  ySlow1.clear();
  xySlow1.clear();
  x2Slow1.clear();

  xFast2.clear();
  yFast2.clear();
  xyFast2.clear();
  x2Fast2.clear();
  xSlow2.clear();
  ySlow2.clear();
  xySlow2.clear();
  x2Slow2.clear();

  xFast3.clear();
  yFast3.clear();
  xyFast3.clear();
  x2Fast3.clear();
  xSlow3.clear();
  ySlow3.clear();
  xySlow3.clear();
  x2Slow3.clear();

  xFast4.clear();
  yFast4.clear();
  xyFast4.clear();
  x2Fast4.clear();
  xSlow4.clear();
  ySlow4.clear();
  xySlow4.clear();
  x2Slow4.clear();

  xFast5.clear();
  yFast5.clear();
  xyFast5.clear();
  x2Fast5.clear();
  xSlow5.clear();
  ySlow5.clear();
  xySlow5.clear();
  x2Slow5.clear();

  xFast6.clear();
  yFast6.clear();
  xyFast6.clear();
  x2Fast6.clear();
  xSlow6.clear();
  ySlow6.clear();
  xySlow6.clear();
  x2Slow6.clear();

  xFast7.clear();
  yFast7.clear();
  xyFast7.clear();
  x2Fast7.clear();
  xSlow7.clear();
  ySlow7.clear();
  xySlow7.clear();
  x2Slow7.clear();

  xFast8.clear();
  yFast8.clear();
  xyFast8.clear();
  x2Fast8.clear();
  xSlow8.clear();
  ySlow8.clear();
  xySlow8.clear();
  x2Slow8.clear();

  xFast9.clear();
  yFast9.clear();
  xyFast9.clear();
  x2Fast9.clear();
  xSlow9.clear();
  ySlow9.clear();
  xySlow9.clear();
  x2Slow9.clear();

  xFast10.clear();
  yFast10.clear();
  xyFast10.clear();
  x2Fast10.clear();
  xSlow10.clear();
  ySlow10.clear();
  xySlow10.clear();
  x2Slow10.clear();

  xFast11.clear();
  yFast11.clear();
  xyFast11.clear();
  x2Fast11.clear();
  xSlow11.clear();
  ySlow11.clear();
  xySlow11.clear();
  x2Slow11.clear();
  
  for (int i = 0; i < max(datapointsFast,datapointsSlow); i++) {
    doSensorReadFast();
    doSensorReadSlow(maxRange);

    delay(1);
  }
  Serial.println("recalibrated");
}
