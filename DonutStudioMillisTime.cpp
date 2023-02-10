/*
  DonutStudioMillisTime.h - Library for using the millis-function of the arduino to create a clock
  Created by Donut Studio, Febuary 10, 2023.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DonutStudioMillisTime.h"

/*
  --- CONSTRUCTOR ---
*/

MillisTime::MillisTime(int hour, int minute, int second)
{
  // recalculate the duration
  refreshDuration();

  // set hours, minutes, seconds
  if (hour != 0)
    setHour(hour);
  if (minute != 0)
    setMinute(minute);
  if (second != 0)
    setSecond(second);
}


/*
  --- ABSOLUTE TIME ---
*/

int MillisTime::getAbsoluteHours()
{
  // recalculate the duration
  refreshDuration();
  // calculate the seconds of the day
  unsigned long seconds = _duration / 1000;
  // return the hours
  return (seconds / 3600) % 24;
}
int MillisTime::getAbsoluteMinutes()
{
  // recalculate the duration
  refreshDuration();
  // calculate the seconds of the day
  unsigned long seconds = _duration / 1000;
  // return the minutes
  return (seconds / 60) % 60;
}
int MillisTime::getAbsoluteSeconds()
{
  // recalculate the duration
  refreshDuration();
  // calculate the seconds of the day
  unsigned long seconds = _duration / 1000;
  // return the seconds
  return seconds % 60;
}

bool MillisTime::isAbsoluteTime(int hour, int minute, int second)
{
  return isAbsoluteHour(hour) && isAbsoluteMinute(minute) && isAbsoluteSecond(second);
}
bool MillisTime::isAbsoluteHour(int hour)
{
  return getAbsoluteHours() == hour;
}
bool MillisTime::isAbsoluteMinute(int minute)
{
  return getAbsoluteMinutes() == minute;
}
bool MillisTime::isAbsoluteSecond(int second)
{
  return getAbsoluteSeconds() == second;
}

/*
  --- RELATIVE TIME ---
*/

int MillisTime::getHours()
{
  // get the relative time in seconds
  unsigned long seconds = getAdditionTime();
  // return the relative hours
  return (seconds / 3600) % 24;
}
int MillisTime::getHours12()
{
  // get the current hours
  int h = getHours();
  // calculate the 12 hour format
  return h > 12 ? (h - 12) : h;
}
int MillisTime::getMinutes()
{
  // get the relative time in seconds
  unsigned long seconds = getAdditionTime();
  // return the relative minutes
  return (seconds / 60) % 60;
}
int MillisTime::getSeconds()
{
  // get the relative time in seconds
  unsigned long seconds = getAdditionTime();
  // return the relative seconds
  return seconds % 60;
}

bool MillisTime::isAM()
{
  return getHours() < 13;
}
bool MillisTime::isPM()
{
  return getHours() > 12;
}

bool MillisTime::isTime(int hour, int minute, int second)
{
  return isHour(hour) && isMinute(minute) && isSecond(second);
}
bool MillisTime::isHour(int hour)
{
  return getHours() == hour;
}
bool MillisTime::isMinute(int minute)
{
  return getMinutes() == minute;
}
bool MillisTime::isSecond(int second)
{
  return getSeconds() == second;
}


/*
  --- SET ---
*/

void MillisTime::setHour(int hour)
{
  // check if the hour is below 0, set it to 23
  if (hour < 0)
    hour = 23;
  // set the hour to the 0-23 format
  hour = hour % 24;
  // get the current hours
  int h = getAbsoluteHours();
  // calculate and set the addition for the relative hour
  setAdditionHour((24 - h) + hour);
}
void MillisTime::setMinute(int minute)
{
  // check if the minute is below 0, set it to 59
  if (minute < 0)
    minute = 59;
  // set the minute to the 0-59 format
  minute = minute % 60;
  // get the current minutes
  int m = getAbsoluteMinutes();
  // calculate and set the addition for the relative minute
  setAdditionMinute((60 - m) + minute);
}
void MillisTime::setSecond(int second)
{
  // check if the second is below 0, set it to 59
  if (second < 0)
    second = 59;
  // set the seconds to the 0-59 format
  second = second % 60;
  // get the current seconds
  int s = getAbsoluteSeconds();
  // calculate and set the addition for the relative second
  setAdditionSecond((60 - s) + second);
}
void MillisTime::resetMilliseconds()
{
  // recalculate the duration
  refreshDuration();
  // add the milliseconds that are left to get to 0
  _previousDay += 1000 -(millis() % 1000);
}

