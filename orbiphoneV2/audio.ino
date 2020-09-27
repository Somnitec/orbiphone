int toneSets = 4;
int toneSet[][11] = {
  {NOTE_C5, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_G3, NOTE_E3, NOTE_D3, NOTE_C3}, //pentatonic C3
  {NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C3}, //diatonic C3
  {NOTE_C4, NOTE_F3, NOTE_E3, NOTE_DS3, NOTE_A3, NOTE_G3, NOTE_D3, NOTE_B3, NOTE_GS3, NOTE_CS3, NOTE_AS3}, //chromatic C3
  {NOTE_C5, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_C3, NOTE_AS3, NOTE_GS3, NOTE_FS3, NOTE_E3}, //whole tone C3
};

void startAudio() {
  AudioMemory(100);
  dac1.analogReference(EXTERNAL);
  //setting all the oscillators off
  mixer1.gain(0, 0);
  mixer1.gain(1, 0);
  mixer1.gain(2, 0);
  mixer1.gain(3, 0);
  mixer2.gain(0, 0);
  mixer2.gain(1, 0);
  mixer2.gain(2, 0);
  mixer2.gain(3, 0);
  mixer3.gain(0, 0);
  mixer3.gain(1, 0);
  mixer3.gain(2, 0);
  mixer3.gain(3, 0);

  mixer1sub.gain(0, 0);
  mixer1sub.gain(1, 0);
  mixer1sub.gain(2, 0);
  mixer1sub.gain(3, 0);
  mixer2sub.gain(0, 0);
  mixer2sub.gain(1, 0);
  mixer2sub.gain(2, 0);
  mixer2sub.gain(3, 0);
  mixer3sub.gain(0, 0);
  mixer3sub.gain(1, 0);
  mixer3sub.gain(2, 0);
  mixer3sub.gain(3, 0);


  float noteVol = .4;//a specific value to equalize levels between the oscilator types
  osc0.begin(noteVol, 220, WAVEFORM_SQUARE);
  osc1.begin(noteVol, 220, WAVEFORM_SQUARE);
  osc2.begin(noteVol, 220, WAVEFORM_SQUARE);
  osc3.begin(noteVol, 220, WAVEFORM_SQUARE);
  osc4.begin(noteVol, 220, WAVEFORM_SQUARE);
  osc5.begin(noteVol, 220, WAVEFORM_SQUARE);
  osc6.begin(noteVol, 220, WAVEFORM_SQUARE);
  osc7.begin(noteVol, 220, WAVEFORM_SQUARE);
  osc8.begin(noteVol, 220, WAVEFORM_SQUARE);
  osc9.begin(noteVol, 220, WAVEFORM_SQUARE);
  osc10.begin(noteVol, 220, WAVEFORM_SQUARE);

  amp1.gain(0);
  amp1sub.gain(0);

  setFrequencies();
  setAmplitudes();
}

void audioUpdate() {


  setFrequencies();
  setAmplitudes();


}

void setFrequencies() {
  for (int i = 0; i < TONESAMOUNT; i++) {
    //freq[i] = (freq[i] * glide + toneSet[(abs(encoder.read()) / 4) % toneSets][i] * 2) / (1 + glide);
    int targetFreq = (freq[i] * glide + toneSet[abs(encoderState)%toneSets][i] * 2) / (1 + glide);
    if (freq[i] == targetFreq)freqStable = true;
    freq[i] = targetFreq;
  }

  //if (!freqStable) {
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
  //}
  
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

  mixer1.gain(0, oscMaxAmplitude * max(0, ampl[0]));
  mixer1.gain(1, oscMaxAmplitude * max(0, ampl[1]));
  mixer1.gain(2, oscMaxAmplitude * max(0, ampl[2]));
  mixer1.gain(3, oscMaxAmplitude * max(0, ampl[3]));
  mixer2.gain(0, oscMaxAmplitude * max(0, ampl[4]));
  mixer2.gain(1, oscMaxAmplitude * max(0, ampl[5]));
  mixer2.gain(2, oscMaxAmplitude * max(0, ampl[6]));
  mixer2.gain(3, oscMaxAmplitude * max(0, ampl[7]));
  mixer3.gain(0, oscMaxAmplitude * max(0, ampl[8]));
  mixer3.gain(1, oscMaxAmplitude * max(0, ampl[9]));
  mixer3.gain(2, oscMaxAmplitude * max(0, ampl[10]));

  mixer1sub.gain(0, oscMaxAmplitude * max(0, ampl[0]));
  mixer1sub.gain(1, oscMaxAmplitude * max(0, ampl[1]));
  mixer1sub.gain(2, oscMaxAmplitude * max(0, ampl[2]));
  mixer1sub.gain(3, oscMaxAmplitude * max(0, ampl[3]));
  mixer2sub.gain(0, oscMaxAmplitude * max(0, ampl[4]));
  mixer2sub.gain(1, oscMaxAmplitude * max(0, ampl[5]));
  mixer2sub.gain(2, oscMaxAmplitude * max(0, ampl[6]));
  mixer2sub.gain(3, oscMaxAmplitude * max(0, ampl[7]));
  mixer3sub.gain(0, oscMaxAmplitude * max(0, ampl[8]));
  mixer3sub.gain(1, oscMaxAmplitude * max(0, ampl[9]));
  mixer3sub.gain(2, oscMaxAmplitude * max(0, ampl[10]));

}

