elapsedMillis debugUpdateTimer;

void debugUpdate() {
  if (debugUpdateTimer > debugUpdateTime) {
    debugUpdateTimer = 0;

    if (Serial.available()) {

      int serialInput = Serial.read();
      if (serialInput == '1')baselineCalibration();
    }


    Serial.println();

    //button status
    Serial.print(buttonState[0]);
    Serial.print('\t');
    Serial.print(buttonState[1]);
    Serial.print('\t');
    Serial.print(buttonState[2]);
    Serial.print('\t');
    Serial.print(buttonState[3]);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print(totalAverage);
    Serial.print('\t');
    Serial.print('\t');
    int avgRange = 0;
    for (int i = 0; i < TONESAMOUNT; i++) {
      avgRange += range[i];
    }
    avgRange /= TONESAMOUNT;
    Serial.print(avgRange);
    Serial.print('\t');
    Serial.print('\t');
    Serial.print(stableTimer);

    Serial.print('\t');
    Serial.print('\t');
    Serial.print(stableAudioTimer);

    Serial.print('\t');
    Serial.print('\t');
    Serial.print(sineMaxAmplitude);
    Serial.println();

  //raw values
    for (int i = 0; i < TONESAMOUNT; i++) {
      Serial.print(readings[i][readIndex]);
      Serial.print('\t');
    }
    
    Serial.println();
    //oscillator amplitudes
    for (int i = 0; i < TONESAMOUNT; i++) {
      Serial.print(ampl[i]);
      Serial.print('\t');
    }
    Serial.println();
    //range of sensor array
    for (int i = 0; i < TONESAMOUNT; i++) {
      Serial.print(range[i]);
      Serial.print('\t');
    }
    Serial.println();


//oscillator freqs
    for (int i = 0; i < TONESAMOUNT; i++) {
      Serial.print(freq[i]);
      Serial.print('\t');
    }
    Serial.println();

    //oscillator desired freqs
    for (int i = 0; i < TONESAMOUNT; i++) {
      Serial.print(toneSet[buttonState[0]][i]);
      Serial.print('\t');
    }
    Serial.println();
    
    Serial.print("RMS = ");
    Serial.print(rms1.read());
    Serial.print('\t');
    Serial.print(" PEAK = ");
    Serial.print(peak1.read());
    Serial.print('\t');
    Serial.print(" Proc = ");
    Serial.print(AudioProcessorUsage());
    Serial.print(" (");
    Serial.print(AudioProcessorUsageMax());
    Serial.print("),  Mem = ");
    Serial.print(AudioMemoryUsage());
    Serial.print(" (");
    Serial.print(AudioMemoryUsageMax());
    Serial.print(")");

  }
}
