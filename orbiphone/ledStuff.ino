elapsedMillis ledUpdateTimer;

int colorCycleTime = 10000 / 255 + TONESAMOUNT; //ms per cycle, added tonesamount to make a variation between different tonepads
int colorDistance = 5;// in hue steps

void ledUpdate() {


  float mappedTotalAverage = fmap( totalAverage, 0, .1, 0, 1);



  for (int i = 0; i < TONESAMOUNT; i++) {
    leds[i] = CHSV( (millis() / colorCycleTime) % 255, 130 * mappedTotalAverage, min(4000  * ampl[i], 255));
  }
  FastLED.show();


}

//mapping the position of where is touched, to a hue value (0-255)
//how to do this?
