bool noteplaying[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

elapsedMicros midiUpdateTimer;
void midiUpdate() {
  while (usbMIDI.read()) {
    // ignore incoming messages, needed to avoid ableton to crash supposedly
  }

  if (midiUpdateTimer > midiUpdateTime) {
    midiUpdateTimer = 0;
    for (int i = 0; i < TONESAMOUNT; i++) {
      if (ampl[i] > 0.01) {
        char midiNote = 12 * (log(freq[i] / 440) / log(2)) + 69;
        char midiPressure = ampl[i] * 127;
        if (!noteplaying[i]) {
          usbMIDI.sendNoteOn(midiNote, midiPressure, i + 1);
          noteplaying[i] = true;
          Serial.print(i + 1);
          Serial.print(" playing ");
          Serial.print(midiNote);
          Serial.print(" at ");
          Serial.println(midiPressure);
        }
        //usbMIDI.sendAfterTouchPoly(midiNote, midiPressure, i + 1);
        usbMIDI.sendAfterTouch( midiPressure, i + 1);
        //Serial.println(midiPressure);
        /*
          Serial.print(i+1);
          Serial.print(" playing ");
          Serial.print(midiNote);
          Serial.print(" at ");
          Serial.println(midiPressure);*/
      }
      else if (noteplaying[i]) {
        int midiNote = 12 * (log(freq[i] / 440) / log(2)) + 69;
        usbMIDI.sendNoteOff(midiNote, 0, i + 1);
        noteplaying[i] = false;
        Serial.print(i + 1);
        Serial.print(" shutting down ");
        Serial.print(midiNote);
        Serial.println();
      }
    }

  }
}
