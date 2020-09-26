elapsedMillis buttonUpdateTimer;

long oldPosition  = -999;
void buttonUpdate() {
  if (buttonUpdateTimer > buttonUpdateTime) {
    buttonUpdateTimer = 0;
    amp1.gain(fmap(analogRead(volumePin), 1023, 0, 0.0, 1.0));

    encButton.update();
    if (encButton.fell()) {
      encClicks++;


      if (abs(encClicks) % 4 == 0 ) {
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
      } else if ((abs(encClicks)) % 4 == 1 ) {
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
      } else if ((abs(encClicks) ) % 4 == 2 ) {
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
      } else if ((abs(encClicks) ) % 4 == 3 ) {
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



    long newPosition = encoder.read();
    if (newPosition != oldPosition) {
      oldPosition = newPosition;


    }

    //
    //    button1.update();
    //    button2.update();
    //    button3.update();
    //    if (button1.fell()) {
    //      buttonState[1] = !buttonState[1];
    //      usbMIDI.sendControlChange(7, buttonState[1] * 127, 0);
    //      buttonStateChanged();
    //    }
    //    if (button2.fell()) {
    //      buttonState[2] = !buttonState[2];
    //      usbMIDI.sendControlChange(8, buttonState[2] * 127, 0);
    //      buttonStateChanged();
    //    }
    //    if (button3.fell()) {
    //      buttonState[3] = !buttonState[3];
    //      usbMIDI.sendControlChange(9, buttonState[3] * 127, 0);
    //      buttonStateChanged();
    //    }



  }
}

void buttonStateChanged() {
  buttonState[0] = 0;

  if (!buttonState[1])buttonState[0] += 1;
  if (!buttonState[2])buttonState[0] += 2;
  if (!buttonState[3])buttonState[0] += 4;
  usbMIDI.sendControlChange(10, buttonState[0], 0);

}
