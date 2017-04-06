#include <string>
#include "Account.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

Account:: Account()
{
    //firstName="";
    //lastName="";
    accntNumber=0;
}

//Account:: ~Account()
//{
 //  delete fund;
//}
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
int Account:: getFundIDNum()const
{
    return fundIDNum;
}
void Account:: setFundIDNum(int num)
{
    fundIDNum=num;
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
    accntNumber=source.accntNumber;
    lastName=source.lastName;
    firstName=source.firstName;
    fund=source.fund;
}
istream& operator>>(istream &in, Account &input)
{
    //in>>input.lastName>>input.firstName>>input.accntNumber;
    return in;
}
ostream &operator<<(ostream &out, const Account &acc)
{
    out<<"Account number: "/*<<acc.getFirstN()<<" "<<acc.getLastN()<<" "*/<<acc.getAccount()<<" "<<endl<<endl;
    for (int i=0; i<10; i++)
    {
        out<<acc.getAllNamesOfFunds()[i]<<": $"<<acc.getFund()[i]<<endl;
    }
    out<<endl;
    return out;
}



/////////////////////////////////////////////////////////////////////////////////
//*****************************************************************************//
/////////////////////////////////////////////////////////////////////////////////


void Account:: addToHistory(string trans, int ID)
{
    if(ID==0)
    {
        history.MoneyMarket.push_back(trans);

    }
    else if(ID==1)
    {
        history.PrimeMoneyMarket.push_back(trans);
    }
    else if(ID==2)
    {
        history.LongTermBond.push_back(trans);
    }
    else if(ID==3)
    {
        history.ShortTermBond.push_back(trans);
    }
    else if(ID==4)
    {
        history.IndexFund.push_back(trans);
    }
    else if(ID==5)
    {
        history.CapitalValueFund.push_back(trans);
    }
    else if(ID==6)
    {
        history.GrowthEquityFund.push_back(trans);
    }
    else if(ID==7)
    {
        history.GrowthIndexFund.push_back(trans);
    }
    else if(ID==8)
    {
        history.ValueFund.push_back(trans);
    }
    else if(ID==9)
    {
        history.ValueStockIndex.push_back(trans);
    }
}
void Account:: displayHistory(Account &accnt)
{
    cout<<"*****************************************************"<<endl;
    cout<<"History of transactions for Account: "<<accnt.getAccount()<<" "
    <<accnt.getFirstN()<<" "<<accnt.getLastN()<<endl<<endl;
    if(!history.MoneyMarket.empty())
    {
        cout<<accnt.getFundToString(0)<<endl;
        for(int i=0; i<history.MoneyMarket.size(); i++)
        {
            cout<<accnt.history.MoneyMarket[i];
            cout<<endl;
        }
        cout<<endl;
    }
    if(!history.PrimeMoneyMarket.empty())
    {
        cout<<accnt.getFundToString(1)<<endl;
        for(int i=0; i<history.PrimeMoneyMarket.size(); i++)
        {
            cout<<accnt.history.PrimeMoneyMarket[i];
            cout<<endl;
        }
        cout<<endl;
    }
    if(!history.LongTermBond.empty())
    {
        cout<<accnt.getFundToString(2)<<endl;
        for(int i=0; i<history.LongTermBond.size(); i++)
        {
            cout<<accnt.history.LongTermBond[i];
            cout<<endl;
        }
        cout<<endl;
    }
    if(!history.ShortTermBond.empty())
    {
        cout<<accnt.getFundToString(3)<<endl;
        for(int i=0; i<history.ShortTermBond.size(); i++)
        {
            cout<<accnt.history.ShortTermBond[i];
            cout<<endl;
        }
        cout<<endl;
    }
    if(!history.IndexFund.empty())
    {
        cout<<accnt.getFundToString(4)<<endl;
        for(int i=0; i<history.IndexFund.size(); i++)
        {
            cout<<accnt.history.IndexFund[i];
            cout<<endl;
        }
        cout<<endl;
    }
    if(!history.CapitalValueFund.empty())
    {
        cout<<accnt.getFundToString(5)<<endl;
        for(int i=0; i<history.CapitalValueFund.size(); i++)
        {
            cout<<accnt.history.CapitalValueFund[i];
            cout<<endl;
        }
        cout<<endl;
    }
    if(!history.GrowthEquityFund.empty())
    {
        cout<<accnt.getFundToString(6)<<endl;
        for(int i=0; i<history.GrowthEquityFund.size(); i++)
        {
            cout<<accnt.history.GrowthEquityFund[i];
            cout<<endl;
        }
        cout<<endl;
    }
    if(!history.GrowthIndexFund.empty())
    {
        cout<<accnt.getFundToString(7)<<endl;
        for(int i=0; i<history.GrowthIndexFund.size(); i++)
        {
            cout<<accnt.history.GrowthIndexFund[i];
            cout<<endl;
        }
        cout<<endl;
    }
    if(!history.ValueFund.empty())
    {
        cout<<accnt.getFundToString(8)<<endl;
        for(int i=0; i<history.ValueFund.size(); i++)
        {
            cout<<accnt.history.ValueFund[i];
            cout<<endl;
        }
        cout<<endl;
    }
    if(!history.ValueStockIndex.empty())
    {
        cout<<accnt.getFundToString(9)<<endl;
        for(int i=0; i<history.ValueStockIndex.size(); i++)
        {
            cout<<accnt.history.ValueStockIndex[i];
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<"End of a history of transactions"<<endl;
    cout<<"*****************************************************"<<endl;
}
void Account:: displayHistory(int ID, Account &accnt)
{
    cout<<"*****************************************************"<<endl;
    cout<<"History of fund transaction for Account: "<<accnt.getAccount()<<" "
    <<accnt.getFirstN()<<" "<<accnt.getLastN()<<endl<<endl;
    if(ID==0)
    {

        cout<<accnt.getFundToString(ID)<<endl;
        for(int i=0; i<history.MoneyMarket.size(); i++)
        {
            cout<<accnt.history.MoneyMarket[i];
            cout<<endl;
        }
        cout<<endl;
    }
    else if(ID==1)
    {
        cout<<accnt.getFundToString(ID)<<endl;
        for(int i=0; i<history.PrimeMoneyMarket.size(); i++)
        {
            cout<<accnt.history.PrimeMoneyMarket[i];
            cout<<endl;
        }
        cout<<endl;
    }
    else if(ID==2)
    {
        cout<<accnt.getFundToString(ID)<<endl;
        for(int i=0; i<history.LongTermBond.size(); i++)
        {
            cout<<accnt.history.LongTermBond[i];
            cout<<endl;
        }
        cout<<endl;
    }
    else if(ID==3)
    {
        cout<<accnt.getFundToString(ID)<<endl;
        for(int i=0; i<history.ShortTermBond.size(); i++)
        {
            cout<<accnt.history.ShortTermBond[i];
            cout<<endl;
        }
        cout<<endl;
    }
    else if(ID==4)
    {
        cout<<accnt.getFundToString(ID)<<endl;
        for(int i=0; i<history.IndexFund.size(); i++)
        {
            cout<<accnt.history.IndexFund[i];
            cout<<endl;
        }
        cout<<endl;
    }
    else if(ID==5)
    {
        cout<<accnt.getFundToString(ID)<<endl;
        for(int i=0; i<history.CapitalValueFund.size(); i++)
        {
            cout<<accnt.history.CapitalValueFund[i];
            cout<<endl;
        }
        cout<<endl;
    }
    else if(ID==6)
    {
        cout<<accnt.getFundToString(ID)<<endl;
        for(int i=0; i<history.GrowthEquityFund.size(); i++)
        {
            cout<<&accnt.history.GrowthEquityFund[i];
            cout<<endl;
        }
        cout<<endl;
    }
    else if(ID==7)
    {
        cout<<accnt.getFundToString(ID)<<endl;
        for(int i=0; i<history.GrowthIndexFund.size(); i++)
        {
            cout<<accnt.history.GrowthIndexFund[i];
            cout<<endl;
        }
        cout<<endl;
    }
    else if(ID==8)
    {
        cout<<accnt.getFundToString(ID)<<endl;
        for(int i=0; i<history.ValueFund.size(); i++)
        {
            cout<<accnt.history.ValueFund[i];
            cout<<endl;
        }
        cout<<endl;
    }
    else if(ID==9)
    {
        cout<<accnt.getFundToString(ID)<<endl;
        for(int i=0; i<history.ValueStockIndex.size(); i++)
        {
            cout<<accnt.history.ValueStockIndex[i];
            cout<<endl;
        }
        cout<<endl;
    }
    else
    {
        cout<<"This account is empty"<<endl;
    }
    cout<<"End of a history of fund transaction"<<endl;
    cout<<"*****************************************************"<<endl;
}
