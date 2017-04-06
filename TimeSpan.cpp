#include "TimeSpan.h"
#include <iostream>

using namespace std;

TimeSpan::TimeSpan()
{
    
}
TimeSpan::TimeSpan(int sec)
{
    seconds=sec;
    cast(hours, minutes, seconds);
}

TimeSpan::TimeSpan(int min, int sec)
{
    seconds=sec;
    minutes=min;
    cast(hours, minutes, seconds);
}
TimeSpan::TimeSpan(int hour, int min, int sec)
{
    hours=hour;
    minutes=min;
    seconds=sec;
    cast(hours, minutes, seconds);
}
int TimeSpan:: getHours()const
{
    cout<<hours;
    return hours;
}

int TimeSpan:: getMinutes()const
{
    cout<<minutes;
    return minutes;
}

int TimeSpan::getSeconds()const
{
    return seconds;
}
void TimeSpan::setHours(int hour)
{
    hours=hour;
}

void TimeSpan::setMinutes(int min)
{
    minutes=min;
}

void TimeSpan::setSoconds(int sec)
{
    seconds=sec;
}

void TimeSpan::cast(int &hours, int &minutes, int &seconds)
{
    cout<<"You have accessed CAST function"<<endl;
    //TimeSpan temp;
    //temp.hours=hour;
    //temp.minutes=min;
    //temp.seconds=sec;
    if(minutes!=0)
    {
        while(minutes>59)
        {
            hours++;
            minutes-=60;
            if(seconds<0 && minutes>0)
            {
                minutes--;
                seconds+=60;
            }
            else if(seconds>59)
            {
                minutes++;
                seconds-=60;
            }
        }
        while(minutes<0 && hours>0)
        {
            hours--;
            minutes+=60;
        }
        
        //cout<<temp.hours<<" "<<temp.minutes<<" "<<temp.seconds<<endl;
    }
    else
    {
        while(seconds>59)
        {
            minutes++;
            seconds-=60;
        }
        while(seconds<0 && hours>0)
        {
            hours--;
            minutes+=60;
            minutes--;
            seconds+=60;
        }
        while(seconds<-59 && minutes<0)
        {
            minutes--;
            seconds+=60;
        }
        
    }
    cout<<hours<<" "<<minutes<<" "<<seconds<<endl;
}

TimeSpan TimeSpan::operator+(const TimeSpan &dur2) const
{
    TimeSpan dur1;
    dur1.hours=hours+dur2.hours;
    dur1.minutes=minutes+dur2.minutes;
    dur1.seconds=seconds+dur2.seconds;
    return (dur1);
}

TimeSpan TimeSpan::operator-(const TimeSpan &dur2) const
{
    TimeSpan dur1;
    dur1.hours=hours-dur2.hours;
    dur1.minutes=minutes-dur2.minutes;
    dur1.seconds=seconds-dur2.seconds;
    return (dur1);
}
TimeSpan TimeSpan::operator+=(const TimeSpan &dur2)
{
    //TimeSpan temp=*this;
    hours=hours+dur2.hours;
    minutes=minutes+dur2.minutes;
    seconds=seconds+dur2.seconds;
    return (*this);
}
TimeSpan TimeSpan::operator-=(const TimeSpan &dur2)
{
    hours=hours-dur2.hours;
    minutes=minutes-dur2.minutes;
    seconds =seconds-dur2.seconds;
    return (*this);
}
bool  TimeSpan:: operator==(const TimeSpan &dur)const
{
    return((hours==dur.hours) && (minutes==dur.minutes) && (seconds==dur.seconds));
}
bool TimeSpan:: operator!=(const TimeSpan &dur)const
{
    return ((hours!=dur.hours) || (minutes!=dur.minutes) || (seconds!=dur.seconds));
}
ostream & operator<<(ostream & out, const TimeSpan &dur)
{
    //const Timespan temp(dur);//to cast a float or double to an int
    // return (out<<"Hours: "<<dur.getHours()<<" Minutes: "<<dur.getMinutes()
    //<<" Seconds: "<<dur.getSeconds()<<endl);
    out<<"Hours: "<<dur.hours<<" Minutes: "<<dur.minutes <<" Seconds: "<<dur.seconds<<endl;
    return out; //to be able to return hours, minutes, and seconds
}
iostream & operator>>(iostream & in, TimeSpan dur)
{
    cout<<"Enter hours, minutes, and seconds: ";
    in>>dur.getHours()>>dur.getMinutes()>>dur.getSeconds();
    //input<<dur.hours<<dur.minutes<<dur.seconds<<endl;
    return in;
}