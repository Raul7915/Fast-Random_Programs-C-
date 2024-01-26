#ifndef TIMESERIES_H
#define TIMESERIES_H
#include "DataPoint.h"
#include <fstream>
#include <vector>
using namespace std;

class TimeSeries
{
    public:
        TimeSeries(int, int, int);
        TimeSeries();
         void loadFromFile(string);
        double tsMean();
        double tsMax();
        double tsMin();
        TimeSeries tsDetrend();
        vector<DataPoint>getTs();
        vector<DataPoint>setTs();
        void print();


          int hour;
       int minute;
       int second;

    private:

       vector<DataPoint> ts;

       friend class DataPoint;
};

#endif
