/*
  DonutStudioMillisTime.h - Library for using the millis-function of the arduino to create a clock
  Created by Donut Studio, Febuary 10, 2023.
  Released into the public domain.
*/

// include the libraray
#include "DonutStudioMillisTime.h"

// create an object of the time class
MillisTime clkTime = MillisTime(); 

void setup() 
{
  // start the serial port
  Serial.begin(9600);

  // set the hour to 23
  clkTime.setHour(23);
  // set the minute to 59
  clkTime.setMinute(59);
  // set the second to 30
  clkTime.setSecond(30);
  // reset the milliseconds to make sure the clock is counting from 20.0s
  clkTime.resetMilliseconds();

  // => time now: 23h:59m:30s
}
void loop() 
{
  Serial.print("absolute time:");
  Serial.println(clkTime.getPhrasedAbsoluteTime());

  Serial.print("relative time:");
  Serial.println(clkTime.getPhrasedTime());

  Serial.println("---");

  delay(1000);
}