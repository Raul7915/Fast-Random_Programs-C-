#include <iostream>
using std::cout;
#include "Date.h"

Date::Date(int d, int mh, int y)
{
    day = d;
    month = mh;
    year = y;

}

Date::Date()
{
    day=month=year=0;
}
int Date::getDay()
{
    return day;
}

int Date::getMonth()
{

    return month;
}

int Date::getYear()
{

    return year;
}

void Date::print()
{
     cout << "\n Data: " << (day < 10 ? "0" : "") << day << '-' << (month<10 ? "0" : "")<< month << '-' << year;
    cout<<getDay()<<'-'<<getMonth()<<'-'<<getYear();
}
