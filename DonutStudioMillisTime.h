/*
  DonutStudioMillisTime.h - Library for using the millis-function of the arduino to create a clock
  Created by Donut Studio, Febuary 07, 2023.
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
    // constructor for the class with the relative time to start from: default=12h:00m:00s
    MillisTime(int hour = 12, int minute = 0, int second = 0);

    /*
      --- METHODS ---
    */
    // recalculate the current duration between the last day and current time
    void refreshDuration();
    // resets the time to 00h:00m:00s and restarts to count
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

    // set the hour
    void setHour(int hour);
    // set the minute
    void setMinute(int minute);
    // set the second
    void setSecond(int second);

    // returns true if the relative time is AM
    bool isAM();
    // returns true if the relative time is PM
    bool isPM();

    
    // get the hour addition (for relative time)
    int getAdditionHour();
    // get the minute addition (for relative time)
    int getAdditionMinute();
    // get the second addition (for relative time)
    int getAdditionSecond();
    // get the relative time(in seconds) by adding the additions onto the absolute time
    unsigned long getAdditionTime();

    // set the hour addition (for relative time)
    void setAdditionHour(int additionHour);
    // set the minute addition (for relative time)
    void setAdditionMinute(int additionMinute);
    // set the second addition (for relative time)
    void setAdditionSecond(int additionSecond);
    

    // returns the current time phrased into the following format: hh:mm:ss
    String getPhrasedTime(bool twelveFormat = false);
    // returns the current hours phrased into the following format: hh
    String getPhrasedHours(bool twelveFormat = false);
    // returns the current minutes phrased into the following format: mm
    String getPhrasedMinutes();
    // returns the current seconds phrased into the following format: ss
    String getPhrasedSeconds();
  /*
    --- PRIVATE ---
  */
  private:
    /*
      --- VARIABLES ---
    */
    unsigned long _duration = 0;
    unsigned long _previousDay = 0;

    unsigned int _hourAddition = 0; // to save space this variable can also be a byte
    unsigned int _minuteAddition = 0; // to save space this variable can also be a byte
    unsigned int _secondAddition = 0; // to save space this variable can also be a byte
};
#endif