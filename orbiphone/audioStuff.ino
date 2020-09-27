
elapsedMicros audioUpdateTimer;

int toneSets = 4;
int toneSet[][11] = {
  {NOTE_C5, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_G3, NOTE_E3, NOTE_D3, NOTE_C3}, //pentatonic C3
  {NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C3}, //diatonic C3
  {NOTE_C4, NOTE_F3, NOTE_E3, NOTE_DS3, NOTE_A3, NOTE_G3, NOTE_D3, NOTE_B3, NOTE_GS3, NOTE_CS3, NOTE_AS3}, //chromatic C3
  {NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_C3, NOTE_AS3, NOTE_GS3, NOTE_FS3, NOTE_E3}, //whole tone C3
};



void audioUpdate() {


  setFrequencies();
  setAmplitudes();

}

void setFrequencies() {
  for (int i = 0; i < TONESAMOUNT; i++) {
    freq[i] = (freq[i] * glide + toneSet[(abs(encoder.read()) / 4) % toneSets][i] * 2) / (1 + glide);
  }

  osc0.frequency(freq[0]);
  osc1.frequency(freq[1]);
  osc2.frequency(freq[2]);
  osc3.frequency(freq[3]);
  osc4.frequency(freq[4]);
  osc5.frequency(freq[5]);
  osc6.frequency(freq[6]);
  osc7.frequency(freq[7]);
  osc8.frequency(freq[8]);
  osc9.frequency(freq[9]);
  osc10.frequency(freq[10]);

  filter0.frequency(freq[0]);
  filter1.frequency(freq[1]);
  filter2.frequency(freq[2]);
  filter3.frequency(freq[3]);
  filter4.frequency(freq[4]);
  filter5.frequency(freq[5]);
  filter6.frequency(freq[6]);
  filter7.frequency(freq[7]);
  filter8.frequency(freq[8]);
  filter9.frequency(freq[9]);
  filter10.frequency(freq[10]);

  subosc0.frequency(freq[0] / 2);
  subosc1.frequency(freq[1] / 2);
  subosc2.frequency(freq[2] / 2);
  subosc3.frequency(freq[3] / 2);
  subosc4.frequency(freq[4] / 2);
  subosc5.frequency(freq[5] / 2);
  subosc6.frequency(freq[6] / 2);
  subosc7.frequency(freq[7] / 2);
  subosc8.frequency(freq[8] / 2);
  subosc9.frequency(freq[9] / 2);
  subosc10.frequency(freq[10] / 2);
}

void setAmplitudes() {

  /*
    //int maxi[TONESAMOUNT];
    //int mini[TONESAMOUNT];
    long total[TONESAMOUNT];

    totalAverage = 0;
    for (int i = 0; i < TONESAMOUNT; i++) {
      readings[i][readIndex] = touchRead(sensor[i]);

      total[i] = 0;
      //maxi[i] = 0;
      //mini[i] = 32000;//it's unlikely to get higher than this in either 16b or 32b

      for (int j = 0; j < numReadings; j++) {
        total[i] +=  readings[i][j];
        //if (readings[i][readIndex] < mini[i])mini[i] = readings[i][j];
        //if (readings[i][readIndex] > maxi[i])maxi[i] = readings[i][j];
      }
      average[i] = total[i] / numReadings;
      //range[i] = maxi[i] - mini[i];
      ampl[i] = fmap(average[i], lowCal[i], highCal[i], 0, 1); //mapping the value to a 0 - 1 range

      totalAverage += ampl[i];
    }
    totalAverage /= TONESAMOUNT;
    readIndex = readIndex + 1; //readIndex + 1 % numReadings ???
    if (readIndex >= numReadings) {
      readIndex = 0;
    }

  */
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

  mixer1sub.gain(0, sineMaxAmplitude * ampl[0]);
  mixer1sub.gain(1, sineMaxAmplitude * ampl[1]);
  mixer1sub.gain(2, sineMaxAmplitude * ampl[2]);
  mixer1sub.gain(3, sineMaxAmplitude * ampl[3]);
  mixer2sub.gain(0, sineMaxAmplitude * ampl[4]);
  mixer2sub.gain(1, sineMaxAmplitude * ampl[5]);
  mixer2sub.gain(2, sineMaxAmplitude * ampl[6]);
  mixer2sub.gain(3, sineMaxAmplitude * ampl[7]);
  mixer3sub.gain(0, sineMaxAmplitude * ampl[8]);
  mixer3sub.gain(1, sineMaxAmplitude * ampl[9]);
  mixer3sub.gain(2, sineMaxAmplitude * ampl[10]);

}
