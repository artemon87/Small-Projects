//  main.cpp

//  LinkedL(332)

//

//  Created by Artem Kovtunenko on 10/17/14.

//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.

//


#include <iostream>

#include "List342.h"


using namespace std;


int main()

{
    IntStack<Child> obaba;
    Child first;
    first.setLName("Simmons");
    first.setFName("Bob");
    first.setAge(26);
    obaba.addItem(&first);
    Child second ("Hodwick", "Tom", 15);
    obaba.addItem(&second);
    cout<<"Obaba: "<<endl;
    cout<<obaba<<endl;
    Child ch("DelPiero", "Alex", 38);
    IntStack<Child> child;
    child.addItem(&ch);
    cout<<"Child: "<<endl;
    cout<<child<<endl;
    Child newChild;
    child.Remove(ch, newChild);
    cout<<"Child: "<<endl;
    obaba.addItem(&newChild);
    cout<<"Obaba: "<<endl;
    cout<<obaba<<endl;
    IntStack<Child> mer;
    mer.Merge(obaba, child);
    cout<<"Merging List: "<<endl;
    cout<<mer<<endl;
    IntStack<Child> copied=obaba;
    //copied=obaba;
    cout<<"Copied List: "<<endl;
    cout<<copied<<endl;


    return 0;

}
