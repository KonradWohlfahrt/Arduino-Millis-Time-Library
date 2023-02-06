/*
  DonutStudioMillisTime.h - Library for using the millis-function of the arduino to create a clock
  Created by Donut Studio, Febuary 06, 2023.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DonutStudioMillisTime.h"

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


int MillisTime::getHours()
{
  // return the relative hours
  return (getAbsoluteHours() + _hourAddition) % 24;
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
  // return the relative minutes
  return (getAbsoluteMinutes() + _minuteAddition) % 60;
}
int MillisTime::getSeconds()
{
  // return the relative seconds
  return (getAbsoluteSeconds() + _secondAddition) % 60;
}

bool MillisTime::isAM()
{
  return getHours() < 13;
}
bool MillisTime::isPM()
{
  return getHours() > 12;
}


void MillisTime::setHour(unsigned int hour)
{
  // set the hour to the 0-23 format
  hour = hour % 24;
  // get the current hours
  int h = getAbsoluteHours();
  // calculate and set the addition for the relative hour
  _hourAddition = (24 - h) + hour;
}
void MillisTime::setMinute(unsigned int minute)
{
  // set the minute to the 0-59 format
  minute = minute % 60;
  // get the current minutes
  int m = getAbsoluteMinutes();
  // calculate and set the addition for the relative hour
  _minuteAddition = (60 - m) + minute;
}
void MillisTime::setSecond(unsigned int second)
{
  // set the seconds to the 0-59 format
  second = second % 60;
  // get the current seconds
  int s = getAbsoluteSeconds();
  // calculate and set the addition for the relative hour
  _secondAddition = (60 - s) + second;
}


int MillisTime::getAdditionHour()
{
  return _hourAddition;
}
int MillisTime::getAdditionMinute()
{
  return _minuteAddition;
}
int MillisTime::getAdditionSecond()
{
  return _secondAddition;
}

void MillisTime::setAdditionHour(int additionHour)
{
  _hourAddition = additionHour;
}
void MillisTime::setAdditionMinute(int additionMinute)
{
  _minuteAddition = additionMinute;
}
void MillisTime::setAdditionSecond(int additionSecond)
{
  _secondAddition = additionSecond;
}