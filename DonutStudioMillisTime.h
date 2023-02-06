/*
  DonutStudioMillisTime.h - Library for using the millis-function of the arduino to create a clock
  Created by Donut Studio, Febuary 06, 2023.
  Released into the public domain.
*/

#ifndef DonutStudioMillisTime.h
#define DonutStudioMillisTime.h

#include "Arduino.h"


class MillisTime
{
  /*
    --- PUBLIC ---
  */
  public:
    /*
      --- CONSTRUCTOR ---
    */
    // constructor for the class with the relative time to start from
    MillisTime(int hour = 12, int minute = 0, int second = 0);

    /*
      --- METHODS ---
    */
    // recalculate the current duration between the last day and current time
    void refreshDuration();
    // resets the time to 00:00:00 and restarts to count
    void resetTime();


    // get the hours(0-23) beginning from the start of the program
    int getAbsoluteHours();
    // get the minutes(0-59) beginning from the start of the program
    int getAbsoluteMinutes();
    // get the seconds(0-59) beginning from the start of the program
    int getAbsoluteSeconds();


    // get the relative hours(0-23)
    int getHours();
    // get the relative hours(0-12)
    int getHours12();
    // get the relative minutes(0-59)
    int getMinutes();
    // get the relative seconds(0-59)
    int getSeconds();

    // returns true if the relative time is AM
    bool isAM();
    // returns true if the relative time is PM
    bool isPM();


    // set the hour
    void setHour(unsigned int hour);
    // set the minute
    void setMinute(unsigned int minute);
    // set the second
    void setSecond(unsigned int second);

    
    // get the hour addition (for relative time)
    void getAdditionHour();
    // get the minute addition (for relative time)
    void getAdditionMinute();
    // get the second addition (for relative time)
    void getAditionSecond();

    // set the hour addition (for relative time)
    void setAdditionHour(int additionHour);
    // set the minute addition (for relative time)
    void setAdditionMinute(int additionMinute);
    // set the second addition (for relative time)
    void setAditionSecond(int additionSecond);
  /*
    --- PRIVATE ---
  */
  private:
    /*
      --- VARIABLES ---
    */
    unsigned long _duration = 0;
    unsigned long _previousDay = 0;

    int _hourAddition = 0;
    int _minuteAddition = 0;
    int _secondAddition = 0;
};
#endif