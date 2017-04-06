//
//  Child.cpp
//  LinkedL(332)
//
//  Created by Artem Kovtunenko on 10/22/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "Child.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

Child::Child()
{
    age=0;
    presents=true;
}
Child::Child(string fName, string lName, int years)
{
    lastName=lName;
    firstName=fName;
    age=years;
    presents=true;
}
Child:: Child(const Child &source)
{
  *this=source;
}
bool Child:: getPresent()const
{
  return presents;
}
void Child:: setPresent(bool candy)
{
    presents=candy;
}
void Child:: setLName(string lName)
{
    lastName=lName;
}
void Child:: setFName(string fName)
{
    firstName=fName;
}
void Child:: setAge(int age)
{
    this->age=age;
}
string Child:: getLName()const
{
    return lastName;
}
string Child:: getFName()const
{
    return firstName;
}
int Child:: getAge()const
{
    return age;
}
bool Child:: operator==(const Child &child)const
{
    return((lastName==child.lastName) && (firstName==child.firstName) && (age==child.age));
}
bool Child:: operator!=(const Child & child)const
{
    return ((lastName!=child.lastName) || (firstName!=child.firstName) || (age!=child.age));
}
void Child:: operator=(const Child &source)
{
    if(this==&source) return;
    lastName=source.lastName;
    firstName=source.firstName;
    age=source.age;
}
bool Child:: operator<(const Child &child)const
{
    return((lastName<child.lastName)||
           (lastName==child.lastName && firstName<child.firstName) ||
           (lastName==child.lastName && firstName==child.firstName && age<child.age));
}
bool Child:: operator>(const Child &child)const
{
    return((lastName>child.lastName)||
           (lastName==child.lastName && firstName>child.firstName) ||
           (lastName==child.lastName && firstName==child.firstName && age>child.age));
}
ostream &operator<<(ostream &out, const Child &child)
{
    out<<child.firstName<<child.lastName<<child.age<<child.presents;
    return out;
}
istream& operator>>(istream &in, Child &child)
{
    in>>child.firstName>>child.lastName>>child.age;
    return in;
}
bool Child:: operator<=(const Child &child) const
{
    return (*this<child || *this==child);
}
Child::~Child()
{}
