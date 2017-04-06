//
//  Account.cpp
//  BinarySearchTree
//
//  Created by Artem Kovtunenko on 11/14/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include <string>
#include "Account.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

Account:: Account()
{
    firstName="";
    lastName="";
    accntNumber=0;
    //historyVect.resize(10, vector<Transaction*> (10, 0));
    //vectorStrings={0, 0, 0, 0, 0, 0, 0, 0, 0};
    //vector<vector<string> > vectorStrings (10, vector<string>(10, ""));
    //vect=new vector<string>(10, "");
    //fund=new vector<int>(10, 0);//{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //vector<string> vectorS (10);//=//{"Hello", "My", "Name", "is", "Artem"};
    //transectionCounter=0;
    //history={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //historyVect=
}

Account:: ~Account()
{
    //delete fund;
}
Account:: Account(string lastN, string firstN, int accnt)
{
    lastName=lastN;
    firstName=firstN;
    accntNumber=accnt;
}
void Account:: setLastN(string lastN)
{
    lastName=lastN;
}
void Account:: setFirstN(string firstN)
{
    firstName=firstN;
}
void Account:: setInitialFund()
{
    fund=new vector<int>(10, 0);
    /*for(int i=0; i<10; i++)
    {
        fund.push_back(0);
    }*/
    //vector<int> temp(10,0);
    //fund = temp;
}
void Account:: setTransHistory()
{
    //vectorStrings=new vector<queue<Transaction*> > (10, 0);
    //vectorString=new vector<Transaction*> (10, 0);
}
void Account:: fundTrans(int fundN, int amount)
{
    (*fund)[fundN]+=amount;
}
void Account:: setAccount(int number)
{
    accntNumber=number;
}
void Account:: restoreName()
{
    firstName="";
    lastName="";
}
string Account:: getLastN()const
{
    return lastName;
}
string Account:: getFirstN()const
{
    return firstName;
}
int Account:: getAccount()const
{
    return accntNumber;
}
vector<int> Account:: getFund()const
{
    return *fund;
}
int Account:: getFundBalance(int fundID)
{
    int balance=(*fund)[fundID];
    return balance;
}
vector<string> Account:: getAllNamesOfFunds()const
{
    vector<string> fundsToString(10);
    fundsToString[0]="Money Market";
    fundsToString[1]="Prime Money Market";
    fundsToString[2]="Long-Term Bond";
    fundsToString[3]="Short-Term Bond";
    fundsToString[4]="500 Index Fund";
    fundsToString[5]="Capital Value Fund";
    fundsToString[6]="Growth Equity Fund";
    fundsToString[7]="Growth Index Fund";
    fundsToString[8]="Value Fund";
    fundsToString[9]="Value Stock Index";
    
    return fundsToString;
}
string Account:: getFundToString(int fundID)
{
    vector<string> fundsToString(10);
    fundsToString[0]="Money Market";
    fundsToString[1]="Prime Money Market";
    fundsToString[2]="Long-Term Bond";
    fundsToString[3]="Short-Term Bond";
    fundsToString[4]="500 Index Fund";
    fundsToString[5]="Capital Value Fund";
    fundsToString[6]="Growth Equity Fund";
    fundsToString[7]="Growth Index Fund";
    fundsToString[8]="Value Fund";
    fundsToString[9]="Value Stock Index";
    
    return fundsToString[fundID];
}
void Account:: addToHistory(Transaction *trans, int fundID)
{
    //history.push(trans);
    //history[fundID].push_back(trans);
    //[transectionCounter]=&trans;
    int i=0;
    //historyVect.resize(10, vector<Transaction*> (10, 0));
    //historyVect[fundID].push_back(trans);
    //history[fundID][i];
    if(fundID==0)
    {
      //vectorStrings[fundID].push_back(new Transaction (trans));
    }
}
void Account:: displayHistory()const
{
    //vector<queue<Transaction>>copy=history;
    for(int i=0; i<10; i++)
    {
        
    }
}




///////////////////////////////////////////////////////////////////////
bool Account:: operator<(const Account &source)const
{
    return (accntNumber<source.accntNumber);
}
bool Account:: operator>(const Account &source)const
{
    return (accntNumber>source.accntNumber);
}
bool Account:: operator==(const Account &source)const
{
    return (accntNumber==source.accntNumber);
}
bool Account:: operator!=(const Account &source)const
{
    return (accntNumber!=source.accntNumber);
}
void Account:: operator=(const Account &source)
{
    //this->lastName="";
    //this->firstName="";
    //this->accntNumber=0;
    //this->fund={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    this->accntNumber=source.accntNumber;
    this->lastName=source.lastName;
    this->firstName=source.firstName;
    this->fund=source.fund;
}
istream& operator>>(istream &in, Account &input)
{
    //in>>input.lastName>>input.firstName>>input.accntNumber;
    return in;
}
ostream& operator<<(ostream &out, const Account &acc)
{
    out<<"Account number: "<<acc.accntNumber<<" "<<acc.lastName<<" "
    <<acc.firstName<<" "<<endl<<endl;
    for (int i=0; i<10; i++)
    {
        out<<acc.getAllNamesOfFunds()[i]<<": $"<<acc.getFund()[i]<<endl;
    }
    out<<endl;
    return out;
}























