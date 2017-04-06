#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
//#include "HistoryObj.h"
//#include "Transaction.h"

using namespace std;

struct HistoryObject
{
    vector<string> MoneyMarket;
    vector<string> PrimeMoneyMarket;
    vector<string> LongTermBond;
    vector<string> ShortTermBond;
    vector<string> IndexFund;
    vector<string> CapitalValueFund;
    vector<string> GrowthEquityFund;
    vector<string> GrowthIndexFund;
    vector<string> ValueFund;
    vector<string> ValueStockIndex;
};

class Transaction;
class Account
{
private:

    int accntNumber;
    string firstName;
    string lastName;
    vector<int> *fund;
    int fundIDNum;
    HistoryObject history;


public:

    Account();
    Account(string lastN, string firstN, int accnt);
    void setLastN(string lastN);
    void setFirstN(string firstN);
    void setInitialFund();
    void setFundIDNum(int num);
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
    int getFundIDNum()const;
    //void addToHistory(Transaction *trans, int fundID);
    void displayHistory()const;
    void setTransHistory();

    ///////////////////////////////////////////////////////////////////////
    void addToHistory(string trans, int ID);
    void displayHistory(Account &accnt);
    void displayHistory(int ID, Account &accnt); //Transaction &trans);
    ///////////////////////////////////////////////////////////////////////

    bool operator<(const Account &source)const;
    bool operator>(const Account &source)const;
    bool operator==(const Account &souce)const;
    bool operator!=(const Account &source)const;
    void operator=(const Account &source);
    friend istream& operator>>(istream &in, Account &input);
    friend ostream& operator<<(ostream &out, const Account &acc);

};

#endif // ACCOUNT_H
