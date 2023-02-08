# SEVEN SEGMENT DISPLAY CONTROLLER LIBRARY README
Welcome!
This is my solution for using the millis function to create a clock.
Keep in mind that the oscillator of the arduino is not very preciced.
I recommend to use a real-time-clock if you got the space/pins left.
If you have the chance to update the time from the internet 
and just want to count on for a few hours, this library is perfect!
Feel free to use it anywere in your projects.
Cheers, Donut Studio!


***
# Features
- get the time in hours, minutes and seconds without having to use an rtc
- set the time
- get am/pm and the time in the 12 hour format
- get phrased time strings


***
# Installation
1. download the `DonutStudioMillisTime` folder and extract it into the libraries folder of the Arduino Software
2. start your arduino ide and open the example sketch at `File/Examples/DonutStudioMillisTime/MillisTimeTest.ino`
3. upload the sketch and watch


***
# Usage
To use the library you have to include it in your sketch and create an object of the MillisTime class. 
With that object you can call different functions which will give you information about the time and allows you to adjust it easily.
There are two time types:
- absolute (can't be set, will start at boot: 00h:00m:00s to 23h:59m:59s)
- relative (can be set, will be relative(by an adjustable addition) to the absolute time)

Sample code:
```cpp
// include the libraray
#include "DonutStudioMillisTime.h"
// create an object of the time class and set the time to 12h:00m:00s
MillisTime clkTime = MillisTime(12, 0, 0); 

// set the minute to 40
clkTime.setMinute(40);
// set the second to 20
clkTime.setSecond(20);

// returns the relative hours as an int
int h = clkTime.getHours();
```


***
# Documentation
CONSTRUCTOR
- `MillisTime(int hour = 12, int minute = 0, int second = 0);` => constructor for the class with the relative time to start from, default=12h:00m:00s

ABSOLUTE TIME
- `int getAbsoluteHours();` => get the absolute hours(0-23)
- `int getAbsoluteMinutes();` => get the absolute minutes(0-59)
- `int getAbsoluteSeconds();` => get the absolute seconds(0-59)
- `bool isAbsoluteTime(int hour, int minute, int second);` => check if the absolute time is equal to the given time
- `bool isAbsoluteHour(int hour);` => check if the absolute hour is equal to the given hour
- `bool isAbsoluteMinute(int minute);` => check if the absolute minute is equal to the given minute
- `bool isAbsoluteSecond(int second);` => check if the absolute second is equal to the given second

RELATIVE TIME
- `int getHours();` => get the relative hours(0-23)
- `int getHours12();` => get the relative hours(0-12)
- `int getMinutes();` => get the relative minutes(0-59)
- `int getSeconds();` => get the relative seconds(0-59)
- `bool isAM();` => returns true if the relative time is AM
- `bool isPM();` => returns true if the relative time is PM
- `bool isTime(int hour, int minute, int second);` => check if the relative time is equal to the given time
- `bool isHour(int hour);` => check if the relative hour is equal to the given hour
- `bool isMinute(int minute);` => check if the relative minute is equal to the given minute
- `bool isSecond(int second);` => check if the relative second is equal to the given second

SET TIME
- `void setHour(int hour);` => set the hour
- `void setMinute(int minute);` => set the minute
- `void setSecond(int second);` => set the second

RELATIVE ADDITION
- `void setAdditionHour(int additionHour);` => set the hour addition (for relative time)
- `void setAdditionMinute(int additionMinute);` => set the minute addition (for relative time)
- `void setAdditionSecond(int additionSecond);`=> set the second addition (for relative time)
- `int getAdditionHour();` => get the hour addition (for relative time)
- `int getAdditionMinute();` => get the minute addition (for relative time)
- `int getAdditionSecond();` => get the second addition (for relative time)
- `unsigned long getAdditionTime();` => get the relative time(in seconds) by adding the additions onto the absolute time

PHRASED TIME ABSOLUTE
- `String getPhrasedAbsoluteTime();` => returns the absolute time phrased into the following format: hh:mm:ss
- `String getPhrasedAbsoluteHours();` => returns the absolute hours phrased into the following format: hh
- `String getPhrasedAbsoluteMinutes();` => returns the absolute minutes phrased into the following format: mm
- `String getPhrasedAbsoluteSeconds();` => returns the absolute seconds phrased into the following format: ss

PHRASED TIME RELATIVE
- `String getPhrasedTime(bool twelveFormat = false);` => returns the current time phrased into the following format: hh:mm:ss
- `String getPhrasedHours(bool twelveFormat = false);` => returns the current hours phrased into the following format: hh
- `String getPhrasedMinutes();` => returns the current minutes phrased into the following format: mm
- `String getPhrasedSeconds();` => returns the current seconds phrased into the following format: ss

OTHER
- `void refreshDuration();` => recalculate the current duration between the last day and current time
- `void resetTime();` => resets the time to 00h:00m:00s and restarts to count


***
# Credits
DonutStudioMillisTime.h - Library for using the millis-function of the arduino to create a clock
Created by Donut Studio, Febuary 08, 2023.
Released into the public domain.