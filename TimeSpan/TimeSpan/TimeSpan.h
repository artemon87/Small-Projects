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

template <class Item>
class TimeSpan
{
    /*friend*/ template<class frindss> friend ostream& operator<< (ostream&, const TimeSpan&);
    /*friend*/ template<class friends> friend istream& operator>> (istream&, TimeSpan&);
private:
    Item hours;
    Item minutes;
    Item seconds;
    
public:
    TimeSpan();
    TimeSpan(Item);
    TimeSpan(Item, Item);
    TimeSpan(Item, Item, Item);
    int getHours()const;
    int getMinutes()const;
    int getSeconds()const;
    void setHours(Item);
    void setMinutes(Item);
    void setSoconds(Item);
    void cast(Item &, Item &, Item &)const;
    TimeSpan operator+(const TimeSpan &)const;
    TimeSpan operator-(const TimeSpan &)const;
    TimeSpan operator+=(const TimeSpan &);
    TimeSpan operator-=(const TimeSpan &);
    bool operator==(const TimeSpan &)const;
    bool operator!=(const TimeSpan &) const;
    
    //~TimeSpan();

    
};

//#inlude "TimeSpan.cpp"
#endif /* defined(__TimeSpan__TimeSpan__) */


