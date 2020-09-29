int toneSets = 4;
int toneSet[][11] = {
  {NOTE_C6, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_C4}, //pentatonic C4
  {NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4}, //diatonic C4
  //{NOTE_C5, NOTE_F4, NOTE_E4, NOTE_DS4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_B4, NOTE_GS4, NOTE_CS4, NOTE_AS4}, //chromatic C4
  //{NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_C4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_E4}, //whole tone C4
  //{NOTE_C6, NOTE_B5, NOTE_G5,   NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_DS5, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_E4}, //Raja
  {NOTE_C7, NOTE_A6, NOTE_G6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_D5, NOTE_C5}, //pentatonic C5
  {NOTE_C6, NOTE_G5, NOTE_DS5, NOTE_D5, NOTE_C5, NOTE_GS4, NOTE_G4, NOTE_DS4, NOTE_F4, NOTE_C4, NOTE_G3}, //Ake Bono
};

void startAudio() {
  AudioMemory(100);
  dac1.analogReference(EXTERNAL);

  setTimbre();

  amp1.gain(0);
  amp1sub.gain(0);

  setFrequencies();

  if (digitalRead(encPins[2])) {
    delay(50);
    pinMode(ampPin, INPUT);
    delay(50);
  };
}

void audioUpdate() {
  setAmplitudes();
  setFilters();
}

void setFrequencies() {
  AudioNoInterrupts();
  for (int i = 0; i < TONESAMOUNT; i++) {
    /*
        float targetFreq = (freq[i] * glide + toneSet[abs(encoderState) % toneSets][i] * 2) / (1 + glide);
        //if (freq[i] == targetFreq)freqStable = true;
        freq[i] = targetFreq;
    */
    freq[i] = toneSet[abs(encoderState) % toneSets][i];
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



#define octDivide 2.
  subosc0.frequency(freq[0] / octDivide);
  subosc1.frequency(freq[1] / octDivide);
  subosc2.frequency(freq[2] / octDivide);
  subosc3.frequency(freq[3] / octDivide);
  subosc4.frequency(freq[4] / octDivide);
  subosc5.frequency(freq[5] / octDivide);
  subosc6.frequency(freq[6] / octDivide);
  subosc7.frequency(freq[7] / octDivide);
  subosc8.frequency(freq[8] / octDivide);
  subosc9.frequency(freq[9] / octDivide);
  subosc10.frequency(freq[10] / octDivide);


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

#define reso 1.5
  filter0.resonance(reso);
  filter1.resonance(reso);
  filter2.resonance(reso);
  filter3.resonance(reso);
  filter4.resonance(reso);
  filter5.resonance(reso);
  filter6.resonance(reso);
  filter7.resonance(reso);
  filter8.resonance(reso);
  filter9.resonance(reso);
  filter10.resonance(reso);
#define octaves 1.75
  filter0.octaveControl(octaves);
  filter1.octaveControl(octaves);
  filter2.octaveControl(octaves);
  filter3.octaveControl(octaves);
  filter4.octaveControl(octaves);
  filter5.octaveControl(octaves);
  filter6.octaveControl(octaves);
  filter7.octaveControl(octaves);
  filter8.octaveControl(octaves);
  filter9.octaveControl(octaves);
  filter10.octaveControl(octaves);
  AudioInterrupts();
}

void setAmplitudes() {
  AudioNoInterrupts();
#define ampChangeTime 3
  envelope0.amplitude(oscMaxAmplitude * max(0, ampl[0]), ampChangeTime);
  envelope1.amplitude(oscMaxAmplitude * max(0, ampl[1]), ampChangeTime);
  envelope2.amplitude(oscMaxAmplitude * max(0, ampl[2]), ampChangeTime);
  envelope3.amplitude(oscMaxAmplitude * max(0, ampl[3]), ampChangeTime);
  envelope4.amplitude(oscMaxAmplitude * max(0, ampl[4]), ampChangeTime);
  envelope5.amplitude(oscMaxAmplitude * max(0, ampl[5]), ampChangeTime);
  envelope6.amplitude(oscMaxAmplitude * max(0, ampl[6]), ampChangeTime);
  envelope7.amplitude(oscMaxAmplitude * max(0, ampl[7]), ampChangeTime);
  envelope8.amplitude(oscMaxAmplitude * max(0, ampl[8]), ampChangeTime);
  envelope9.amplitude(oscMaxAmplitude * max(0, ampl[9]), ampChangeTime);
  envelope10.amplitude(oscMaxAmplitude * max(0, ampl[10]), ampChangeTime);
  envelope11.amplitude(oscMaxAmplitude * max(0, ampl[11]), ampChangeTime);

  AudioInterrupts();
}

void setTimbre() {
  AudioNoInterrupts();
#define timbreVariations 3
  if (encClicks % timbreVariations == 1 ) {
    float noteVol = .4;
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
  } else  if (encClicks % timbreVariations == 0 ) {
    float noteVol = .3;
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
  } else if (encClicks % timbreVariations == 2 ) {
    float noteVol = .25;

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
  setFrequencies();
  AudioInterrupts();
}

void setFilters() {
#define filterLowPos 0.
#define filterHighPos 1.
#define filterChangeTime 10
  AudioNoInterrupts();
  filterMod0.amplitude(fmap(amplChange[0], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);
  filterMod1.amplitude(fmap(amplChange[1], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);
  filterMod2.amplitude(fmap(amplChange[2], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);
  filterMod3.amplitude(fmap(amplChange[3], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);
  filterMod4.amplitude(fmap(amplChange[4], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);
  filterMod5.amplitude(fmap(amplChange[5], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);
  filterMod6.amplitude(fmap(amplChange[6], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);
  filterMod7.amplitude(fmap(amplChange[7], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);
  filterMod8.amplitude(fmap(amplChange[8], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);
  filterMod9.amplitude(fmap(amplChange[9], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);
  filterMod10.amplitude(fmap(amplChange[10], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);
  filterMod11.amplitude(fmap(amplChange[11], 0, standardDevRange, filterLowPos, filterHighPos), filterChangeTime);

  AudioInterrupts();
}
