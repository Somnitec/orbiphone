char noteplaying[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

elapsedMicros midiUpdateTimer;
void midiUpdate() {
  while (usbMIDI.read()) {
    // ignore incoming messages, needed to avoid ableton to crash supposedly
  }

  if (midiUpdateTimer > midiUpdateTime) {
    midiUpdateTimer = 0;
    for (int i = 0; i < TONESAMOUNT; i++) {
      if (ampl[i] > 0.01) {
        //char midiNote = 12 * (log(toneSet[buttonState[0]][i] / 440) / log(2)) + 69;//formula to turn the freq into a midi note, could be more fast by simply making a table
        char midiPressure = ampl[i] * 127;
        if (noteplaying[i] == 0) {
          float note = 2* toneSet[buttonState[0]][i] ;//freq[i];//
          Serial.print(toneSet[buttonState[0]][i]*2);
          Serial.print('\t');
          Serial.println(freq[i]);
          noteplaying[i] = 12 * (log(note / 440) / log(2)) + 69;//formula to turn the freq into a midi note, could be more fast by simply making a table
          //noteplaying[i] = true;
          usbMIDI.sendNoteOn(noteplaying[i], midiPressure, i + 1);
          /*
                    Serial.print(i + 1);
                    Serial.print(" playing ");
                    Serial.print(noteplaying[i]);
                    Serial.print(" at ");
                    Serial.println(midiPressure);
          */
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
      else if (noteplaying[i] != 0) {
        //int midiNote = 12 * (log(freq[i] / 440) / log(2)) + 69;
        usbMIDI.sendNoteOff(noteplaying[i], 0, i + 1);
        noteplaying[i] = 0;
        /*
          Serial.print(i + 1);
          Serial.print(" shutting down ");
          Serial.print(midiNote);
          Serial.println();
        */
      }
    }

  }
}
