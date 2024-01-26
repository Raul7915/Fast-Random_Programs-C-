#ifndef DATAPOINT_H
#define DATAPOINT_H
#include "Date.h"
#include "TimeSeries.h"


class DataPoint
{

    public:
        DataPoint(int , int , int, double );
        DataPoint(Date, double);
        DataPoint();
        Date getTimeStamp();
        TimeSeries getTime();
        double getValue();


    private:
    Date TimeStamp;
    TimeSeries Time;
        double value;
        friend class TimeSeries;


};

#endif // DATAPOINT_H

