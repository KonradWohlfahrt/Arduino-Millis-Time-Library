/*
  DonutStudioMillisTime.h - Library to utilize the millis function as a clock
  Created by Donut Studio, March 11, 2024.
  Released into the public domain.
*/

// include the libraray
#include <DonutStudioMillisTime.h>

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

  // => time now: 23h:59m:30s
}
void loop() 
{
  int absHrs = clkTime.getAbsoluteHours();
  int absMin = clkTime.getAbsoluteMinutes();
  int absSec = clkTime.getAbsoluteSeconds();

  String hrs = absHrs < 10 ? "0" + String(absHrs) : String(absHrs);
  String min = absMin < 10 ? "0" + String(absMin) : String(absMin);
  String sec = absSec < 10 ? "0" + String(absSec) : String(absSec);

  Serial.print("absolute time:");
  Serial.print(hrs);
  Serial.print(":");
  Serial.print(min);
  Serial.print(":");
  Serial.println(sec);

  Serial.print("relative time:");
  Serial.println(clkTime.getPhrasedTime());

  Serial.println("---");

  delay(1000);
}