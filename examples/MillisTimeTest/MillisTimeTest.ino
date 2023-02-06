/*
  DonutStudioMillisTime.h - Library for using the millis-function of the arduino to create a clock
  Created by Donut Studio, Febuary 06, 2023.
  Released into the public domain.
*/

// include the libraray
#include "DonutStudioMillisTime.h"

// create an object of the time class and set the time to 12h:00m:00s
MillisTime time = MillisTime(12, 0, 0); 

void setup() 
{
  // start the serial port
  Serial.begin(9600);

  // set the minute to 40
  time.setMinute(40);
  // set the second to 20
  time.setSecond(20);

  // => time now: 12h:40m:20s
}
void loop() 
{
  int h = time.getAbsoluteHours();
  int m = time.getAbsoluteMinutes();
  int s = time.getAbsoluteSeconds();

  Serial.print("absolute time:");
  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.println(s);



  h = time.getHours();
  m = time.getMinutes();
  s = time.getSeconds();

  Serial.print("relative time:");
  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.println(s);



  Serial.println();
}