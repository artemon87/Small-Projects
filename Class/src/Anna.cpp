//#include "Anna.h"
#include <iostream>
#include "Anna.h"

using namespace std;

Anna:: Anna()
{
  cout<<"You just created an Anna object"<<endl;
}
Anna:: Anna(int y, int m, int d)
{
  year=y;
  month=m;
  day=d;
}
void Anna:: duration(int h, double m, double s)
{
    hours=h;
    minutes=m;
    seconds=s;

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
        //int modulo;
        //int temp;
        //if(minutes<-59)
        //{
          //  hours--;
          //  minutes+=60;
       // }
       // else
       // {
         //   hours*=60;
         //   hours-=minutes;
    }
    cout<<hours;//return Anna;
}
      //temp=hours/60;
      //modulo=hours%60;
      //hours=temp;
     // minutes+=modulo;


Anna::~Anna()
{
    //dtor
}
const int Anna:: getHours()const
{
    return hours;
}
const int Anna:: getMinutes()const
{
    return minutes;
}
const int Anna:: getSoconds()const
{
    return seconds;
}
void Anna:: setHours(int h)
{
    hours=h;
}
void Anna:: setMinutes(int m)
{
    minutes=m;
}
void Anna:: setSoconds(int s)
{
    seconds=s;
}
