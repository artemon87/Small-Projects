//
//  TimeSpan.h
//  TimeSpan
//
//  Created by Artem Kovtunenko on 10/8/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <stdio.h>
#include <iostream>
using namespace std;


class TimeSpan
{
    /*friend*/ friend ostream& operator<< (ostream&, const TimeSpan&);
    /*friend*/ friend istream& operator>> (istream&, TimeSpan&);
private:
    int hours;
    int minutes;
    int seconds;
    
public:
    TimeSpan();
    TimeSpan(int);
    TimeSpan(int, int);
    TimeSpan(int, int, int);
    int getHours()const;
    int getMinutes()const;
    int getSeconds()const;
    void setHours(int);
    void setMinutes(int);
    void setSoconds(int);
    void cast(int &, int &, int &);
    TimeSpan operator+(const TimeSpan &)const;
    TimeSpan operator-(const TimeSpan &)const;
    TimeSpan operator+=(const TimeSpan &);
    TimeSpan operator-=(const TimeSpan &);
    bool operator==(const TimeSpan &)const;
    bool operator!=(const TimeSpan &) const;
    
    //~TimeSpan();

    
};


#endif /* defined(__TimeSpan__TimeSpan__) */


