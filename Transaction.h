#ifndef __BinarySearchTree__Transaction__
#define __BinarySearchTree__Transaction__

#include <stdio.h>
#include "Account.h"
#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class BSTree;
class Transaction
{
public:
    
    Transaction();
    ~Transaction();
    friend ostream& operator<<(ostream &out, const Transaction &trans);
    
    void ReadFromAFile(string fileName, queue<Transaction> &myQ);
    
    //void Deposit(Account &account, int fund, int amount, BSTree &tree);
    void Deposit(Transaction &trans, BSTree &tree);
    //void Withdraw(Account &account, int fund, int amount, BSTree &tree);
    void Withdraw(Transaction &trans, BSTree &tree);
    void Transfer(Transaction &trans, BSTree &tree);
    void History(Transaction &trans, BSTree &tree);
    void Open(Transaction &trans, BSTree &tree);
    void PopFromQueue(queue<Transaction> &myQ, BSTree &tree);
    //void PopFromQueue(queue<Transaction> &myQ);
    char getTransactionID()const;
    void setErrorMessage(string message);
    
    string* historyToString(Account &accnt, char transID, int bill, Transaction &trans);
    
    void operator=(const Transaction &source);
    friend istream& operator>>(istream & in, Transaction &transaction);
    
    
private:
    
    char transactionID;
    int amount;
    Account accnt;
    Account accnt2;
    bool successful;
    string ERROR;
    //queue<string> errorMessage;
    
};

#endif /* defined(__BinarySearchTree__Transaction__) */