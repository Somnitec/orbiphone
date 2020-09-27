void knobUpdate() {

  amp1.gain(fmap(analogRead(volumePin), 1023, 0, 0.0, 1.0));
  amp1sub.gain(fmap(analogRead(volumePin), 1023, 0, 0.0, 1.0));

  encButton.update();
  if (encButton.fell()) {
    encClicks++;
    setTimbre();
  }

  if (encoderState != encoder.read() / 4) {

    encoderState = encoder.read() / 4;
    setFrequencies();
  }

}

void setKnobs() {
  pinMode(encPins[2], INPUT_PULLUP);
  encButton.attach(encPins[2]);
  encButton.interval(buttonDebounceTime);
  //encoder.write(1000);
}
