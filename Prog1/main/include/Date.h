#ifndef DATE_H
#define DATE_H


class Date
{
    public:

        Date(int, int, int );
        Date();
        int getDay();
        int getMonth();
        int getYear();
        void print();



    private:
        int day;
        int month;
        int year;
        friend class DataPoint;
        friend class TimeSeries;
};
#endif
