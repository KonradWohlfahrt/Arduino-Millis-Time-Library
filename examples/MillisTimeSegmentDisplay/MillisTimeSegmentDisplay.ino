/*
  DonutStudioMillisTime.h - Library for using the millis-function of the arduino to create a clock
  Created by Donut Studio, Febuary 08, 2023.
  Released into the public domain.
*/

// include the librarys
#include "DonutStudioMillisTime.h"

// this library can be found here: https://github.com/Donut-Studio/Arduino-Seven-Segment-Controller
// instruction on the usage: https://www.instructables.com/Using-a-Seven-Segment-Display-Library-for-Arduino/
#include "DonutStudioSevenSegment.h"

// define the ground pins 
int gnd[] = { 3, 5, 6, 9 };
// create an object of the SegmentController class and define the segment, ground pins and display length.
SegmentController disp = SegmentController(2, 4, 10, 7, 11, 8, 12, 13, gnd, 4);

// create an object of the time class
MillisTime clkTime = MillisTime(); 

int index = 0;
unsigned long previous;

void setup() 
{
  // start the serial port
  Serial.begin(9600);

  disp.initialize(true);

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
  if (millis() - previous >= 500) 
  {
    Serial.print("absolute time:");
    Serial.println(clkTime.getPhrasedAbsoluteTime());

    Serial.print("relative time:");
    Serial.println(clkTime.getPhrasedTime());

    Serial.println("---");

    index = (index + 1) % 5;
    if (index == 0) 
      disp.clearDisplay();
    else if (index == 1)
      disp.setString(clkTime.getPhrasedAbsoluteHours() + clkTime.getPhrasedAbsoluteMinutes());
    else if (index == 2)
      disp.setString(clkTime.getPhrasedAbsoluteSeconds());
    else if (index == 3)
      disp.setString(clkTime.getPhrasedHours() + clkTime.getPhrasedMinutes());
    else if (index == 4)
      disp.setString(clkTime.getPhrasedSeconds());

    previous = millis();
  }
  disp.refreshDisplay();
}