void setTimbre() {
  if (encClicks % 4 == 0 ) {
    float noteVol = 0.4;
    osc0.begin(noteVol, 220, WAVEFORM_SINE);
    osc1.begin(noteVol, 220, WAVEFORM_SINE);
    osc2.begin(noteVol, 220, WAVEFORM_SINE);
    osc3.begin(noteVol, 220, WAVEFORM_SINE);
    osc4.begin(noteVol, 220, WAVEFORM_SINE);
    osc5.begin(noteVol, 220, WAVEFORM_SINE);
    osc6.begin(noteVol, 220, WAVEFORM_SINE);
    osc7.begin(noteVol, 220, WAVEFORM_SINE);
    osc8.begin(noteVol, 220, WAVEFORM_SINE);
    osc9.begin(noteVol, 220, WAVEFORM_SINE);
    osc10.begin(noteVol, 220, WAVEFORM_SINE);
  } else if (encClicks % 4 == 1 ) {
    float noteVol = 0.3;
    osc0.begin(noteVol, 220, WAVEFORM_TRIANGLE);
    osc1.begin(noteVol, 220, WAVEFORM_TRIANGLE);
    osc2.begin(noteVol, 220, WAVEFORM_TRIANGLE);
    osc3.begin(noteVol, 220, WAVEFORM_TRIANGLE);
    osc4.begin(noteVol, 220, WAVEFORM_TRIANGLE);
    osc5.begin(noteVol, 220, WAVEFORM_TRIANGLE);
    osc6.begin(noteVol, 220, WAVEFORM_TRIANGLE);
    osc7.begin(noteVol, 220, WAVEFORM_TRIANGLE);
    osc8.begin(noteVol, 220, WAVEFORM_TRIANGLE);
    osc9.begin(noteVol, 220, WAVEFORM_TRIANGLE);
    osc10.begin(noteVol, 220, WAVEFORM_TRIANGLE);
  } else if (encClicks % 4 == 2 ) {
    float noteVol = 0.2;
    osc0.begin(noteVol, 220, WAVEFORM_SQUARE);
    osc1.begin(noteVol, 220, WAVEFORM_SQUARE);
    osc2.begin(noteVol, 220, WAVEFORM_SQUARE);
    osc3.begin(noteVol, 220, WAVEFORM_SQUARE);
    osc4.begin(noteVol, 220, WAVEFORM_SQUARE);
    osc5.begin(noteVol, 220, WAVEFORM_SQUARE);
    osc6.begin(noteVol, 220, WAVEFORM_SQUARE);
    osc7.begin(noteVol, 220, WAVEFORM_SQUARE);
    osc8.begin(noteVol, 220, WAVEFORM_SQUARE);
    osc9.begin(noteVol, 220, WAVEFORM_SQUARE);
    osc10.begin(noteVol, 220, WAVEFORM_SQUARE);
  } else if (encClicks % 4 == 3 ) {
    float noteVol = 0.2;
    osc0.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
    osc1.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
    osc2.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
    osc3.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
    osc4.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
    osc5.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
    osc6.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
    osc7.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
    osc8.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
    osc9.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
    osc10.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
  }
}
