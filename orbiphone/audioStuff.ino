
elapsedMicros audioUpdateTimer;

int toneSet[8][11] = {
  {NOTE_C4, NOTE_A3, NOTE_G3, NOTE_E3, NOTE_D3, NOTE_C3, NOTE_A2, NOTE_G2, NOTE_E2, NOTE_D2, NOTE_C2}, //0= 0 0 0    C
  {NOTE_A2, NOTE_D3, NOTE_FS3, NOTE_A3, NOTE_D4, NOTE_FS4, NOTE_A4, NOTE_D5, NOTE_FS5, NOTE_A5, NOTE_D6}, //1= 1 0 0    D/A
  {NOTE_E2, NOTE_E3, NOTE_A3, NOTE_B3, NOTE_E4, NOTE_A4,   NOTE_B4, NOTE_E5, NOTE_A5, NOTE_B5, NOTE_E6}, //2= 0 1 0    Esus
  {NOTE_G2, NOTE_B3, NOTE_D3, NOTE_G3, NOTE_B4, NOTE_D4, NOTE_G4, NOTE_B5, NOTE_D5, NOTE_G5, NOTE_G6}, //3= 1 1 0    G
  {NOTE_A2, NOTE_A3, NOTE_C3, NOTE_E3, NOTE_A4, NOTE_C4, NOTE_E4, NOTE_A5, NOTE_C5, NOTE_E5, NOTE_A6}, //4= 0 0 1    am
  {NOTE_A2, NOTE_D3, NOTE_F3, NOTE_A3, NOTE_D4, NOTE_F4, NOTE_A4, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_D6}, //5= 1 0 1    dm/A
  {NOTE_E2, NOTE_E3, NOTE_G3, NOTE_B3, NOTE_E4, NOTE_G4, NOTE_B4, NOTE_E5, NOTE_G5, NOTE_B5, NOTE_E6}, //6= 0 1 1    em
  {NOTE_A2, NOTE_A3, NOTE_CS3, NOTE_E3, NOTE_A4, NOTE_CS4, NOTE_E4, NOTE_A5, NOTE_CS5, NOTE_E5, NOTE_A6}  //7= 1 1 1    A
};



void audioUpdate() {
  if (audioUpdateTimer > audioUpdateTime) {
    audioUpdateTimer = 0;

    setFrequencies();
    setAmplitudes();
  }
}

void setFrequencies() {
  for (int i = 0; i < TONESAMOUNT; i++) {
    freq[i] = (freq[i] * glide + toneSet[buttonState[0]][i] * 2) / (1 + glide);

  }

  sine1.frequency(freq[0]);
  sine2.frequency(freq[1]);
  sine3.frequency(freq[2]);
  sine4.frequency(freq[3]);
  sine5.frequency(freq[4]);
  sine6.frequency(freq[5]);
  sine7.frequency(freq[6]);
  sine8.frequency(freq[7]);
  sine9.frequency(freq[8]);
  sine10.frequency(freq[9]);
  sine11.frequency(freq[10]);
}

void setAmplitudes() {


  int maxi[TONESAMOUNT];
  int mini[TONESAMOUNT];
  int total[TONESAMOUNT];

  totalAverage = 0;
  for (int i = 0; i < TONESAMOUNT; i++) {
    readings[i][readIndex] = touchRead(sensor[i]);

    total[i] = 0;
    maxi[i] = 0;
    mini[i] = 32000;//it's unlikely to get higher than this in either 16b or 32b

    for (int j = 0; j < numReadings; j++) {
      total[i] +=  readings[i][j];
      if (readings[i][readIndex] < mini[i])mini[i] = readings[i][j];
      if (readings[i][readIndex] > maxi[i])maxi[i] = readings[i][j];
    }
    average[i] = total[i] / numReadings;
    range[i] = maxi[i] - mini[i];
    ampl[i] = fmap(average[i], lowCal[i], highCal[i], 0, 1); //mapping the value to a 0 - 1 range

    totalAverage += ampl[i];
  }
  totalAverage /= TONESAMOUNT;
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }


  mixer1.gain(0, sineMaxAmplitude * ampl[0]);
  mixer1.gain(1, sineMaxAmplitude * ampl[1]);
  mixer1.gain(2, sineMaxAmplitude * ampl[2]);
  mixer1.gain(3, sineMaxAmplitude * ampl[3]);
  mixer2.gain(0, sineMaxAmplitude * ampl[4]);
  mixer2.gain(1, sineMaxAmplitude * ampl[5]);
  mixer2.gain(2, sineMaxAmplitude * ampl[6]);
  mixer2.gain(3, sineMaxAmplitude * ampl[7]);
  mixer3.gain(0, sineMaxAmplitude * ampl[8]);
  mixer3.gain(1, sineMaxAmplitude * ampl[9]);
  mixer3.gain(2, sineMaxAmplitude * ampl[10]);

}
