int colorCycleTime = 10000 / 255 + TONESAMOUNT; //ms per cycle, added tonesamount to make a variation between different tonepads

void ledUpdate() {
  float mappedTotalAverage=0;
  for (int i = 0; i < TONESAMOUNT; i++) {
    mappedTotalAverage+=ampl[i];
  }
  mappedTotalAverage = fmap( mappedTotalAverage, 0, TONESAMOUNT, 0., 1.);


  for (int i = 0; i < TONESAMOUNT; i++) {
    //leds[i] = CHSV( (millis() / colorCycleTime) % 255, 130 * mappedTotalAverage, min(255  * ampl[i], 255));
    leds[i] = CHSV( (millis() / colorCycleTime) % 255, fmap(amplChange[i],0,standardDevRange,0,255), min(255  * ampl[i]*2, 255));
  }
  FastLED.show();

}

void setLeds() {
  FastLED.addLeds<LED_TYPE, LEDPIN0, COLOR_ORDER>(leds, 0, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN1, COLOR_ORDER>(leds, 1, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN2, COLOR_ORDER>(leds, 2, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN3, COLOR_ORDER>(leds, 3, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN4, COLOR_ORDER>(leds, 4, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN5, COLOR_ORDER>(leds, 5, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN6, COLOR_ORDER>(leds, 6, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN7, COLOR_ORDER>(leds, 7, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN8, COLOR_ORDER>(leds, 8, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN9, COLOR_ORDER>(leds, 9, 1);
  FastLED.addLeds<LED_TYPE, LEDPIN10, COLOR_ORDER>(leds, 10, 1);
  FastLED.setBrightness(  LEDBRIGHTNESS );
}
