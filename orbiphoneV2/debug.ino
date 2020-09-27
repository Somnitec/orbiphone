void debugUpdate() {

  if (Serial.available()) {
    int serialInput = Serial.read();
    if (serialInput == '1')baseLineCalibration();
  }

  if (1) {//just showing sensor 4
    Serial.print("\tsraw4:");
    Serial.print( touchRead(sensor[4]));
    Serial.print("\tfast4:");
    Serial.print(bufferFast4.getAverage());
    Serial.print("\tslow4:");
    Serial.print( bufferSlow4.getAverage());
    Serial.print("\tslowMin4:");
    Serial.print( bufferFast4.getMin());
    Serial.print("\tslowMax4:");
    Serial.print( bufferSlow4.getMax());
    Serial.print("\tampl4:");
    Serial.print( ampl[4]);
    Serial.print("\tStDevFast4:");
    Serial.print(bufferFast4.getStandardDeviation());
    Serial.print("\tStDevSlow4:");
    Serial.print(bufferSlow4.getStandardDeviation());
  }
  if (false) {//showing all avg
    Serial.print("\tfast0:"); Serial.print(bufferFast0.getAverage());
    Serial.print("\tfast1:"); Serial.print(bufferFast1.getAverage());
    Serial.print("\tfast2:"); Serial.print(bufferFast2.getAverage());
    Serial.print("\tfast3:"); Serial.print(bufferFast3.getAverage());
    Serial.print("\tfast4:"); Serial.print(bufferFast4.getAverage());
    Serial.print("\tfast5:"); Serial.print(bufferFast5.getAverage());
    Serial.print("\tfast6:"); Serial.print(bufferFast6.getAverage());
    Serial.print("\tfast7:"); Serial.print(bufferFast7.getAverage());
    Serial.print("\tfast8:"); Serial.print(bufferFast8.getAverage());
    Serial.print("\tfast9:"); Serial.print(bufferFast9.getAverage());
    Serial.print("\tfast10:"); Serial.print(bufferFast10.getAverage());
    //Serial.print("\tfast11:"); Serial.print(bufferFast11.getAverage());

  }
  if (false) {//showing all ampl
    Serial.print("\tampl0:"); Serial.print(ampl[0]);
    Serial.print("\tampl1:"); Serial.print(ampl[1]);
    Serial.print("\tampl2:"); Serial.print(ampl[2]);
    Serial.print("\tampl3:"); Serial.print(ampl[3]);
    Serial.print("\tampl4:"); Serial.print(ampl[4]);
    Serial.print("\tampl5:"); Serial.print(ampl[5]);
    Serial.print("\tampl6:"); Serial.print(ampl[6]);
    Serial.print("\tampl7:"); Serial.print(ampl[7]);
    Serial.print("\tampl8:"); Serial.print(ampl[8]);
    Serial.print("\tampl9:"); Serial.print(ampl[9]);
    Serial.print("\tampl10:"); Serial.print(ampl[10]);
    //Serial.print("\tampl11:"); Serial.print(ampl[11]);

  }
  Serial.println();
}
