#include <iostream>
#include <fstream>
#include "Date.h"
#include "DataPoint.h"
#include "TimeSeries.h"
#include <vector>
using namespace std;


int main()
{
   TimeSeries aapl;

   aapl.loadFromFile("AAPL3.txt");
    cout << "AAPL size: " <<aapl.getTs().size() << endl;
    cout << "AAPL Mean: " << aapl.tsMean() << endl;
    cout << "AAPL Max: " << aapl.tsMax() << endl;
    cout << "AAPL Min: " << aapl.tsMin() << endl;

   TimeSeries dtaapl = aapl.tsDetrend();
    cout << "Detrended size: " << dtaapl.getTs().size() << endl;
    cout << "Detrended AAPL Mean: " << dtaapl.tsMean() << endl;
    cout << "Detrended AAPL Max: " << dtaapl.tsMax() << endl;
    cout << "Detrended AAPL Min: " << dtaapl.tsMin() << endl;




    TimeSeries Z(10, 9, 45);

    Z.getTime();





}

