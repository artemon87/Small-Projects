  //
//  Transaction.cpp
//  BinarySearchTree
//
//  Created by Artem Kovtunenko on 11/22/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "Transaction.h"
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "BSTree.h"

using namespace std;

//void Transaction:: getTransactionID(const char ID)
//{
 //   transactionID=ID;
//    if(transactionID=='D')
 //   {
        
//    }
//}
/*ostream& operator<<(ostream &out, const Transaction &trans)
{
    out<<trans.accnt.getAccount()<<" "<<trans.accnt.getLastN()<<" "
    <<trans.accnt.getFirstN()<<" ";
    for (int i=0; i<10; i++)
    {
        out<<setw(4)<<trans.accnt.getFund()[i];
    }
    return out;
}*/
void Transaction:: ReadFromAFile(string fileName, queue<Transaction> &qTrans)
{
    //BSTree tree;
    //queue<Transaction> qTrans;
    Transaction line;
    ifstream file;
    file.open(fileName.c_str());
    
    if(!file)
    {
        exit(EXIT_FAILURE);//cout<<"File cannot be opened"<<endl;
    }
    else
    {
        while(!file.eof())
        {
            file>>line;
            qTrans.push(line);
        }
    }
  //PopFromQueue(qTrans, tree);
  //return qTrans;
  //PopFromQueue(qTrans);
  
}
char Transaction:: getTransactionID()const
{
  return transactionID;
}
void Transaction:: Deposit(Transaction &trans, BSTree &tree)
{
    Account *ptrAccnt; //*ptrAccnt;
    int fundID=trans.accnt.getAccount()%10;
    trans.accnt.setAccount(trans.accnt.getAccount()/10);
    if(tree.Retrive(trans.accnt, ptrAccnt)!=false)
    {
        if(trans.amount<0)
        {
            cout<<"ERROR: you cant deposit negative amount ("<<trans.amount<<")"<<endl;
        }
        ptrAccnt->fundTrans(fundID, trans.amount);
        ptrAccnt->addToHistory(&trans, fundID);
    }
  else if(tree.Retrive(trans.accnt, ptrAccnt)==false)
  {
    cout<<"ERROR: account "<<trans.accnt.getAccount()<<" does not exist"<<endl;
  }
}
void Transaction:: Withdraw(Transaction &trans, BSTree &tree)
{
  Account *ptrAccnt; //*ptrAccnt;
  int balance, balance2;
  int fundID=trans.accnt.getAccount()%10;
  trans.accnt.setAccount(trans.accnt.getAccount()/10);
  if(tree.Retrive(trans.accnt, ptrAccnt)!=false)
  {
    balance=ptrAccnt->getFundBalance(fundID);
    if(trans.amount<0)
    {
      cout<<"ERROR: you cant withdraw negative amount ("<<trans.amount<<")"<<endl;
    }
    else
    {
      if(balance<trans.amount)
      {
        if(fundID==0 || fundID==2)
        {
          balance2=ptrAccnt->getFundBalance(fundID+1);
          if(balance+balance2>=trans.amount)
          {
            int money=trans.amount-balance;
            balance2=balance2-money;
            ptrAccnt->fundTrans(fundID, -(trans.amount-money));
            ptrAccnt->fundTrans(fundID+1, -(money));
          }
          else if(balance+balance2<trans.amount)
          {
            cout<<"ERROR: No sufficient funds to withdraw from: "<<endl;
            cout<<trans.accnt.getFundToString(fundID)<<" and "<<trans.accnt.getFundToString(fundID+1)<<" accounts"<<endl;
          }
        }
        else if(fundID==1 || fundID==3)
        {
          balance2=ptrAccnt->getFundBalance(fundID-1);
          if(balance+balance2>=trans.amount)
          {
            int money=trans.amount-balance;
            balance2=balance2-money;
            ptrAccnt->fundTrans(fundID, -(trans.amount-money));
            ptrAccnt->fundTrans(fundID-1, -(money));
          }
          else if(balance+balance2<trans.amount)
          {
            cout<<"ERROR: No sufficient funds to withdraw from: "<<endl;
            cout<<trans.accnt.getFundToString(fundID)<<" and "<<trans.accnt.getFundToString(fundID-1)<<" accounts"<<endl;
          }
        }
        else
        {
          cout<<"ERROR: No sufficient funds to withdraw from "<<trans.accnt.getFirstN()<<" "<<trans.accnt.getLastN()<<" "<< trans.accnt.getAccount()<<" "<<trans.accnt.getFundToString(fundID)<<" account"<<endl;
        }
        
      }
      else
      {
        ptrAccnt->fundTrans(fundID, -trans.amount);
      }
      }
     }
  else
  {
    cout<<"ERROR: account "<<trans.accnt.getAccount()<<" does not exist"<<endl;
  }
}
void Transaction:: Transfer(Transaction &trans, BSTree &tree)
{
  Account *ptrAccnt;
  Account *ptrAccnt2;
  int balance, balance2;
  int fundID=trans.accnt.getAccount()%10;
  trans.accnt.setAccount(trans.accnt.getAccount()/10);
  int fundID2=trans.accnt2.getAccount()%10;
  trans.accnt2.setAccount(trans.accnt2.getAccount()/10);
  if(tree.Retrive(trans.accnt, ptrAccnt)!=false && tree.Retrive(trans.accnt2, ptrAccnt2)!=false)
  {
    balance=ptrAccnt->getFundBalance(fundID);
    if(trans.amount<0)
    {
      cout<<"ERROR: you cant withdraw negative amount ("<<trans.amount<<")"<<endl;
    }
    else
    {
      if(balance<trans.amount)
      {
        /*if(fundID==0 || fundID==2)
        {
          balance2=ptrAccnt->getFundBalance(fundID+1);
          if(balance+balance2>=trans.amount)
          {
            int money=trans.amount-balance;
            balance2=balance2-money;
            ptrAccnt->fundTrans(fundID, -(trans.amount-money));
            ptrAccnt->fundTrans(fundID+1, -(money));
          }
          else if(balance+balance2<trans.amount)
          {
            cout<<"ERROR: Not sufficient funds to transfer from: "<<endl;
            cout<<trans.accnt.getFundToString(fundID)<<" and "<<trans.accnt.getFundToString(fundID+1)<<" accounts"<<endl;
          }
        }
        else if(fundID==1 || fundID==3)
        {
          balance2=ptrAccnt->getFundBalance(fundID-1);
          if(balance+balance2>=trans.amount)
          {
            int money=trans.amount-balance;
            balance2=balance2-money;
            ptrAccnt->fundTrans(fundID, -(trans.amount-money));
            ptrAccnt->fundTrans(fundID-1, -(money));
          }
          else if(balance+balance2<trans.amount)
          {
            cout<<"ERROR: Not sufficient funds to transfer from: "<<endl;
            cout<<trans.accnt.getFundToString(fundID)<<" and "<<trans.accnt.getFundToString(fundID+1)<<" accounts"<<endl;
          }
        }
        else
        {*/
          cout<<"ERROR: No sufficient funds to transfer from "<<trans.accnt.getFirstN()<<" "<<trans.accnt.getLastN()<<" "<< trans.accnt.getAccount()<<" "<<trans.accnt.getFundToString(fundID)<<" account"<<endl;
        //}
        
      }
      else
      {
        ptrAccnt->fundTrans(fundID, -trans.amount);
        ptrAccnt2->fundTrans(fundID2, trans.amount);
        //trans.accnt.fundTrans(fundID, -trans.amount);
        //trans.accnt2.fundTrans(fundID2, trans.amount);
      }
    }
  }
  else if(tree.Retrive(trans.accnt, ptrAccnt)==false || tree.Retrive(trans.accnt2, ptrAccnt2)==false)
  {
    if(tree.Retrive(trans.accnt, ptrAccnt)==false && tree.Retrive(trans.accnt2, ptrAccnt2)==false)
    {
      cout<<"ERROR: cant transfer between unexisted accounts: "<<trans.accnt.getAccount()<<" and "<<trans.accnt2.getAccount()<<endl;
    }
    else if(tree.Retrive(trans.accnt, ptrAccnt)==false)
    {
      cout<<"ERROR: cant transfer from unexisted account: "<<trans.accnt.getAccount()<<endl;
    }
    else
    {
      cout<<"ERROR: cant transfer to unexisted account: "<<trans.accnt2.getAccount()<<endl;
    }
  }
  
}







