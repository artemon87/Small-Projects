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
    bool presents;
    
public:
    
    friend ostream& operator<<(ostream &out, const Child &child);
    friend istream& operator>>(istream &in, Child &child);
    
    Child();
    Child(string lName, string fName, int years);
    Child(const Child &source);
    bool getPresent()const;
    void setPresent(bool candy);
    void setLName(string lName);
    void setFName(string fName);
    void setAge(int age);
    string getLName()const;
    string getFName()const;
    int getAge()const;
    bool operator==(const Child &child)const;
    bool operator!=(const Child &child)const;
    void operator=(const Child &source);
    bool operator<(const Child &child)const;
    bool operator>(const Child &child)const;
    bool operator<=(const Child &child) const;
    
    ~Child();

};


#endif /* defined(__LinkedL_332___Child__) */