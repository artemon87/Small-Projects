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
    int id;
    
public:
    
    friend ostream& operator<<(ostream &out, const Bird &bird);
    friend istream& operator>>(istream & in, Bird &bird);
    
    Bird();
    Bird(string name, int num);
    Bird(const Bird &source);
    void setBirdName(string name);
    void setID(int num);
    string getName()const;
    int getID()const;
    
    void operator=(const Bird &source);
    bool operator==(const Bird &bird)const;
    bool operator!=(const Bird &bird)const;
    bool operator<(const Bird &bird)const;
    bool operator>(const Bird &bird)const;
    bool operator<=(const Bird &bird) const;
    
    ~Bird();
    
    
};

#endif /* defined(__LinkedL_332___Bird__) */