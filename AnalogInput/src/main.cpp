#include <Arduino.h>
//I, Ahmet Aydogan, 000792453 certify that this material is my original work.No other person's work has been used without due acknowledgement.
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

float analogVoltage(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void loop() {
  // put your main code here, to run repeatedly:
  int iVal;
  String tempReading;

  // read digitized value from the D1 mini's A/D convertor
  iVal = analogRead(A0);
  float y = analogVoltage(iVal, 0, 1024, 0, 50);
    if (y < 10)
  {
    tempReading = "Cold!";
  }
    if (y <= 15 && y >= 10 )
  {
    tempReading = "Cool";
  }
    if (y <= 25 && y > 15 )
  {
    tempReading = "Perfect";
  }
    if (y <= 30 && y > 25 )
  {
    tempReading = "Warm";
  }
    if (y <= 35 && y > 30 )
  {
    tempReading = "Hot";
  }
    if (y > 35)
  {
    tempReading = "Too Hot!";
  }


  //print value to the USB port
  Serial.println("Digitized Value = " + String(iVal) + " is equivalent to a temperature input of " + String(y) + " deg. C, which is " + String(tempReading));

  // wait 2 seconds (2000ms)
  delay(2000);
}