void knobUpdate(){

  amp1.gain(fmap(analogRead(volumePin), 1023, 0, 0.0, 1.0));
  amp1sub.gain(fmap(analogRead(volumePin), 1023, 0, 0.0, 1.0));

}
