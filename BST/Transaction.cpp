#include "Transaction.h"
#include "BSTRee.h"
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using namespace std;

Transaction:: Transaction()
{
  successful=false;

}
Transaction:: ~Transaction()
{}

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
    if(tree.Retrive(trans.accnt, ptrAccnt)==true)
    {
        if(trans.amount<0)
        {
            cout<<"ERROR: you cant deposit negative amount ("<<trans.amount<<")"<<endl;
            ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
            trans.successful=false;
        }
      else
      {
        trans.successful=true;
        ptrAccnt->setFundIDNum(fundID);
        ptrAccnt->fundTrans(fundID, trans.amount);
        ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
        //HistoryObj *temp;
        //ptrAccnt->getHistoryObj()->addToHistory(&trans, fundID);//->addToHistory(trans, fundID);
      //temp->addToHistory(&trans, fundID);
        //ptrAccnt->addToHistory(&trans, fundID);
      }
    }
  else if(tree.Retrive(trans.accnt, ptrAccnt)==false)
  {
    cout<<"ERROR: account "<<trans.accnt.getAccount()<<" does not exist"<<endl;
  }
}
void Transaction:: Withdraw(Transaction &trans, BSTree &tree)
{
  Account *ptrAccnt; //*ptrAccnt;
  int balance=0;
  int balance2=0;
  int fundID=trans.accnt.getAccount()%10;
  trans.accnt.setAccount(trans.accnt.getAccount()/10);
  if(tree.Retrive(trans.accnt, ptrAccnt)!=false)
  {
    trans.successful=true;
    balance=ptrAccnt->getFundBalance(fundID);
    ptrAccnt->setFundIDNum(fundID);
    if(trans.amount<0)
    {
      cout<<"ERROR: you cant withdraw negative amount ("<<trans.amount<<")"<<endl;
      trans.successful=false;
      ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
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
            ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
          }
          else if(balance+balance2<trans.amount)
          {
            cout<<"ERROR: No sufficient funds to withdraw from: "<<endl;
            cout<<trans.accnt.getFundToString(fundID)<<" and "<<trans.accnt.getFundToString(fundID+1)<<" accounts"<<endl;
            trans.successful=false;
            ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
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
            ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
          }
          else if(balance+balance2<trans.amount)
          {
            cout<<"ERROR: No sufficient funds to withdraw from: "<<endl;
            cout<<trans.accnt.getFundToString(fundID)<<" and "<<trans.accnt.getFundToString(fundID-1)<<" accounts"<<endl;
            trans.successful=false;
            ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
          }
        }
        else
        {
          cout<<"ERROR: No sufficient funds to withdraw from "<<trans.accnt.getFirstN()<<" "<<trans.accnt.getLastN()<<" "<< trans.accnt.getAccount()<<" "<<trans.accnt.getFundToString(fundID)<<" account"<<endl;
              trans.successful=false;
          ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
        }

      }
      else
      {
        ptrAccnt->fundTrans(fundID, -trans.amount);
        ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
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
  int balance=0;
  //int balance2=0;;
  int fundID=trans.accnt.getAccount()%10;
  trans.accnt.setAccount(trans.accnt.getAccount()/10);
  int fundID2=trans.accnt2.getAccount()%10;
  trans.accnt2.setAccount(trans.accnt2.getAccount()/10);
  if(tree.Retrive(trans.accnt, ptrAccnt)!=false && tree.Retrive(trans.accnt2, ptrAccnt2)!=false)
  {
    trans.successful=true;
    ptrAccnt->setFundIDNum(fundID);
    ptrAccnt2->setFundIDNum(fundID2);
    balance=ptrAccnt->getFundBalance(fundID);
    if(trans.amount<0)
    {
      cout<<"ERROR: you cant withdraw negative amount ("<<trans.amount<<")"<<endl;
       trans.successful=false;
      ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
    }
    else
    {
      if(balance<trans.amount)
      {
          cout<<"ERROR: No sufficient funds to transfer from "<<trans.accnt.getFirstN()<<" "<<trans.accnt.getLastN()<<" "<< trans.accnt.getAccount()<<" "<<trans.accnt.getFundToString(fundID)<<" account"<<endl;
         trans.successful=false;
         ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
        //}

      }
      else
      {
        trans.successful=true;
        ptrAccnt->fundTrans(fundID, -trans.amount);
        ptrAccnt2->fundTrans(fundID2, trans.amount);
        ptrAccnt->addToHistory(*historyToString(*ptrAccnt, trans.transactionID, trans.amount, trans), fundID);
        ptrAccnt2->addToHistory(*historyToString(*ptrAccnt2, trans.transactionID, trans.amount, trans), fundID2);
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
  int size = 1;
  int account = trans.accnt.getAccount();
  while ( account /= 10 )
  {
    size++;
  }
  Account *ptrAccnt;
  //long temp=trans.accnt.getAccount();
  //string convert=to_string(temp);
  //long size=convert.length();
  if(size==4)
  {
    if(tree.Retrive(trans.accnt, ptrAccnt)!=false)
    {
      ptrAccnt->displayHistory(*ptrAccnt);
    }
    else
    {
      cout<<"ERROR: cant display a history of unexisted account: "<<trans.accnt.getAccount()<<endl;
    }
  }
  else
  {
    int fundID=trans.accnt.getAccount()%10;
    trans.accnt.setAccount(trans.accnt.getAccount()/10);
    if(tree.Retrive(trans.accnt, ptrAccnt)!=false)
    {
      ptrAccnt->setFundIDNum(fundID);
      ptrAccnt->displayHistory(fundID, *ptrAccnt);
    }
    else
    {
      cout<<"ERROR: cant display a history of unexisted account: "<<trans.accnt.getAccount()<<endl;
    }
  }
}
void Transaction:: Open(Transaction &trans, BSTree &tree)
{
    Account *ptrAccnt;
    if(tree.Retrive(trans.accnt, ptrAccnt)==false)
    {
      tree.Insert(&trans.accnt);
    }
    else
    {
      //trans.accnt.setInitialFund();
      cout<<"ERROR: "<<trans.accnt.getAccount()<<" already exists"<<endl;
    }
                              // tree.Display();
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

ostream& operator<<(ostream &out, const Transaction &transaction)
{
  char temp=transaction.getTransactionID();
  if(temp=='D')
  {
    out<<transaction.transactionID<<" "<<transaction.accnt.getAccount()<<transaction.accnt.getFundIDNum()<<" "<<transaction.amount<<endl;
  }
  else if(temp=='T')
  {
    out<<transaction.transactionID<<" "<<transaction.accnt.getAccount()<<transaction.accnt.getFundIDNum()<<" "
    <<transaction.amount<<" "<<transaction.accnt2.getAccount()<<transaction.accnt2.getFundIDNum()<<endl;
  }
  return out;
}
string* Transaction:: historyToString(Account &accnt, char transID, int bill, Transaction &trans)
{
  stringstream convertor;
  string errorCheck="REJECTED";
  int account=accnt.getAccount();
  int fundNumber=accnt.getFundIDNum();
  if(transID!='T')
  {
    if(trans.successful==true)
    {
      convertor<<setw(4)<<transID<<" "<<account<<fundNumber<<" "<<bill;
    }
    else
    {
      convertor<<transID<<" "<<account<<fundNumber<<" "<<bill<<" "<<errorCheck;
    }
  }
  else
  {
    if(trans.successful==true)
    {
      convertor<<setw(4)<<transID<<" "<<account<<fundNumber<<" "<<bill<<" "<<trans.accnt2.getAccount()<<trans.accnt2.getFundIDNum();
    }
    else
    {
      convertor<<transID<<" "<<account<<fundNumber<<" "<<bill<<" "<<trans.accnt2.getAccount()<<trans.accnt2.getFundIDNum()<<" "<<errorCheck;
    }
  }
    string output=convertor.str();
    //cout<<output<<endl;
    string *finalOutput;
    finalOutput=&output;
  return finalOutput;
}
