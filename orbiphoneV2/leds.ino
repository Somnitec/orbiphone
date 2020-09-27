int colorCycleTime = 10000 / 255 + TONESAMOUNT; //ms per cycle, added tonesamount to make a variation between different tonepads

void ledUpdate() {
  float mappedTotalAverage=0;
  for (int i = 0; i < TONESAMOUNT; i++) {
    mappedTotalAverage+=ampl[i];
  }
  mappedTotalAverage = fmap( mappedTotalAverage, 0, TONESAMOUNT, 0., 1.);


  for (int i = 0; i < TONESAMOUNT; i++) {
    //leds[i] = CHSV( (millis() / colorCycleTime) % 255, 130 * mappedTotalAverage, min(255  * ampl[i], 255));
    leds[i] = CHSV( (millis() / colorCycleTime) % 255, fmap(amplChange[i],0,standardDevRange,0,255), min(255  * ampl[i], 255));
  }
  FastLED.show();

}
