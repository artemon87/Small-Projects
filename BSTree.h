#ifndef ___Bstree_
#define __Bstree__

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
    //void Display(Node *traversNode, Node *parentNode);
    
    void Display(Node *node);
    
    void Empty();
    void Empty(Node *node);
    bool isEmpty();
    
private:

    Node *root;
};
#endif