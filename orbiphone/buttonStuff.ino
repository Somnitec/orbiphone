elapsedMillis buttonUpdateTimer;

void buttonUpdate() {
  if (buttonUpdateTimer > buttonUpdateTime) {
    buttonUpdateTimer = 0;
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
