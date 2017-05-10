elapsedMillis ledUpdateTimer;

int colorCycleTime= 10000 /255 + TONESAMOUNT;//ms per cycle, added tonesamount to make a variation between different tonepads
int colorDistance = 5;// in hue steps

void ledUpdate() {
  if (ledUpdateTimer > ledUpdateTime) {
    ledUpdateTimer = 0;

    float mappedTotalAverage=fmap( totalAverage,0,.1,0,1);


    leds[0][0] = CHSV( (millis()/colorCycleTime)%255                , 255*buttonState[1], 255*mappedTotalAverage);
    leds[1][0] = CHSV( ((millis()/colorCycleTime)+colorDistance)%255, 255*buttonState[2], 255*mappedTotalAverage);
    leds[2][0] = CHSV( ((millis()/colorCycleTime)-colorDistance)%255, 255*buttonState[3], 255*mappedTotalAverage);
    FastLED.show();

  }
}
