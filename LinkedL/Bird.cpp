//
//  Bird.cpp
//  LinkedL(332)
//
//  Created by Artem Kovtunenko on 10/22/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "Bird.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Bird::Bird()
{
    id=0;
}
Bird::Bird(string name, int num)
{
    birdName=name;
    id=num;
}
void Bird:: setBirdName(string name)
{
    birdName=name;
}
void Bird:: setID(int num)
{
    id=num;
}
string Bird:: getName()const
{
    return birdName;
}
int Bird:: getID()const
{
    return id;
}
Bird:: Bird(const Bird &source)
{
    *this=source;
}
void Bird:: operator=(const Bird &source)
{
    if(this==&source)return;
    birdName=source.birdName;
    id=source.id;
}
bool Bird:: operator==(const Bird &bird)const
{
    return((birdName==bird.birdName) && (id==bird.id));
}
bool Bird:: operator!=(const Bird & bird)const
{
    return ((birdName!=bird.birdName) || (id!=bird.id));
}
bool Bird:: operator<(const Bird &bird)const
{
    return((id<bird.id)||
           (id==bird.id && birdName<bird.birdName));
}
bool Bird:: operator>(const Bird &bird)const
{
    return((id>bird.id)||
           (id==bird.id && birdName>bird.birdName));
}
ostream &operator<<(ostream &out, const Bird &bird)
{
    out<<bird.birdName<<bird.id;
    return out;
}
istream& operator>>(istream &in, Bird &bird)
{
    in>>bird.birdName>>bird.id;
    return in;
}
bool Bird:: operator<=(const Bird &bird) const
{
    return (*this<bird || *this==bird);
}
Bird:: ~Bird()
{}