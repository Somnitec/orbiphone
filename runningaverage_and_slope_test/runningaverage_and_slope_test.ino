#include <Metro.h>
#include "RunningAverage.h"

#define datapointsFast 100
#define datapointsSlow 50

Metro sensorReadFast = Metro(3);
Metro sensorReadSlow = Metro(30);
Metro printUpdateTime = Metro(10);
// storage of "temporal window" of 50 data points:

RunningAverage xFast(datapointsFast);   // to store x data (time)
RunningAverage yFast(datapointsFast);   // to store y data (analog sensor output)
RunningAverage xyFast(datapointsFast);  // to store x*y, needed for slope calculation
RunningAverage x2Fast(datapointsFast);  // to store x*x, needed for slope calculation

RunningAverage xSlow(datapointsSlow);   // to store x data (time)
RunningAverage ySlow(datapointsSlow);   // to store y data (analog sensor output)
RunningAverage xySlow(datapointsSlow);  // to store x*y, needed for slope calculation
RunningAverage x2Slow(datapointsSlow);  // to store x*x, needed for slope calculation

float slopeFast=0;
float slopeSlow=0;

void setup() {
  Serial.begin(9600);    // needed for arduino yun

  Serial.println("Slope calculation");

  // explicitly start clean
  xFast.clear();
  yFast.clear();
  xyFast.clear();
  x2Fast.clear();

  xSlow.clear();
  ySlow.clear();
  xySlow.clear();
  x2Slow.clear();

  // wait until window is full of data.
  if (x2Slow.getCount() < datapointsSlow) {
    readValues();
    Serial.print("filling time window... n = ");
    Serial.println(x2Slow.getCount());
  }
}

void loop()
{
  if (sensorReadFast.check() == 1) {
    float yn = touchRead(0) * 1000;  // individual sensor lecture (y variable)
    float xn = millis();// / 1000.000; // corresponding x time variable (seconds)

    yFast.addValue(yn);          // add y variable to storing array
    xFast.addValue(xn);          // add x variable to storing array
    xyFast.addValue(xn * yn); // same for x*y
    x2Fast.addValue(xn * xn); // same for x*x
    // Slope equation (simple regression):
    float xvalFast = xFast.getAverage();
    slopeFast = (xyFast.getAverage() - (xvalFast * yFast.getAverage())) / (x2Fast.getAverage() - (xvalFast * xvalFast));
  }
  if (sensorReadSlow.check() == 1) {
    float yn = touchRead(0) * 1000.;  // individual sensor lecture (y variable)
    float xn = millis();// / 1000.000; // corresponding x time variable (seconds)

    ySlow.addValue(yn);          // add y variable to storing array
    xSlow.addValue(xn);          // add x variable to storing array
    xySlow.addValue(xn * yn); // same for x*y
    x2Slow.addValue(xn * xn); // same for x*x
    float xvalSlow = xSlow.getAverage();
    slopeSlow = (xySlow.getAverage() - (xvalSlow * ySlow.getAverage())) / (x2Slow.getAverage() - (xvalSlow * xvalSlow));

  }
  if (printUpdateTime.check() == 1) {
    Serial.print("SlopeFast:");
    Serial.print(slopeFast , 4); // shows slope value (sensor units / second)
    Serial.print("\tSlopeSlow:");
    Serial.print(slopeSlow , 4); // shows slope value (sensor units / second)
    Serial.print("\tRawVal:");
    Serial.println(touchRead(0)); // shows slope value (sensor units / second)
  }
}

void readValues() {


}
