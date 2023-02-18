/*
  DonutStudioMillisTime.h - Library for using the millis-function of the arduino to create a clock
  Created by Donut Studio, Febuary 18, 2023.
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
    // constructor for the class with the relative time to start from, default=12h:00m:00s
    MillisTime(int hour = 12, int minute = 0, int second = 0);

    /*
      --- METHODS ---
    */

    /*-- absolute time --*/

    // get the absolute hours(0-23)
    int getAbsoluteHours();
    // get the absolute minutes(0-59)
    int getAbsoluteMinutes();
    // get the absolute seconds(0-59)
    int getAbsoluteSeconds();

    // check if the absolute time is equal to the given time
    bool isAbsoluteTime(int hour, int minute, int second);
    // check if the absolute hour is equal to the given hour
    bool isAbsoluteHour(int hour);
    // check if the absolute minute is equal to the given minute
    bool isAbsoluteMinute(int minute);
    // check if the absolute second is equal to the given second
    bool isAbsoluteSecond(int second);


    /*-- relative time --*/

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
    // check if the relative time is equal to the given time
    bool isTime(int hour, int minute, int second);
    // check if the relative hour is equal to the given hour
    bool isHour(int hour);
    // check if the relative minute is equal to the given minute
    bool isMinute(int minute);
    // check if the relative second is equal to the given second
    bool isSecond(int second);


    /*-- set time --*/

    // set the hour
    void setHour(int hour);
    // set the minute
    void setMinute(int minute);
    // set the second
    void setSecond(int second);
    // set the milliseconds of the relative time back to 0
    void resetMilliseconds();


    /*-- relative addition --*/

    // set the hour addition (for relative time)
    void setAdditionHour(int additionHour);
    // set the minute addition (for relative time)
    void setAdditionMinute(int additionMinute);
    // set the second addition (for relative time)
    void setAdditionSecond(int additionSecond);

    // get the hour addition (for relative time)
    int getAdditionHour();
    // get the minute addition (for relative time)
    int getAdditionMinute();
    // get the second addition (for relative time)
    int getAdditionSecond();
    // get the relative time(in seconds) by adding the additions onto the absolute time
    unsigned long getAdditionTime();


    /*-- phrased time absolute --*/

    // returns the absolute time phrased into the following format: hh:mm:ss
    String getPhrasedAbsoluteTime();
    // returns the absolute hours phrased into the following format: hh
    String getPhrasedAbsoluteHours();
    // returns the absolute minutes phrased into the following format: mm
    String getPhrasedAbsoluteMinutes();
    // returns the absolute seconds phrased into the following format: ss
    String getPhrasedAbsoluteSeconds();


    /*-- phrased time relative --*/

    // returns the current time phrased into the following format: hh:mm:ss
    String getPhrasedTime(bool twelveFormat = false);
    // returns the current hours phrased into the following format: hh
    String getPhrasedHours(bool twelveFormat = false);
    // returns the current minutes phrased into the following format: mm
    String getPhrasedMinutes();
    // returns the current seconds phrased into the following format: ss
    String getPhrasedSeconds();


    /*-- other --*/

    // recalculate the current duration between the last day and current time
    void refreshDuration();
    // resets the time to 00h:00m:00s and restarts to count
    void resetTime();
  /*
    --- PRIVATE ---
  */
  private:
    /*
      --- VARIABLES ---
    */
    unsigned long _duration = 0;
    unsigned long _previousDay = 0;

    int _hourAddition = 0; // to save space this variable can also be a byte
    int _minuteAddition = 0; // to save space this variable can also be a byte
    int _secondAddition = 0; // to save space this variable can also be a byte
};
#endif