/*
  --- RELATIVE ADDITION ---
*/

void MillisTime::setAdditionHour(int additionHour)
{
  // check if the addition hours are below 0, set them to 23
  if (additionHour < 0)
    additionHour = 23;
  // set the addition hours (0-23)
  _hourAddition = additionHour % 24;
}
void MillisTime::setAdditionMinute(int additionMinute)
{
  // check if the addition minutes are below 0, set them to 59
  if (additionMinute < 0)
    additionMinute = 59;
  // set the addition minutes (0-59)
  _minuteAddition = additionMinute % 60;
}
void MillisTime::setAdditionSecond(int additionSecond)
{
  // check if the addition seconds are below 0, set them to 59
  if (additionSecond < 0)
    additionSecond = 59;
  // set the addition seconds (0-59)
  _secondAddition = additionSecond % 60;
}

int MillisTime::getAdditionHour()
{
  // return the hour addition value
  return _hourAddition;
}
int MillisTime::getAdditionMinute()
{
  // return the minute addition value
  return _minuteAddition;
}
int MillisTime::getAdditionSecond()
{
  // return the second addition value
  return _secondAddition;
}
unsigned long MillisTime::getAdditionTime()
{
  // recalculate the duration
  refreshDuration();
  // calculate the seconds of the day and add the time
  unsigned long seconds = _duration / 1000;
  seconds += (long)_secondAddition;
  seconds += (long)_minuteAddition * 60;
  seconds += (long)_hourAddition * 3600;
  return seconds;
}


/*
  --- PHRASED TIME ABSOLUTE ---
*/

String MillisTime::getPhrasedAbsoluteTime()
{
  // get the hours
  String h = getPhrasedAbsoluteHours();
  // geth the minutes
  String m = getPhrasedAbsoluteMinutes();
  // get the seconds
  String s = getPhrasedAbsoluteSeconds();
  // phrase them into the hh:mm:ss format
  return h + ":" + m + ":" + s;
}
String MillisTime::getPhrasedAbsoluteHours()
{
  // get the hours
  int h = getAbsoluteHours();
  // phrase and return the hours
  return h < 10 ? "0" + String(h) : String(h);
}
String MillisTime::getPhrasedAbsoluteMinutes()
{
  // get the minutes
  int m = getAbsoluteMinutes();
  // phrase and return the minutes
  return m < 10 ? "0" + String(m) : String(m);
}
String MillisTime::getPhrasedAbsoluteSeconds()
{
  // get the minutes
  int s = getAbsoluteSeconds();
  // phrase and return the minutes
  return s < 10 ? "0" + String(s) : String(s);
}


/*
  --- PHRASED TIME RELATIVE ---
*/

String MillisTime::getPhrasedTime(bool twelveFormat)
{
  // get the hours
  String h = getPhrasedHours(twelveFormat);
  // geth the minutes
  String m = getPhrasedMinutes();
  // get the seconds
  String s = getPhrasedSeconds();
  // phrase them into the hh:mm:ss format
  return h + ":" + m + ":" + s;
}
String MillisTime::getPhrasedHours(bool twelveFormat)
{
  // get the hours
  int h = 0;
  if (twelveFormat)
    h = getHours12();
  else
    h = getHours();
  // phrase and return the hours
  return h < 10 ? "0" + String(h) : String(h);
}
String MillisTime::getPhrasedMinutes()
{
  // get the minutes
  int m = getMinutes();
  // phrase and return the minutes
  return m < 10 ? "0" + String(m) : String(m);
}
String MillisTime::getPhrasedSeconds()
{
  // get the seconds
  int s = getSeconds();
  // phrase and return the seconds
  return s < 10 ? "0" + String(s) : String(s);
}


/*
  --- OTHER ---
*/

void MillisTime::refreshDuration()
{
  // get the current millis value
  unsigned long currentTime = millis();
  // calculate the duration between the current time and the previous day, prevent the overflow problem of millis
  _duration = currentTime - _previousDay;

  // check if a new day already started 1day = 24hours = 1.440minutes = 86.400seconds = 86.400.000milliseconds
  if (_duration >= 86400000)
  {
    // recalculate the time elapsed from the last day
    _duration = _duration % 86400000;
    // set the time stamp of the last day
    _previousDay = currentTime - _duration;
  }
}
void MillisTime::resetTime()
{
  _previousDay = millis();
  refreshDuration();
}