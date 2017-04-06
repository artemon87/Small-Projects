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
    List342<Child> stack1;
    List342<Child> stack2;
    List342<Child> stack3;
    Child ch1 ("aaa", "aaa", 1);
    Child ch2 ("bbb", "bbb", 2);
    Child ch3 ("ccc", "ddd", 3);
    Child ch4 ("child", "four", 4);
    Child ch5 ("child", "five", 5);
    Child ch6 ("child", "six", 6);
    Child ch7=ch1;
    Child ch0;
    Child ch01;
    //stack1.addItem(&ch0);
    stack1.Insert(&ch1);
    stack1.Insert(&ch2);
    stack1.Insert(&ch3);
    
    List342<Child> newC=stack1;
    cout<<"Copy constructor call" <<endl;
    cout<<newC<<endl;
    cout<<"stack1 for Copy constructor" <<endl;
    cout<<stack1<<endl;
    newC.Remove(ch1, ch01);
    cout<<"Copy constructor after REMOVE call" <<endl;
    cout<<newC<<endl;
    cout<<"stack1 for Copy constructor" <<endl;
    cout<<stack1<<endl;
    newC.Insert(&ch7);
    cout<<"Copy constructor after INSERTING call" <<endl;
    cout<<newC<<endl;
    cout<<"stack1 for Copy constructor" <<endl;
    stack2.Insert(&ch4);
    stack2.Insert(&ch5);
    stack2.Insert(&ch6);
    stack2.Insert(&ch6);
    stack2.Insert(&ch7);
    stack2.Remove(ch6, ch0);
    stack2.Remove(ch6, ch01);
    stack1.Insert(&ch0);
    stack1.Insert(&ch01);
    cout<<"Stack 1: "<<endl;
    cout<<stack1<<endl;
    cout<<"Stack 2: "<<endl;
    cout<<stack2<<endl;
    stack3=stack1;
    stack1.ClearList();
    cout<<"Stack 1: "<<endl;
    cout<<stack1<<endl;
    //stack1=stack
    cout<<"Stack 3(Copy from stack 1) "<<endl;
    cout<<stack3<<endl;
    //stack1.Merge(stack2, stack3);
    //cout<<"Merged Stack1 "<<endl;
    //cout<<stack1;
    List342<Child> add;
    cout<<"|||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"Stack2 and Stack3 will be added together. Before adding "<<endl;
    cout<<"Stack2"<<stack2<<endl;
    cout<<"Stack3"<<stack3<<endl;
    cout<<"|||||||||||||||||||||||||||||||||||||||"<<endl;
    stack2+=stack3;
    cout<<"Stack2 += Stack3: "<<endl;
    cout<<stack2<<endl;
    List342<Child> read;
    read.BuildList("name.txt");
    cout<<"Read file: "<<endl;
    cout<<read<<endl;
    Bird bird1("bird1", 1), bird2("bird2", 2), bird3("bird3", 3);
    List342<Bird> birds;
    birds.BuildList("bird.txt");
    cout<<"Brirds from a file: "<<endl;
    cout<<birds<<endl;
    birds.Insert(&bird1);
    cout<<"Brirds: "<<endl;
    cout<<birds<<endl;
    //birds.clearList();
    //cout<<"Brirds after clear: "<<endl;
    //cout<<birds<<endl;
    List342<Bird> birds2, birds3;
    birds2.Insert(&bird2);
    birds2.Insert(&bird3);
    birds3.Insert(&bird1);
    birds3.Merge(birds, birds2);
    cout<<"Merged:"<<endl;
    cout<<birds3<<endl;
    stack1.ClearList();
    stack2.ClearList();
    stack1.Insert(&ch7);
    stack2.Insert(&ch7);
    cout<<"Stack3: "<<endl;
    cout<<stack3<<endl;
    if(stack1==stack2)
    {
      cout<<"They are equal"<<endl;
    }
        if(stack1!=stack3)
    {
      cout<<"They are NOT equal"<<endl;
    }
     
    cout<<"///////////////////////////////////////////////////////"<<endl;
    cout<<"///////////////////////////////////////////////////////"<<endl;
    cout<<"///////////////////////////////////////////////////////"<<endl;
    cout<<"///////////////////////////////////////////////////////"<<endl;
    cout<<"///////////////////////////////////////////////////////"<<endl;
    cout<<"///////////////////////////////////////////////////////"<<endl;
    
    
    Child c1("ann", "hanlin", 7), c2("pradnya", "dhala", 8);
    Child c3("bill", "vollmann", 13), c4("cesar", "ruiz", 6);
    Child c5("piqi", "tang", 7), c6("pete", "rose", 13), c7("hank", "aaron", 3);
    Child c8("madison", "fife", 7), c9("miles", "davis", 65);
    Child c10("john", "zorn", 4), c11;
    List342<Child> class1, class2, soccer, chess;
    int a = 1, b = -1, c = 13;
    class1.Insert(&c1);
    class1.Insert(&c2);
    class1.Insert(&c3);
    class2.Insert(&c4);
    class2.Insert(&c5);
    class2.Insert(&c6);
    class2.Insert(&c7);
    soccer.Insert(&c6);
    soccer.Insert(&c4);
    soccer.Insert(&c9);
    chess.Insert(&c10);
    chess.Insert(&c7);
    cout<< "This is class1: " << class1 << endl;
    cout << "This is class2: " << class2 << endl;
    if(class1!=class2)
    {
      cout<<"class1 is different than class 2" << endl;
    }
    if(class1.Peek(c2, c11))
    {}
    cout << c11 << " is in class1" << endl;
    if(class1.Remove(c1, c11))
    {
            class2.Insert(&c11);
        cout<< c1 <<"has been removed from class1 and placed in class2" << endl;
    }
    cout<<"This is class2:  " << class2 << endl;
    cout << "This is the chess club: " << chess << endl;
    chess.ClearList();
    chess.Insert(&c9);
    cout << "this is now the chess club: " << chess << endl;
    List342<Child> soccer2 = soccer;
    // Note that the Merge function is probably not as intuitive as we like
    // but the fact the lists allow duplicates confuse the situation.
    chess.Merge(soccer, class2);
    cout << "this is now the chess club: " << chess << endl;
    if (soccer.isEmpty())
    {
    }
    cout << "The soccer club is now empty" << endl;
    cout << "This is the soccer2 club: " << soccer2 << endl;
    List342<int> numbers;
    numbers.Insert(&a);
    numbers.Insert(&b);
    numbers.Insert(&c);
    cout<<"These are the numbers: " << numbers << endl;
    
    List342<int> int1;
    List342<int> int2;
    cout<<"|||||||||||||||||||||||"<<endl;
    
    int m=7, n=8, l=9;
    int1.Insert(&m);
    int2.Insert(&n);
    int2.Insert(&l);
    int1.Merge(int1, int2);
    cout<<"Int1 : "<<int1<<endl;
    cout<<"Int2 : "<<int2<<endl;
    
    List342<int> ints;
    ints.BuildList("num.txt");
    cout<<"Ints from a file: "<<endl;
    cout<<ints<<endl;
    
    
    

    
    
    
    
    
    return 0;
    
}