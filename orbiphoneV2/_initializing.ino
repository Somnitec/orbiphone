

void initializingStuff() {
  resetRunningAverages();
  setLeds();

  baseLineCalibration();
}

void resetRunningAverages() {
  bufferFast0.clear();
  bufferSlow0.clear();
  bufferFast1.clear();
  bufferSlow1.clear();
  bufferFast2.clear();
  bufferSlow2.clear();
  bufferFast3.clear();
  bufferSlow3.clear();
  bufferFast4.clear();
  bufferSlow4.clear();
  bufferFast5.clear();
  bufferSlow5.clear();
  bufferFast6.clear();
  bufferSlow6.clear();
  bufferFast7.clear();
  bufferSlow7.clear();
  bufferFast8.clear();
  bufferSlow8.clear();
  bufferFast9.clear();
  bufferSlow9.clear();
  bufferFast10.clear();
  bufferSlow10.clear();
  bufferFast11.clear();
  bufferSlow11.clear();
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


float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  float value =  (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return constrain(value, out_min, out_max);
}
