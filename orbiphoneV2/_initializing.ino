

void initializingStuff() {
  Serial.begin(115200);

  setLeds();
  startAudio();

  baseLineCalibration();
}






float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  float value =  (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return constrain(value, out_min, out_max);
}
