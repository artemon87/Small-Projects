#include "TimeSpan.h"

#include <iostream>


using namespace std;


template <class Item>
TimeSpan::TimeSpan()

{

    

}
template <class Item>
TimeSpan::TimeSpan(Item sec)

{

    hours=0;

    minutes=0;

    seconds=sec;

    cast(hours, minutes, seconds);

}
template <class Item>
TimeSpan::TimeSpan(Item min, Item sec)

{

    hours=0;

    minutes=min;

    seconds=sec;

    cast(hours, minutes, seconds);

}
template <class Item>
TimeSpan::TimeSpan(Item hour, Item min, Item sec)

{

    hours= hour;

    minutes= min;

    seconds=sec;

    cast(hours, minutes, seconds);

}
template <class Item>
int TimeSpan:: getHours()const

{

    cout<<hours;

    return hours;

}
template <class Item>
int TimeSpan:: getMinutes()const

{

    cout<<minutes;

    return minutes;

}
template <class Item>
int TimeSpan::getSeconds()const

{

    return seconds;

}
template <class Item>
void TimeSpan::setHours(Item hour)

{

    hours=hour;

}
template <class Item>
void TimeSpan::setMinutes(Item min)

{

    minutes=min;

}
template <class Item>
void TimeSpan::setSoconds(Item sec)

{

    seconds=sec;

}
template <class Item>
void TimeSpan::cast(Item &hours, Item &minutes, Item &seconds)const

{

    cout<<"You have accessed CAST function"<<endl;


        while(seconds<0)

        {

            if(minutes>0)

            {

              minutes--;

              seconds+=60;

            }

            else if(minutes==0 && hours>0)

            {

                minutes--;

                seconds+=60;

            }

            else if(minutes<0)

            {

                minutes--;

                seconds+=60;

            }

        }

        while(seconds >59)

        {


              minutes++;

              seconds-=60;

    

            if(seconds>0 && minutes<0)

            {

              minutes++;

              seconds-=60;

            }

        }

        while(minutes<0)

        {

            if(hours>0)

            {

              hours--;

              minutes+=60;

            }

            else if(minutes<-59)

            {

              hours--;

              minutes+=60;

            }

        }

        while(minutes>59)

        {

            hours++;

            minutes-=60;

        }

 

    cout<<hours<<" "<<minutes<<" "<<seconds<<endl;

}
template <class Item>
TimeSpan TimeSpan::operator+(const TimeSpan &dur2)const

{

    TimeSpan dur1;

    dur1.hours=hours+dur2.hours;

    dur1.minutes=minutes+dur2.minutes;

    dur1.seconds=seconds+dur2.seconds;

    cast(dur1.hours, dur1.minutes, dur1.seconds); //casting

    return (dur1);

}
template <class Item>
TimeSpan TimeSpan::operator-(const TimeSpan &dur2)const

{

    TimeSpan dur1;

    dur1.hours=hours-dur2.hours;

    dur1.minutes=minutes-dur2.minutes;

    dur1.seconds=seconds-dur2.seconds;

    cast(dur1.hours, dur1.minutes, dur1.seconds); //casting

    return (dur1);

}
template <class Item>
TimeSpan TimeSpan::operator+=(const TimeSpan &dur2)

{

    //TimeSpan temp=*this;

    hours=hours+dur2.hours;

    minutes=minutes+dur2.minutes;

    seconds=seconds+dur2.seconds;

    cast(hours, minutes, seconds); //casting

    return (*this);

}
template <class Item>
TimeSpan TimeSpan::operator-=(const TimeSpan &dur2)

{

    hours=hours-dur2.hours;

    minutes=minutes-dur2.minutes;

    seconds =seconds-dur2.seconds;

    cast(hours, minutes, seconds); //casting

    return (*this);

}
template <class Item>
bool  TimeSpan:: operator==(const TimeSpan &dur)const

{

    return((hours==dur.hours) && (minutes==dur.minutes) && (seconds==dur.seconds));

}
template <class Item>
bool TimeSpan:: operator!=(const TimeSpan &dur)const

{

    return ((hours!=dur.hours) || (minutes!=dur.minutes) || (seconds!=dur.seconds));

}

template<class friends>
ostream & operator<<(ostream & out, const TimeSpan &dur)

{

    out<<"Hours: "<<dur.hours<<" Minutes: "<<dur.minutes <<" Seconds: "<<dur.seconds<<endl;

    //TimeSpan::cast(dur.hours, dur.minutes, dur.seconds);

    return out; //to be able to return hours, minutes, and seconds

}
template<class friends>
istream & operator>>(istream & in, TimeSpan &dur)

{

    //cout<<"Enter hours, minutes, and seconds: ";
    int hour=int(dur.hours);
    int min= int(dur.minutes);
    int sec= int(dur.seconds);

    in >> dur.hours >> dur.minutes >> dur.seconds;
    //in>>hour>>min>>sec;

    //cast(dur.hours, dur.minutes, dur.seconds);    //in>>dur.getHours()>>dur.getMinutes()>>dur.getSeconds();

    cout<<endl;

    return in;

}