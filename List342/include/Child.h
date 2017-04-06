#ifndef __LinkedL_332___Child__
#define __LinkedL_332___Child__

#include <stdio.h>
#include <string>

using namespace std;


class Child//: public IntStack<Child>
{
private:

    string lastName;
    string firstName;
    int age;
public:

    //friend class IntStack<>;
    Child();

    Child(string lName, string fName, int years);
    void setLName(string lName);
    void setFName(string fName);
    void setAge(int age);
    string getLName()const;
    string getFName()const;
    int getAge()const;
    bool operator==(const Child &child)const;
    bool operator!=(const Child &child)const;


};


#endif /* defined(__LinkedL_332___Child__) */
