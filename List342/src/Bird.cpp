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

    {  }

Bird::Bird(string name, int num)

    {
        present=true;
        birdName=name;
        idNum=num;
    }
void Bird:: setBirdName(string name)
    {
        birdName=name;
    }

void Bird:: setID(int num)
    {
        idNum=num;
    }

string Bird:: getName()const
    {
        return birdName;
    }
int Bird:: getID()const
    {
        return idNum;
    }
Bird:: Bird(const Bird &source)//copy constructor

    {
        cout<<"Copy constructor"<<endl;
    }
void Bird:: operator=(const Bird &source)

    {
        if(this==&source)return;///????????? if you are calling yourself return false
        present=source.present;
        birdName=source.birdName;
        idNum=source.idNum;
    }