void Transaction:: History(Transaction &trans, BSTree &tree)
{
  //long temp=trans.accnt.getAccount();
  //string convert=to_string(temp);
  //long size=convert.length();
  //if(size==4)
  //{
    
 // }
  //else
 // {
    int fundID=trans.accnt.getAccount()%10;
    trans.accnt.setAccount(trans.accnt.getAccount()/10);
    trans.accnt.history.addToHistory(&trans, fundID);
  //}
  
  
  
}
void Transaction:: Open(Transaction &trans, BSTree &tree)
{
    Account *ptrAccnt;
    if(tree.Retrive(trans.accnt, ptrAccnt)==true)
    {
      cout<<"ERROR: "<<trans.accnt.getAccount()<<" already exists"<<endl;
    }
    else
    {
      //trans.accnt.setInitialFund();
      tree.Insert(&trans.accnt);
    }
}
istream& operator>>(istream & in, Transaction &transaction)
{
    //BSTree tree;
    in>>transaction.transactionID;
    if(transaction.transactionID=='O')
    {
        string lastN, firstN;
        int account;
        in>>lastN;
        in>>firstN;
        in>>account;
        transaction.accnt.setLastN(lastN);
        transaction.accnt.setFirstN(firstN);
        transaction.accnt.setAccount(account);
        transaction.accnt.setInitialFund();
        //Open(transaction.accnt, tree);
        //transaction.Open(transaction, tree);
      
    }
    else if (transaction.transactionID=='D')
    {
        //transaction.accnt.restoreName();
        int temp;
        in>>temp;
        //int fundNum=temp%10;
        transaction.accnt.setAccount(temp);//(temp/10);
        in>>transaction.amount;
        //Deposit(transaction.accnt, fundNum, transaction.amount, tree);
        //Transaction::Deposit(transaction);
      
    }
    else if(transaction.transactionID=='W')
    {
        //transaction.accnt.restoreName();
        int temp;
        in>>temp;
        //int fundNum=temp%10;
        transaction.accnt.setAccount(temp);///10);
        in>>transaction.amount;
        //Withdraw(transaction.accnt, fundNum, transaction.amount, tree);
      
    }
    else if(transaction.transactionID=='T')
    {
      int temp1, temp2;
      in>>temp1;
      transaction.accnt.setAccount(temp1);
      in>>transaction.amount;
      in>>temp2;
      transaction.accnt2.setAccount(temp2);
      
      
    }
    else if(transaction.transactionID=='H')
    {
      int temp;
      in>>temp;
      transaction.accnt.setAccount(temp);
      
      
    }
    //else if(transaction.transactionID==')
    //return in;
    return in;
    
}

