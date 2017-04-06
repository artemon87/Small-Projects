//
//  Account.h
//  BinarySearchTree
//
//  Created by Artem Kovtunenko on 11/14/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#ifndef __BinarySearchTree__Account__
#define __BinarySearchTree__Account__

#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
//#include "Transaction.h"

using namespace std;


class Transaction;

/*struct History
{
  Transaction transHistory;
};
typedef vector<History> historyV;
typedef vector<historyV> historyTree;
*/
class Account
{
private:
    
    int accntNumber;
    string firstName;
    string lastName;
    vector<int> *fund;//{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //vector<vector<Transaction*> > vectorStrings;
    //string history[100][10];
    //vector<vector<Transaction*> > historyVect;
    
    
    //vector<queue<Transaction*> > vectorStrings (10, vector<Transaction*>(10));
    
    //vector<Transaction*> *vectorString;
    //queue<Transaction*> history;
    
    
public:
    
    Account();
    Account(string lastN, string firstN, int accnt);
    void setLastN(string lastN);
    void setFirstN(string firstN);
    void setInitialFund();
    void fundTrans(int fundN, int amount);
    void setAccount(int number);
    void restoreName();
    string getLastN()const;
    string getFirstN()const;
    int getAccount()const;
    vector<int> getFund()const;
    int getFundBalance(int fundID);
    vector<string> getAllNamesOfFunds()const;
    string getFundToString(int fundID);
    void addToHistory(Transaction *trans, int fundID);
    void displayHistory()const;
    void setTransHistory();
    int getFundIDNum()const;
    void setFundIDNum(int num);
    
    bool operator<(const Account &source)const;
    bool operator>(const Account &source)const;
    bool operator==(const Account &souce)const;
    bool operator!=(const Account &source)const;
    void operator=(const Account &source);
    friend istream& operator>>(istream &in, Account &input);
    friend ostream& operator<<(ostream &out, const Account &acc);
    
    
    
    ~Account();
    
    
};

#endif /* defined(__BinarySearchTree__Account__) */
