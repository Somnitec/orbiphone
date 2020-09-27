

void initializingStuff() {
  resetRunningAverages();
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


float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  float value =  (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return constrain(value, out_min, out_max);
}
