
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

using namespace std;

Child::Child()

{}
Child::Child(string lName, string fName, int years)
    {
        lastName=lName;
        firstName=fName;
        age=years;
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
