#include <iostream>
using namespace std;

class Time
{
    protected:
        int hour;
        int minute;
        int second;

    public:
        Time(int h, int m, int s)
        {
            setTime(h, m, s);
        }

        void setTime(int h, int m, int s)
        {
            hour = (h >= 0 && h < 24) ? h : 0;
            minute = (m >= 0 && m < 60) ? m : 0;
            second = (s >= 0 && s < 60) ? s : 0;
        }
      friend ostream& operator<<(ostream& os, const Time& t);
};

 ostream& operator<<(ostream& os, const Time& t)
{
    return os << (t.hour < 10 ? "0" : "") << t.hour << ":" << (t.minute < 10 ? "0" : "") << t.minute << ":" << (t.second < 10 ? "0" : "") << t.second;
}

class DateTime : public Time
{
        int day;
        int month;
        int year;

    public:
        DateTime(int d = 0, int mo = 0, int y = 0, int h = 0, int m = 0, int s = 0)
            : Time(h, m, s)
        {
            day = d;
            year = y;
            month = mo;
        }
       friend ostream& operator<<(ostream& os, const DateTime& c);
};

ostream& operator<<(ostream& os, const DateTime& dateTime)
{
	return os << dateTime.day << '-' << dateTime.month << '-' << dateTime.year << " "
			  << (dateTime.hour < 10 ? "0" : "") << dateTime.hour << ":"
			  << (dateTime.minute < 10 ? "0" : "") << dateTime.minute;
}

int main()
{
	Time t(10, 12, 15);
	  cout << t << endl;

	DateTime date(5, 4, 2022, 16, 15, 13);
	  cout << date << endl;

	return 0;
}
