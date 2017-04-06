//
//  BSTree.h
//  BinarySearchTree
//
//  Created by Artem Kovtunenko on 11/14/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef ____BSTREE_H__
#define ____BSTREE_H__

#include <stdio.h>
#include "Account.h"
#include "Transaction.h"

using namespace std;

struct Node
{
    Node *left;
    Node *right;
    Account *pAccnt;
};

class BSTree
{
    
public:
    
    BSTree();
    ~BSTree();
    bool Insert(Account *source);
    //void Insert(Account *source, Node *node);
    bool Retrive(const Account &, Account *&)const;
    void Display();//const throw (exception);
    void Display(Node *traversNode, Node *parentNode);
    void Empty();
    void Empty(Node *node);
    bool isEmpty();
    
private:

    Node *root;
};




#endif /* defined(__BinarySearchTree__BSTree__) */
