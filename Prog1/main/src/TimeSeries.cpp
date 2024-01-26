#include "TimeSeries.h"
#include <iostream>
#include "DataPoint.h"
#include <vector>
#include <fstream>
#include "Date.h"

using namespace std;

TimeSeries::TimeSeries()
{

}

void TimeSeries::loadFromFile(string filePath)
{
	ifstream f(filePath);
	int i = 0;
	while (!f.eof())
	{
		DataPoint t;
		f >>t.TimeStamp.day;
		f >> t.TimeStamp.month;
		f >> t.TimeStamp.year;
		f >> t.value;
		ts.push_back(t);

		//cout << ts.back().TimeStamp.day << " " << ts.back().TimeStamp.month << " " << ts.back().TimeStamp.year << " " << ts.back().value << endl;
	}
	//ts.pop_back();
}

double TimeSeries::tsMax()
{
	double max = ts[0].value;
	for (int i = 1; i < 73; i++)
	{
		if (max < ts[i].value)
			max = ts[i].value;
	}
	return max;
}

double TimeSeries::tsMin()
{
	double min = ts[0].value;
	for (int i = 1; i < 73; i++)
	{
		if (min > ts[i].value)
			min = ts[i].value;
	}
	return min;
}
double TimeSeries::tsMean()
{
	double sumValue = 0;
	if (ts.size() > 0)
	{
		for (DataPoint i : ts)
			sumValue += i.getValue();
		return sumValue / ts.size();
	}
	return 0;

}


vector<DataPoint> TimeSeries::setTs()
{
   // vector<DataPoint> v;
	for ( int i = 0; i < 72; i++)
		ts[i].value = ts[i].value;


}

TimeSeries TimeSeries::tsDetrend()
    {
        TimeSeries x;
        for (int i = 1; i < ts.size(); i++)

            x.ts.push_back(DataPoint(ts[i].getTimeStamp(), ts[i].getValue() - ts[i - 1].getValue()));
        return x;
    }


vector <DataPoint> TimeSeries::getTs()
{
	return ts;
}

TimeSeries::TimeSeries(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;

}


void TimeSeries::print()
{
     cout << "\n ORA: " << (hour < 10 ? "0" : "") << hour << ':' << (minute<10 ? "0" : "")<< minute << ':' << (second<10 ? "0" : "")<< second;

}
