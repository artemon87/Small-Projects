//
//  main.cpp
//  BinarySearchTree
//
//  Created by Artem Kovtunenko on 11/14/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <iostream>
#include "BSTree.h"
//#include "Account.h"
#include <fstream>
#include "Transaction.h"

int main(int argc, const char * argv[]) {
    
    
    //Account t;
    
    Transaction a;
    BSTree tree;
    queue<Transaction> myQ;
    a.ReadFromAFile("test.txt", myQ);
    a.PopFromQueue(myQ, tree);
    tree.Display();
    std::cout << "Hello, World!\n";
    //Account a;
    //BSTree tree;
    //tree.Insert(&a);
    return 0;
}
