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
      sine1.begin(noteVol, 220, WAVEFORM_SINE);
        sine2.begin(noteVol, 220, WAVEFORM_SINE);
        sine3.begin(noteVol, 220, WAVEFORM_SINE);
        sine4.begin(noteVol, 220, WAVEFORM_SINE);
        sine5.begin(noteVol, 220, WAVEFORM_SINE);
        sine6.begin(noteVol, 220, WAVEFORM_SINE);
        sine7.begin(noteVol, 220, WAVEFORM_SINE);
        sine8.begin(noteVol, 220, WAVEFORM_SINE);
        sine9.begin(noteVol, 220, WAVEFORM_SINE);
        sine10.begin(noteVol, 220, WAVEFORM_SINE);
        sine11.begin(noteVol, 220, WAVEFORM_SINE);
      } else if ((abs(encClicks)) % 4 == 1 ) {
      float noteVol = 0.3;
      sine1.begin(noteVol, 220, WAVEFORM_TRIANGLE);
        sine2.begin(noteVol, 220, WAVEFORM_TRIANGLE);
        sine3.begin(noteVol, 220, WAVEFORM_TRIANGLE);
        sine4.begin(noteVol, 220, WAVEFORM_TRIANGLE);
        sine5.begin(noteVol, 220, WAVEFORM_TRIANGLE);
        sine6.begin(noteVol, 220, WAVEFORM_TRIANGLE);
        sine7.begin(noteVol, 220, WAVEFORM_TRIANGLE);
        sine8.begin(noteVol, 220, WAVEFORM_TRIANGLE);
        sine9.begin(noteVol, 220, WAVEFORM_TRIANGLE);
        sine10.begin(noteVol, 220, WAVEFORM_TRIANGLE);
        sine11.begin(noteVol, 220, WAVEFORM_TRIANGLE);
      } else if ((abs(encClicks) ) % 4 == 2 ) {
      float noteVol = 0.2;
      sine1.begin(noteVol, 220, WAVEFORM_SQUARE);
        sine2.begin(noteVol, 220, WAVEFORM_SQUARE);
        sine3.begin(noteVol, 220, WAVEFORM_SQUARE);
        sine4.begin(noteVol, 220, WAVEFORM_SQUARE);
        sine5.begin(noteVol, 220, WAVEFORM_SQUARE);
        sine6.begin(noteVol, 220, WAVEFORM_SQUARE);
        sine7.begin(noteVol, 220, WAVEFORM_SQUARE);
        sine8.begin(noteVol, 220, WAVEFORM_SQUARE);
        sine9.begin(noteVol, 220, WAVEFORM_SQUARE);
        sine10.begin(noteVol, 220, WAVEFORM_SQUARE);
        sine11.begin(noteVol, 220, WAVEFORM_SQUARE);
      } else if ((abs(encClicks) ) % 4 == 3 ) {
      float noteVol = 0.2;
      sine1.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
        sine2.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
        sine3.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
        sine4.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
        sine5.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
        sine6.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
        sine7.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
        sine8.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
        sine9.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
        sine10.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
        sine11.begin(noteVol, 220, WAVEFORM_SAWTOOTH);
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
