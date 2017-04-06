//
//  Bird.h
//  LinkedL(332)
//
//  Created by Artem Kovtunenko on 10/22/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __LinkedL_332___Bird__
#define __LinkedL_332___Bird__

#include <stdio.h>
#include <string>


using namespace std;

class Bird

{

private:
    string birdName;
    int idNum;
    bool present;

public:

    Bird();
    Bird(string name, int num);
    void setBirdName(string name);
    void setID(int num);
    string getName()const;
    int getID()const;

    Bird(const Bird &source);//copy constructor
    void operator=(const Bird &source);




};

#endif /* defined(__LinkedL_332___Bird__) */
