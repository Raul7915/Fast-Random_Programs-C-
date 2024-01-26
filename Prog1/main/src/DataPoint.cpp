#include "DataPoint.h"
#include <iostream>
#include "Date.h"

DataPoint::DataPoint(int d, int m, int y, double v)
{
    TimeStamp.day = d;
    TimeStamp.month = m;
    TimeStamp.year = y;
    value = v;
}

Date DataPoint::getTimeStamp()
{
   // TimeStamp.getDay();
    //TimeStamp.getMonth();
    //TimeStamp.getYear();
    return TimeStamp;
}

DataPoint::DataPoint(TimeSeries Z)
{
    Time= Z;
}

TimeSeries DataPoint::getTime()
{
    return Time;
}

DataPoint::DataPoint(Date d, double v)
{
    TimeStamp= d;
    value=v;
}
double DataPoint::getValue()
{
    return value;
}

DataPoint::DataPoint()
{
    // TimeStamp.day=TimeStamp.month= TimeStamp.year = value=0;
}

