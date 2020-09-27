#include <Metro.h>
#include "RunningAverage.h"

int sensor[12] = {0, 1, 25, 17, 16, 15, 32, 18, 33, 19, 22, 23};
float ampl[12];

#define defaultRange 200

#define autocalibTime 8000

#define datapointsFast 10
#define datapointsSlow 50

Metro sensorReadFast = Metro(3);
Metro sensorReadSlow = Metro(30);
Metro printUpdateTime = Metro(10);
// storage of "temporal window" of 50 data points:
RunningAverage xFast0(datapointsFast);   // to store x data (time)
RunningAverage yFast0(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast0(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast0(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow0(datapointsSlow);   // to store x data (time)
RunningAverage ySlow0(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow0(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow0(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast0 = 0;
float slopeSlow0 = 0;

RunningAverage xFast1(datapointsFast);   // to store x data (time)
RunningAverage yFast1(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast1(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast1(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow1(datapointsSlow);   // to store x data (time)
RunningAverage ySlow1(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow1(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow1(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast1 = 0;
float slopeSlow1 = 0;

RunningAverage xFast2(datapointsFast);   // to store x data (time)
RunningAverage yFast2(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast2(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast2(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow2(datapointsSlow);   // to store x data (time)
RunningAverage ySlow2(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow2(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow2(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast2 = 0;
float slopeSlow2 = 0;

RunningAverage xFast3(datapointsFast);   // to store x data (time)
RunningAverage yFast3(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast3(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast3(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow3(datapointsSlow);   // to store x data (time)
RunningAverage ySlow3(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow3(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow3(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast3 = 0;
float slopeSlow3 = 0;

RunningAverage xFast4(datapointsFast);   // to store x data (time)
RunningAverage yFast4(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast4(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast4(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow4(datapointsSlow);   // to store x data (time)
RunningAverage ySlow4(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow4(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow4(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast4 = 0;
float slopeSlow4 = 0;

RunningAverage xFast5(datapointsFast);   // to store x data (time)
RunningAverage yFast5(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast5(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast5(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow5(datapointsSlow);   // to store x data (time)
RunningAverage ySlow5(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow5(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow5(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast5 = 0;
float slopeSlow5 = 0;

RunningAverage xFast6(datapointsFast);   // to store x data (time)
RunningAverage yFast6(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast6(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast6(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow6(datapointsSlow);   // to store x data (time)
RunningAverage ySlow6(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow6(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow6(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast6 = 0;
float slopeSlow6 = 0;

RunningAverage xFast7(datapointsFast);   // to store x data (time)
RunningAverage yFast7(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast7(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast7(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow7(datapointsSlow);   // to store x data (time)
RunningAverage ySlow7(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow7(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow7(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast7 = 0;
float slopeSlow7 = 0;

RunningAverage xFast8(datapointsFast);   // to store x data (time)
RunningAverage yFast8(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast8(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast8(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow8(datapointsSlow);   // to store x data (time)
RunningAverage ySlow8(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow8(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow8(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast8 = 0;
float slopeSlow8 = 0;

RunningAverage xFast9(datapointsFast);   // to store x data (time)
RunningAverage yFast9(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast9(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast9(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow9(datapointsSlow);   // to store x data (time)
RunningAverage ySlow9(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow9(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow9(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast9 = 0;
float slopeSlow9 = 0;

RunningAverage xFast10(datapointsFast);   // to store x data (time)
RunningAverage yFast10(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast10(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast10(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow10(datapointsSlow);   // to store x data (time)
RunningAverage ySlow10(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow10(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow10(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast10 = 0;
float slopeSlow10 = 0;

RunningAverage xFast11(datapointsFast);   // to store x data (time)
RunningAverage yFast11(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast11(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast11(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow11(datapointsSlow);   // to store x data (time)
RunningAverage ySlow11(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow11(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow11(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast11 = 0;
float slopeSlow11 = 0;



bool stable = false;
long stableTimer = 0;

void setup() {
  Serial.begin(9600);    // needed for arduino yun

  baseLineCalibration();
}

void loop()
{
  if (sensorReadFast.check() == 1) {
    doSensorReadFast();
  }
  if (sensorReadSlow.check() == 1) {
    doSensorReadSlow(0);
  }
  if (printUpdateTime.check() == 1) {
    //    Serial.print("\tSlopeFast0:");
    //    Serial.print(slopeFast0 , 4); // shows slope value (sensor units / second)
    //    Serial.print("\tSlopeSlow0:");
    //    Serial.print(slopeSlow0 , 4); // shows slope value (sensor units / second)
    //    Serial.print("\tRawVal0:");
    //    Serial.print(touchRead(sensor[0]));
    //    Serial.print("\tavgVal0:");
    //    Serial.print(yFast0.getAverage());
    //    Serial.print("\tStandardError0:");
    //    Serial.print(yFast0.getStandardError());
    //    Serial.print("\tStandardDeviation0:");
    //    Serial.print(yFast0.getStandardDeviation());
    //    Serial.print("\tslStandardError0:");
    //    Serial.print(ySlow0.getStandardError());
    //    Serial.print("\tslStandardDeviation0:");
    //    Serial.print(ySlow0.getStandardDeviation());
    //    Serial.print("\tbottom0:");
    //    Serial.print(ySlow0.getMin());
    //    Serial.print("\ttop:");
    //    Serial.print(ySlow0.getMax());

    Serial.print("\tslowSlopeSUM:");
    int slopeSum = slopeSlow0 + slopeSlow1 + slopeSlow2 + slopeSlow3 + slopeSlow4 + slopeSlow5 + slopeSlow6 + slopeSlow7 + slopeSlow8 + slopeSlow9 + slopeSlow10 + slopeSlow11;
    int stableRange = 5;
    
    if (slopeSum < stableRange && slopeSum > -stableRange) {
      if (stable == false){
        stable = true;
        stableTimer=millis();
      } else {
        if (millis()>stableTimer+autocalibTime){
           baseLineCalibration();
        }
      }
      
    } else stable = false;
    
    //Serial.print(stableTimer);

    Serial.print("\tscaled0:");
    Serial.print( ampl[0]);
    Serial.print("\tscaled1:");
    Serial.print( ampl[1]);
    Serial.print("\tscaled2:");
    Serial.print( ampl[2]);
    Serial.print("\tscaled3:");
    Serial.print( ampl[3]);
    Serial.print("\tscaled4:");
    Serial.print( ampl[4]);
    Serial.print("\tscaled5:");
    Serial.print( ampl[5]);
    Serial.print("\tscaled6:");
    Serial.print( ampl[6]);
    Serial.print("\tscaled7:");
    Serial.print( ampl[7]);
    Serial.print("\tscaled8:");
    Serial.print( ampl[8]);
    Serial.print("\tscaled9:");
    Serial.print( ampl[9]);
    Serial.print("\tscaled10:");
    Serial.print( ampl[10]);
    //Serial.print("\tscaled11:");
    //Serial.print( ampl[11]);

    //    Serial.print("\tscaled1:");
    //    Serial.print(fmap(touchRead(sensor[1]), ySlow1.getMin(), ySlow1.getMax() + 1, 0., 1.));
    //
    //    Serial.print("\tscaled2:");
    //    Serial.print( fmap(touchRead(sensor[2]), ySlow2.getMin(), ySlow2.getMax() + 1, 0., 1.));
    //
    //    Serial.print("\tscaled3:");
    //    Serial.print(fmap(touchRead(sensor[3]), ySlow3.getMin(), ySlow3.getMax() + 1, 0., 1.));
    //
    //    Serial.print("\tscaled4:");
    //    Serial.print( fmap(touchRead(sensor[4]), ySlow4.getMin(), ySlow4.getMax() + 1, 0., 1.));
    //
    //    Serial.print("\tscaled5:");
    //    Serial.print(fmap(touchRead(sensor[5]), ySlow5.getMin(), ySlow5.getMax() + 1, 0., 1.));
    //
    //    Serial.print("\tscaled6:");
    //    Serial.print( fmap(touchRead(sensor[6]), ySlow6.getMin(), ySlow6.getMax() + 1, 0., 1.));
    //
    //    Serial.print("\tscaled7:");
    //    Serial.print(fmap(touchRead(sensor[7]), ySlow7.getMin(), ySlow7.getMax() + 1, 0., 1.));
    //
    //    Serial.print("\tscaled8:");
    //    Serial.print( fmap(touchRead(sensor[8]), ySlow8.getMin(), ySlow8.getMax() + 1, 0., 1.));
    //
    //    Serial.print("\tscaled9:");
    //    Serial.print(fmap(touchRead(sensor[9]), ySlow9.getMin(), ySlow9.getMax() + 1, 0., 1.));
    //
    //    Serial.print("\tscaled10:");
    //    Serial.print( fmap(touchRead(sensor[10]), ySlow10.getMin(), ySlow10.getMax() + 1, 0., 1.));
    //
    //    Serial.print("\tscaled11:");
    //    Serial.print(fmap(touchRead(sensor[11]), ySlow11.getMin(), ySlow11.getMax() + 1, 0., 1.));




    /*
        Serial.print("\tSlopeFast1:");
        Serial.print(slopeFast1 , 4); // shows slope value (sensor units / second)
        Serial.print("\tSlopeSlow1:");
        Serial.print(slopeSlow1 , 4); // shows slope value (sensor units / second)
        Serial.print("\tRawVal1:");
        Serial.print(touchRead(sensor[1]));
        Serial.print("\tavgVal1:");
        Serial.print(yFast1.getAverage());

        Serial.print("\tSlopeFast2:");
        Serial.print(slopeFast2 , 4); // shows slope value (sensor units / second)
        Serial.print("\tSlopeSlow2:");
        Serial.print(slopeSlow2 , 4); // shows slope value (sensor units / second)
        Serial.print("\tRawVal2:");
        Serial.print(touchRead(sensor[2]));
        Serial.print("\tavgVal2:");
        Serial.print(yFast2.getAverage());

        Serial.print("\tSlopeFast3:");
        Serial.print(slopeFast3 , 4); // shows slope value (sensor units / second)
        Serial.print("\tSlopeSlow3:");
        Serial.print(slopeSlow3 , 4); // shows slope value (sensor units / second)
        Serial.print("\tRawVal3:");
        Serial.print(touchRead(sensor[3]));
        Serial.print("\tavgVal3:");
        Serial.print(yFast3.getAverage());

        Serial.print("\tSlopeFast4:");
        Serial.print(slopeFast4 , 4); // shows slope value (sensor units / second)
        Serial.print("\tSlopeSlow4:");
        Serial.print(slopeSlow4 , 4); // shows slope value (sensor units / second)
        Serial.print("\tRawVal4:");
        Serial.print(touchRead(sensor[4]));
        Serial.print("\tavgVa4:");
        Serial.print(yFast4.getAverage());

        Serial.print("\tSlopeFast5:");
        Serial.print(slopeFast5 , 4); // shows slope value (sensor units / second)
        Serial.print("\tSlopeSlow5:");
        Serial.print(slopeSlow5 , 4); // shows slope value (sensor units / second)
        Serial.print("\tRawVal5:");
        Serial.print(touchRead(sensor[5]));
        Serial.print("\tavgVa5:");
        Serial.print(yFast5.getAverage());

        Serial.print("\tSlopeFast6:");
        Serial.print(slopeFast6 , 4); // shows slope value (sensor units / second)
        Serial.print("\tSlopeSlow6:");
        Serial.print(slopeSlow6 , 4); // shows slope value (sensor units / second)
        Serial.print("\tRawVal6:");
        Serial.print(touchRead(sensor[6]));
        Serial.print("\avgVa6:");
        Serial.print(yFast6.getAverage());

        Serial.print("\tSlopeFast7:");
        Serial.print(slopeFast7 , 4); // shows slope value (sensor units / second)
        Serial.print("\tSlopeSlow7:");
        Serial.print(slopeSlow7 , 4); // shows slope value (sensor units / second)
        Serial.print("\tRawVal7:");
        Serial.print(touchRead(sensor[7]));
        Serial.print("\tavgVal7:");
        Serial.print(yFast7.getAverage());

        Serial.print("\tSlopeFast8:");
        Serial.print(slopeFast8 , 4); // shows slope value (sensor units / second)
        Serial.print("\tSlopeSlow8:");
        Serial.print(slopeSlow8 , 4); // shows slope value (sensor units / second)
        Serial.print("\tRawVal8:");
        Serial.print(touchRead(sensor[8]));
        Serial.print("\tavgVa8:");
        Serial.print(yFast8.getAverage());

        Serial.print("\tSlopeFast9:");
        Serial.print(slopeFast9 , 4); // shows slope value (sensor units / second)
        Serial.print("\tSlopeSlow9:");
        Serial.print(slopeSlow9 , 4); // shows slope value (sensor units / second)
        Serial.print("\tRawVal9:");
        Serial.print(touchRead(sensor[9]));
        Serial.print("\tavgVal9:");
        Serial.print(yFast9.getAverage());

        Serial.print("\tSlopeFast10:");
        Serial.print(slopeFast10 , 4); // shows slope value (sensor units / second)
        Serial.print("\tSlopeSlow10:");
        Serial.print(slopeSlow10 , 4); // shows slope value (sensor units / second)
        Serial.print("\tRawVal10:");
        Serial.print(touchRead(sensor[10]));
        Serial.print("\tavgVal10:");
        Serial.print(yFast10.getAverage());

        Serial.print("\tSlopeFast11:");
        Serial.print(slopeFast11 , 4); // shows slope value (sensor units / second)
        Serial.print("\tSlopeSlow11:");
        Serial.print(slopeSlow11 , 4); // shows slope value (sensor units / second)
        Serial.print("\tRawVal11:");
        Serial.print(touchRead(sensor[11]));
        Serial.print("\tavgVal11:");
        Serial.print(yFast11.getAverage());
    */
    Serial.println();
  }
}

void doSensorReadFast() {
  float yn = 0;
  float xn = 0;
  float xFastVal = 0;

  yn = touchRead(sensor[0]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast0.addValue(yn);          // add y variable to storing array
  xFast0.addValue(xn);          // add x variable to storing array
  xyFast0.addValue(xn * yn); // same for x*y
  x2Fast0.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast0.getAverage();
  slopeFast0 = (xyFast0.getAverage() - (xFastVal * yFast0.getAverage())) / (x2Fast0.getAverage() - (xFastVal * xFastVal));
  ampl[0] = fmap(touchRead(sensor[0]), ySlow0.getMin(), ySlow0.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[1]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast1.addValue(yn);          // add y variable to storing array
  xFast1.addValue(xn);          // add x variable to storing array
  xyFast1.addValue(xn * yn); // same for x*y
  x2Fast1.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast1.getAverage();
  slopeFast1 = (xyFast1.getAverage() - (xFastVal * yFast1.getAverage())) / (x2Fast1.getAverage() - (xFastVal * xFastVal));
  ampl[1] = fmap(touchRead(sensor[1]), ySlow1.getMin(), ySlow1.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[2]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast2.addValue(yn);          // add y variable to storing array
  xFast2.addValue(xn);          // add x variable to storing array
  xyFast2.addValue(xn * yn); // same for x*y
  x2Fast2.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast2.getAverage();
  slopeFast2 = (xyFast2.getAverage() - (xFastVal * yFast2.getAverage())) / (x2Fast2.getAverage() - (xFastVal * xFastVal));
  ampl[2] = fmap(touchRead(sensor[2]), ySlow2.getMin(), ySlow2.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[3]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast3.addValue(yn);          // add y variable to storing array
  xFast3.addValue(xn);          // add x variable to storing array
  xyFast3.addValue(xn * yn); // same for x*y
  x2Fast3.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast3.getAverage();
  slopeFast3 = (xyFast3.getAverage() - (xFastVal * yFast3.getAverage())) / (x2Fast3.getAverage() - (xFastVal * xFastVal));
  ampl[3] = fmap(touchRead(sensor[3]), ySlow3.getMin(), ySlow3.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[4]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast4.addValue(yn);          // add y variable to storing array
  xFast4.addValue(xn);          // add x variable to storing array
  xyFast4.addValue(xn * yn); // same for x*y
  x2Fast4.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast4.getAverage();
  slopeFast4 = (xyFast4.getAverage() - (xFastVal * yFast4.getAverage())) / (x2Fast4.getAverage() - (xFastVal * xFastVal));
  ampl[4] = fmap(touchRead(sensor[4]), ySlow4.getMin(), ySlow4.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[5]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast5.addValue(yn);          // add y variable to storing array
  xFast5.addValue(xn);          // add x variable to storing array
  xyFast5.addValue(xn * yn); // same for x*y
  x2Fast5.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast5.getAverage();
  slopeFast5 = (xyFast5.getAverage() - (xFastVal * yFast5.getAverage())) / (x2Fast5.getAverage() - (xFastVal * xFastVal));
  ampl[5] = fmap(touchRead(sensor[5]), ySlow5.getMin(), ySlow5.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[6]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast6.addValue(yn);          // add y variable to storing array
  xFast6.addValue(xn);          // add x variable to storing array
  xyFast6.addValue(xn * yn); // same for x*y
  x2Fast6.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast6.getAverage();
  slopeFast6 = (xyFast6.getAverage() - (xFastVal * yFast6.getAverage())) / (x2Fast6.getAverage() - (xFastVal * xFastVal));
  ampl[6] = fmap(touchRead(sensor[6]), ySlow6.getMin(), ySlow6.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[7]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast7.addValue(yn);          // add y variable to storing array
  xFast7.addValue(xn);          // add x variable to storing array
  xyFast7.addValue(xn * yn); // same for x*y
  x2Fast7.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast7.getAverage();
  slopeFast7 = (xyFast7.getAverage() - (xFastVal * yFast7.getAverage())) / (x2Fast7.getAverage() - (xFastVal * xFastVal));
  ampl[7] = fmap(touchRead(sensor[7]), ySlow7.getMin(), ySlow7.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[8]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast8.addValue(yn);          // add y variable to storing array
  xFast8.addValue(xn);          // add x variable to storing array
  xyFast8.addValue(xn * yn); // same for x*y
  x2Fast8.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast8.getAverage();
  slopeFast8 = (xyFast8.getAverage() - (xFastVal * yFast8.getAverage())) / (x2Fast8.getAverage() - (xFastVal * xFastVal));
  ampl[8] = fmap(touchRead(sensor[8]), ySlow8.getMin(), ySlow8.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[9]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast9.addValue(yn);          // add y variable to storing array
  xFast9.addValue(xn);          // add x variable to storing array
  xyFast9.addValue(xn * yn); // same for x*y
  x2Fast9.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast9.getAverage();
  slopeFast9 = (xyFast9.getAverage() - (xFastVal * yFast9.getAverage())) / (x2Fast9.getAverage() - (xFastVal * xFastVal));
  ampl[9] = fmap(touchRead(sensor[9]), ySlow9.getMin(), ySlow9.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[10]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast10.addValue(yn);          // add y variable to storing array
  xFast10.addValue(xn);          // add x variable to storing array
  xyFast10.addValue(xn * yn); // same for x*y
  x2Fast10.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast10.getAverage();
  slopeFast10 = (xyFast10.getAverage() - (xFastVal * yFast10.getAverage())) / (x2Fast10.getAverage() - (xFastVal * xFastVal));
  ampl[10] = fmap(touchRead(sensor[10]), ySlow10.getMin(), ySlow10.getMax() + 1, 0., 1.);

  yn = touchRead(sensor[11]) ;  // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  yFast11.addValue(yn);          // add y variable to storing array
  xFast11.addValue(xn);          // add x variable to storing array
  xyFast11.addValue(xn * yn); // same for x*y
  x2Fast11.addValue(xn * xn); // same for x*x
  // Slope equation (simple regression):
  xFastVal = xFast11.getAverage();
  slopeFast11 = (xyFast11.getAverage() - (xFastVal * yFast11.getAverage())) / (x2Fast11.getAverage() - (xFastVal * xFastVal));
  ampl[11] = fmap(touchRead(sensor[11]), ySlow11.getMin(), ySlow11.getMax() + 1, 0., 1.);
}

void doSensorReadSlow(float mod) {

  float yn = 0;
  float xn = 0;
  float xvalSlow = 0;

  yn = mod + touchRead( sensor[0]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow0.addValue(yn);          // add y variable to storing array
  xSlow0.addValue(xn);          // add x variable to storing array
  xySlow0.addValue(xn * yn); // same for x*y
  x2Slow0.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow0.getAverage();
  slopeSlow0 = (xySlow0.getAverage() - (xvalSlow * ySlow0.getAverage())) / (x2Slow0.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[1]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow1.addValue(yn);          // add y variable to storing array
  xSlow1.addValue(xn);          // add x variable to storing array
  xySlow1.addValue(xn * yn); // same for x*y
  x2Slow1.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow1.getAverage();
  slopeSlow1 = (xySlow1.getAverage() - (xvalSlow * ySlow1.getAverage())) / (x2Slow1.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[2]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow2.addValue(yn);          // add y variable to storing array
  xSlow2.addValue(xn);          // add x variable to storing array
  xySlow2.addValue(xn * yn); // same for x*y
  x2Slow2.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow2.getAverage();
  slopeSlow2 = (xySlow2.getAverage() - (xvalSlow * ySlow2.getAverage())) / (x2Slow2.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[3]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow3.addValue(yn);          // add y variable to storing array
  xSlow3.addValue(xn);          // add x variable to storing array
  xySlow3.addValue(xn * yn); // same for x*y
  x2Slow3.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow3.getAverage();
  slopeSlow3 = (xySlow3.getAverage() - (xvalSlow * ySlow3.getAverage())) / (x2Slow3.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[4]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow4.addValue(yn);          // add y variable to storing array
  xSlow4.addValue(xn);          // add x variable to storing array
  xySlow4.addValue(xn * yn); // same for x*y
  x2Slow4.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow4.getAverage();
  slopeSlow4 = (xySlow4.getAverage() - (xvalSlow * ySlow4.getAverage())) / (x2Slow4.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[5]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow5.addValue(yn);          // add y variable to storing array
  xSlow5.addValue(xn);          // add x variable to storing array
  xySlow5.addValue(xn * yn); // same for x*y
  x2Slow5.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow5.getAverage();
  slopeSlow5 = (xySlow5.getAverage() - (xvalSlow * ySlow5.getAverage())) / (x2Slow5.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[6]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow6.addValue(yn);          // add y variable to storing array
  xSlow6.addValue(xn);          // add x variable to storing array
  xySlow6.addValue(xn * yn); // same for x*y
  x2Slow6.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow6.getAverage();
  slopeSlow6 = (xySlow6.getAverage() - (xvalSlow * ySlow6.getAverage())) / (x2Slow6.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[7]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow7.addValue(yn);          // add y variable to storing array
  xSlow7.addValue(xn);          // add x variable to storing array
  xySlow7.addValue(xn * yn); // same for x*y
  x2Slow7.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow7.getAverage();
  slopeSlow7 = (xySlow7.getAverage() - (xvalSlow * ySlow7.getAverage())) / (x2Slow7.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[8]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow8.addValue(yn);          // add y variable to storing array
  xSlow8.addValue(xn);          // add x variable to storing array
  xySlow8.addValue(xn * yn); // same for x*y
  x2Slow8.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow8.getAverage();
  slopeSlow8 = (xySlow8.getAverage() - (xvalSlow * ySlow8.getAverage())) / (x2Slow8.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[9]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow9.addValue(yn);          // add y variable to storing array
  xSlow9.addValue(xn);          // add x variable to storing array
  xySlow9.addValue(xn * yn); // same for x*y
  x2Slow9.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow9.getAverage();
  slopeSlow9 = (xySlow9.getAverage() - (xvalSlow * ySlow9.getAverage())) / (x2Slow9.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[10]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow10.addValue(yn);          // add y variable to storing array
  xSlow10.addValue(xn);          // add x variable to storing array
  xySlow10.addValue(xn * yn); // same for x*y
  x2Slow10.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow10.getAverage();
  slopeSlow10 = (xySlow10.getAverage() - (xvalSlow * ySlow10.getAverage())) / (x2Slow10.getAverage() - (xvalSlow * xvalSlow));

  yn = mod + touchRead( sensor[11]) ; // individual sensor lecture (y variable)
  xn = millis() / 1000.; // / 1000.000; // corresponding x time variable (seconds)
  ySlow11.addValue(yn);          // add y variable to storing array
  xSlow11.addValue(xn);          // add x variable to storing array
  xySlow11.addValue(xn * yn); // same for x*y
  x2Slow11.addValue(xn * xn); // same for x*x
  xvalSlow = xSlow11.getAverage();
  slopeSlow11 = (xySlow11.getAverage() - (xvalSlow * ySlow11.getAverage())) / (x2Slow11.getAverage() - (xvalSlow * xvalSlow));


}

void baseLineCalibration() {
   // explicitly start clean
  xFast0.clear();
  yFast0.clear();
  xyFast0.clear();
  x2Fast0.clear();
  xSlow0.clear();
  ySlow0.clear();
  xySlow0.clear();
  x2Slow0.clear();

  xFast1.clear();
  yFast1.clear();
  xyFast1.clear();
  x2Fast1.clear();
  xSlow1.clear();
  ySlow1.clear();
  xySlow1.clear();
  x2Slow1.clear();

  xFast2.clear();
  yFast2.clear();
  xyFast2.clear();
  x2Fast2.clear();
  xSlow2.clear();
  ySlow2.clear();
  xySlow2.clear();
  x2Slow2.clear();

  xFast3.clear();
  yFast3.clear();
  xyFast3.clear();
  x2Fast3.clear();
  xSlow3.clear();
  ySlow3.clear();
  xySlow3.clear();
  x2Slow3.clear();

  xFast4.clear();
  yFast4.clear();
  xyFast4.clear();
  x2Fast4.clear();
  xSlow4.clear();
  ySlow4.clear();
  xySlow4.clear();
  x2Slow4.clear();

  xFast5.clear();
  yFast5.clear();
  xyFast5.clear();
  x2Fast5.clear();
  xSlow5.clear();
  ySlow5.clear();
  xySlow5.clear();
  x2Slow5.clear();

  xFast6.clear();
  yFast6.clear();
  xyFast6.clear();
  x2Fast6.clear();
  xSlow6.clear();
  ySlow6.clear();
  xySlow6.clear();
  x2Slow6.clear();

  xFast7.clear();
  yFast7.clear();
  xyFast7.clear();
  x2Fast7.clear();
  xSlow7.clear();
  ySlow7.clear();
  xySlow7.clear();
  x2Slow7.clear();

  xFast8.clear();
  yFast8.clear();
  xyFast8.clear();
  x2Fast8.clear();
  xSlow8.clear();
  ySlow8.clear();
  xySlow8.clear();
  x2Slow8.clear();

  xFast9.clear();
  yFast9.clear();
  xyFast9.clear();
  x2Fast9.clear();
  xSlow9.clear();
  ySlow9.clear();
  xySlow9.clear();
  x2Slow9.clear();

  xFast10.clear();
  yFast10.clear();
  xyFast10.clear();
  x2Fast10.clear();
  xSlow10.clear();
  ySlow10.clear();
  xySlow10.clear();
  x2Slow10.clear();

  xFast11.clear();
  yFast11.clear();
  xyFast11.clear();
  x2Fast11.clear();
  xSlow11.clear();
  ySlow11.clear();
  xySlow11.clear();
  x2Slow11.clear();
  
  for (int i = 0; i < max(datapointsFast,datapointsSlow); i++) {
    doSensorReadFast();
    doSensorReadSlow(defaultRange);

    delay(1);
  }
  Serial.println("recalibrated");
}

float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
