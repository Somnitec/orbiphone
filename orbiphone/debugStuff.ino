elapsedMillis debugUpdateTimer;

void debugUpdate() {


  if (Serial.available()) {

    int serialInput = Serial.read();
    if (serialInput == '1')baselineCalibration();
  }


  Serial.println();
  Serial.println();
  Serial.print("\tscaled0:");
  Serial.print( ampl[0]);
  Serial.print("\tscaled1:");
  Serial.print( ampl[1]);
  Serial.print("\tscaled2:");
  Serial.print( ampl[2]);
  Serial.print("\tscaled3:");
  Serial.print( ampl[3]);
  Serial.print("\tscaled4:");
  Serial.print( ampl[4]);
  Serial.print("\tscaled5:");
  Serial.print( ampl[5]);
  Serial.print("\tscaled6:");
  Serial.print( ampl[6]);
  Serial.print("\tscaled7:");
  Serial.print( ampl[7]);
  Serial.print("\tscaled8:");
  Serial.print( ampl[8]);
  Serial.print("\tscaled9:");
  Serial.print( ampl[9]);
  Serial.print("\tscaled10:");
  Serial.print( ampl[10]);
  //button status

  //    Serial.print("totalAverage:");
  //    Serial.print(totalAverage);
  //    Serial.print('\t');
  //        Serial.print("avgRange:");
  //        int avgRange = 0;
  //        for (int i = 0; i < TONESAMOUNT; i++) {
  //          avgRange += range[i];
  //        }
  //        avgRange /= TONESAMOUNT;
  //        Serial.print(avgRange);
  //        Serial.print('\t');
  //        Serial.print("stableTimer:");
  //        Serial.print(stableTimer);
  //
  //        Serial.print('\t');
  //        Serial.print("stableAudioTimer:");
  //        Serial.print(stableAudioTimer);
  //
  //    Serial.print('\t');
  //    Serial.print("sineMaxAmplitude:");
  //    Serial.print(sineMaxAmplitude);
  //    Serial.println();
  //
  //    //raw values
  //    for (int i = 0; i < TONESAMOUNT; i++) {
  //      Serial.print("reading");
  //      Serial.print(i);
  //      Serial.print(':');
  //      Serial.print(readings[i][readIndex-1]);
  //      Serial.print('\t');
  //    }
  //
  //    //calibration value
  //    for (int i = 0; i < TONESAMOUNT; i++) {
  //      Serial.print("lowcal");
  //      Serial.print(i);
  //      Serial.print(':');
  //      Serial.print(lowCal[i]);
  //      Serial.print('\t');
  //    }

  //for doing an individual reading
  //  int i = 10;
  //  Serial.print("reading");
  //  Serial.print(i);
  //  Serial.print(':');
  //  Serial.print(readings[i][readIndex]);
  //  Serial.print('\t');
  //
  //  Serial.print("average");
  //  Serial.print(i);
  //  Serial.print(':');
  //  Serial.print(average[i]);
  //  Serial.print('\t');
  //
  //  Serial.print("lowCal");
  //  Serial.print(i);
  //  Serial.print(':');
  //  Serial.print(lowCal[i]);
  //  Serial.print('\t');
  //
  //  Serial.print("highCal");
  //  Serial.print(i);
  //  Serial.print(':');
  //  Serial.print(highCal[i]);
  //  Serial.print('\t');
  //
  //    Serial.println();
  //    //oscillator amplitudes
  //    for (int i = 0; i < TONESAMOUNT; i++) {
  //      Serial.print("ampl");
  //      Serial.print(i);
  //      Serial.print(':');
  //      Serial.print(ampl[i]);
  //      Serial.print('\t');
  //    }
  //    Serial.println();
  //    //range of sensor array
  //    for (int i = 0; i < TONESAMOUNT; i++) {
  //      Serial.print("range");
  //      Serial.print(i);
  //      Serial.print(':');
  //      Serial.print(range[i]);
  //      Serial.print('\t');
  //    }
  //    Serial.println();
  //
  //
  //    //oscillator freqs
  //    for (int i = 0; i < TONESAMOUNT; i++) {
  //      Serial.print("freq");
  //      Serial.print(i);
  //      Serial.print(':');
  //      Serial.print(freq[i]);
  //      Serial.print('\t');
  //    }
  //    Serial.println();
  //
  //    //oscillator desired freqs
  //    for (int i = 0; i < TONESAMOUNT; i++) {
  //      Serial.print("targetfreq");
  //      Serial.print(i);
  //      Serial.print(':');
  //      Serial.print(toneSet[buttonState[0]][i]);
  //      Serial.print('\t');
  //    }
  //    Serial.println();
  //
  //    Serial.print("RMS:");
  //    Serial.print(rms1.read());
  //    Serial.print('\t');
  //    Serial.print("PEAK:");
  //    Serial.print(peak1.read());
  //    Serial.print('\t');
  //    Serial.print("Proc:");
  //    Serial.print(AudioProcessorUsage());
  //    Serial.print('\t');
  //    Serial.print("ProcMax:");
  //    Serial.print(AudioProcessorUsageMax());
  //    Serial.print('\t');
  //    Serial.print("Mem:");
  //    Serial.print(AudioMemoryUsage());
  //    Serial.print('\t');
  //    Serial.print("MemMax:");
  //    Serial.print(AudioMemoryUsageMax());



}
