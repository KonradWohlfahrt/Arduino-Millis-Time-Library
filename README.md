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


***
# Installation
1. download the `DonutStudioMillisTime` folder and extract it into the libraries folder of the Arduino Software
2. start your arduino ide and open the example sketch at `File/Examples/DonutStudioMillisTime/MillisTimeTest.ino`
3. upload the sketch and watch


***
# Usage
To use the library you have to include it in your sketch
and create an object of the MillisTime class. With that variable you can perform the time setting process and get the elapsed time. To prevent the millis overflow problem you should call `refreshDuration()` or the get methods for the time at least once a day.
```cpp
// include the libraray
#include "DonutStudioMillisTime.h"
// create an object of the time class and set the time to 12h:00m:00s
MillisTime time = MillisTime(12, 0, 0); 

// set the minute to 40
time.setMinute(40);
// set the second to 20
time.setSecond(20);
```


***
# Documentation
CONSTRUCTOR
- `MillisTime(int hour = 12, int minute = 0, int second = 0);` => constructor for the class with the relative time to start from
Methods
- `void refreshDuration();` => recalculate the current duration between the last day and current time
- `void resetTime();` => resets the time to 00h:00m:00s and restarts to count
- `int getAbsoluteHours();` => get the hours(0-23) beginning from the start of the program
- `int getAbsoluteMinutes();` => get the minutes(0-59) beginning from the start of the program
- `int getAbsoluteSeconds();` => get the seconds(0-59) beginning from the start of the program
- `int getHours();` => get the relative hours(0-23)
- `int getHours12();` => get the relative hours(0-12)
- `int getMinutes();` => get the relative minutes(0-59)
- `int getSeconds();` => get the relative seconds(0-59)
- `bool isAM();` => returns true if the relative time is AM
- `bool isPM();` => returns true if the relative time is PM
- `void setHour(unsigned int hour);` => set the hour
- `void setMinute(unsigned int minute);` => set the minute
- `void setSecond(unsigned int second);` => set the second
- `void getAdditionHour();` => get the hour addition (for relative time)
- `void getAdditionMinute();` => get the minute addition (for relative time)
- `void getAditionSecond();` => get the second addition (for relative time)
- `void setAdditionHour(int additionHour);` => set the hour addition (for relative time)
- `void setAdditionMinute(int additionMinute);` => set the minute addition (for relative time)
- `void setAditionSecond(int additionSecond);`=> set the second addition (for relative time)


***
# Credits
DonutStudioMillisTime.h - Library for using the millis-function of the arduino to create a clock
Created by Donut Studio, Febuary 06, 2023.
Released into the public domain.