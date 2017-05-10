elapsedMillis buttonUpdateTimer;

void buttonUpdate() {
  if (buttonUpdateTimer > buttonUpdateTime) {
    buttonUpdateTimer = 0;

    buttonState[0] = 0;
    buttonState[1] = digitalRead(BUTTON1);
    buttonState[2] = digitalRead(BUTTON2);
    buttonState[3] = digitalRead(BUTTON3);

    if (!buttonState[1])buttonState[0] += 1;
    if (!buttonState[2])buttonState[0] += 2;
    if (!buttonState[3])buttonState[0] += 4;

  }
}