void Transaction:: PopFromQueue(queue<Transaction> &myQ, BSTree &tree)
{
    //BSTree tree;
    Transaction trans;
    while(!myQ.empty())
    {
        //trans=myQ.front();
        //myQ.pop();
        if(myQ.front().getTransactionID()=='O')//trans.getTransactionID()=='O')
        {
          Open(myQ.front(), tree);
          myQ.pop();
        }
        else if(myQ.front().getTransactionID()=='D')
        {
          trans.Deposit(myQ.front(), tree);
          myQ.pop();
        }
        else if(myQ.front().getTransactionID()=='W')
        {
          Withdraw(myQ.front(), tree);
          myQ.pop();
        }
        else if(myQ.front().getTransactionID()=='T')
        {
          Transfer(myQ.front(), tree);
          myQ.pop();
        }
        else if(myQ.front().getTransactionID()=='H')
        {
          History(myQ.front(), tree);
          myQ.pop();
        }
    }
  //tree.Display();
}


void Transaction:: operator=(const Transaction &source)
{
  this->transactionID=source.transactionID;
  this->amount=source.amount;
  this->accnt=source.accnt;
  this->accnt2=source.accnt2;
  
}
void Transaction:: setErrorMessage(string message)
{
  ERROR=message;
}
ostream& operator<<(const ostream &out, Transaction &transaction)
{
 
  char transID=transaction.getTransactionID();
  if(transID=='D')
  {
    out<<transID<<" "<<transaction.getAccount()<<" "<<//;transaction.
  out<<
  if(


















