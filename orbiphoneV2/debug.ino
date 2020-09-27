void debugUpdate() {
  Serial.print("\tsraw0:");
  Serial.print( touchRead(sensor[0]));
  Serial.print("\tfast0:");
  Serial.print(bufferFast0.getAverage());
  Serial.print("\tslow0:");
  Serial.print( bufferSlow0.getAverage());
  Serial.print("\tamp0:");
  Serial.print( ampl[0]*6000);
  Serial.println();
}
