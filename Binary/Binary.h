///Users/artemkovtunenko/Documents/C++/TimeSpan/TimeSpan/TimeSpan.h
//  Binary.h
//  Binary
//
//  Created by Artem Kovtunenko on 1/5/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#ifndef __Binary__Binary__
#define __Binary__Binary__

#include <stdio.h>
#include <iostream>

using namespace std;

class Binary
{
    
private:
    
    bool *array;
    bool sign;
    int count;
    
public:
    
    Binary();
    Binary(int number);
    Binary(Binary const &input);
    ~Binary();
    
    bool getBit(int n)const;
    int getCount()const;
    bool setBit(int n);
    bool clearBit(int n);
    bool toggleBit(int n);
    bool decimalToBinary(bool *array, int n, int &count)const;
    
    int toInteger(const Binary &bin)const;
    int binaryToDecimal(int num)const;
    
    const Binary & operator-(const Binary &input)const;
    const Binary & operator+(const Binary &input)const;
    Binary & operator=(const Binary &input);
    Binary & operator+=(const Binary &input);
    Binary & operator-=(const Binary &input);
    bool operator==(const Binary &input) const;
    bool operator!=(const Binary &input)const;
    
    friend istream& operator>>(istream &in, Binary & bin);
    friend ostream& operator<<(ostream &out, const Binary &output);
    
    
};


#endif /* defined(__Binary__Binary__) */
