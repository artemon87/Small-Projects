//
//  Binary.cpp
//  Binary
//
//  Created by Artem Kovtunenko on 1/5/15.
//  Copyright (c) 2015 Artem Kovtunenko. All rights reserved.
//

#include "Binary.h"
#include <iostream>

using namespace std;

Binary:: Binary()
{
    array=new bool[32];
    for(int i = 0; i < 32; i++)
    {
        array[i]=false;
    }
    count=0;
    sign=true;
}
Binary:: Binary(int n)
{
    if(n >= -128 && n <= 127)
    {
        array=new bool[8];
    }
    else if(n >= -32768 && n <= 32767)
    {
        array=new bool[16];
    }
    else
    {
        array=new bool[32];
    }
    
    count=0;
    if(n<0)
    {
        sign=false;
        n*=-1;
    }
    decimalToBinary(array, n, count);
    /*while(n>0)
    {
        if(n%2==0)
        {
            array[traversal]=false;
        }
        else
        {
            array[traversal]=true;
        }
        traversal++;
        count++;
        n=n/2;
    }*/
}

bool Binary:: decimalToBinary(bool *array, int n, int &count)const
{
    int traversal=0;
    while(n>0)
    {
        if(n%2==0)
        {
            array[traversal]=false;
        }
        else
        {
            array[traversal]=true;
        }
        traversal++;
        count++;
        n=n/2;
    }
    return true;
}

Binary:: Binary(const Binary &input)
{
    
    for(int i = 0; i <= input.count; i++)
    {
        //this.array[i]=false;
        array[i]=input.array[i];
    }
    count=input.count;
    sign=input.sign;
}

Binary:: ~Binary()
{
    delete [] array;
    array=NULL;
}

bool Binary:: getBit(int n)const
{
    return array[n];
}

bool Binary:: setBit(int n)
{
    array[n]=true;
    return true;
}

bool Binary:: clearBit(int n)
{
    array[n]=false;
    return true;
}

bool Binary:: toggleBit(int n)
{
    if(array[n]==true && n >= 0)
    {
        array[n]=false;
    }
    else
    {
        array[n]=true;
    }
    return true;
}
int Binary:: getCount()const
{
    return count;
}
int Binary:: toInteger(const Binary &bin)const
{
    //int num1=0;
    int arr1[bin.count];
    int integer=0;
    
    for(int i = 0; i < bin.count; i++)
    {
        if(bin.array[i]==true)
        {
            arr1[i]=1;
        }
        else
        {
            arr1[i]=0;
        }
    }
    for(int i = 0; i < bin.count; i++)
    {
        integer*=10;
        integer+=arr1[i];
    }
    
    //////////////////////////////////////////////
    // checking if binary # has a negative sign //
    //////////////////////////////////////////////
    if(bin.sign==false)
    {
        integer*=-1;
    }
    return integer;
}
int Binary:: binaryToDecimal(int num)const
{
    //checking if "num" is negative
    bool zero=true;
    if(num<0)
    {
        num*=-1;
        zero=false;
    }
    int dec=0;//unsigned long
    int remain=0, base=1;
    while(num > 0)
    {
        remain = num % 10;
        dec  = dec + remain * base;
        num /= num;
        base *= 2;
    }
    if(zero != false)
    {
        return dec;
    }
    else
    {
        return dec * (-1);
    }
}

const Binary & Binary:: operator-(const Binary &input)const
{
    int num1=toInteger(*this);
    int num2=toInteger(input);
    int dec1=binaryToDecimal(num1);
    int dec2=binaryToDecimal(num2);
    int difference=dec1-dec2;
    Binary *output=new Binary(difference);
    return *output;
}
Binary & Binary:: operator=(const Binary &input)
{
    if(this==&input)
    {
      return *this;
    }
    else
    {
      delete [] array;
      count=input.count;
      sign=input.sign;
      array=new bool[binaryToDecimal(toInteger(input))];
      for(int i = 0; i < input.count; i++)
      {
        array[i]=input.array[i];
      }

    }
    return *this;
}
      
Binary & Binary:: operator-=(const Binary &input)
{
    *this=*this-input;
    return (*this);
}
const Binary & Binary:: operator+(const Binary &input)const
{
    int num1=toInteger(*this);
    int num2=toInteger(input);
    int dec1=binaryToDecimal(num1);
    int dec2=binaryToDecimal(num2);
    int sum=dec1+dec2;
    Binary *output=new Binary(sum);
    return *output;
}

Binary & Binary:: operator+=(const Binary &input)
{
    *this=*this+input;
    return (*this);
}

bool Binary:: operator==(const Binary &input) const
{
    if (count==input.count && sign==input.sign)
    {
        for(int i = 0; i < input.count; i++)
        {
            if(array[i] != input.array[i])
            {
                return false;
                break;
            }
        }
    }
    return true;
}
bool Binary:: operator!=(const Binary &input)const
{
    if (count != input.count || sign != input.sign)
    {
        return true;
    }
    else
    {
        for(int i = 0; i < input.count; i++)
        {
            if(array[i] != input.array[i])
            {
                return true;
            }
        }
    }
    return false;
}
istream& operator>>(istream &in, Binary & bin)
{
    int number;
    in >> number;
    bin.decimalToBinary(bin.array, number, bin.count);
    return in;
}
ostream& operator<<(ostream &out, const Binary &output)
{
    for(int i = 0; i < output.count; i++)
    {
        out<<output.sign<<output.array[i];
    }
    return out;
}




