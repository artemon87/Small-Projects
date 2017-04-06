#ifndef BSTREE_H
#define BSTREE_H



#include <stdio.h>
#include "Account.h"
//#include "Transaction.h"

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
    bool Retrive(const Account &given, Account *&output)const;
    void Display()const;
    void Empty();
    bool isEmpty();

private:

    Node *root;
    void Insert(Node *&node, Account *source);
    //void Retrive(const Account &given, Account *&output, )const;

    void Display(Node *node)const;
    void Empty(Node *node);
};
#endif // BSTREE_H
