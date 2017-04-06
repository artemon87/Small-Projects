#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <stdio.h>
using namespace std;


class TimeSpan
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    TimeSpan();
    TimeSpan(int);
    TimeSpan(int, int);
    TimeSpan(int, int, int);
    const int getHours()const;
    const int getMinutes()const;
    const int getSeconds()const;
    void setHours(int);
    void setMinutes(int);
    void setSoconds(int);
    void cast(int &, int &, int &);
    TimeSpan operator+(const TimeSpan)const;
    TimeSpan operator-(const TimeSpan)const;
    TimeSpan operator+=(const TimeSpan);
    TimeSpan operator-=(const TimeSpan);
    TimeSpan operator==(const TimeSpan)const;
    TimeSpan operator!=(const TimeSpan)const;

    /*friend*/ friend ostream & operator<< (ostream &, const TimeSpan &);
    /*friend*/ friend istream & operator>> (istream &, TimeSpan &);

};


#endif /* defined(__TimeSpan__TimeSpan__) */
