/*
  DonutStudioMillisTime.h - Library for using the millis-function of the arduino to create a clock
  Created by Donut Studio, Febuary 07, 2023.
  Released into the public domain.
*/

// include the libraray
#include "DonutStudioMillisTime.h"

// create an object of the time class and set the time to 12h:00m:00s
MillisTime clkTime = MillisTime(12, 0, 0); 

void setup() 
{
  // start the serial port
  Serial.begin(9600);

  // set the hour to 4
  clkTime.setHour(4);
  // set the minute to 40
  clkTime.setMinute(40);
  // set the second to 20
  clkTime.setSecond(20);

  // => time now: 4h:40m:20s
}
void loop() 
{
  int h = clkTime.getAbsoluteHours();
  int m = clkTime.getAbsoluteMinutes();
  int s = clkTime.getAbsoluteSeconds();

  Serial.print("absolute time:");
  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.println(s);

  Serial.print("relative time:");
  Serial.println(clkTime.getPhrasedTime());

  Serial.println();

  delay(500);
}