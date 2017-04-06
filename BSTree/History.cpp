#include <stdio.h>
#include "Account.h"
#include "Transaction.h"
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include "History.h"

using namespace std;

History:: History()
{
    moneyMarket;
    primeMoneyMarket;
    longTermBond;
    shortTermBond;
    indexFund;
    capitalValueFund;
    growthEquityFund;
    rowthIndexFund;
    valueFund;
    valueStockIndex;
}
void History:: addHistory(int ID, TRansaction *trans)
{
  if(ID==0)
  {
    moneyMarket.push_back(trans);
  }
  else if(ID==1)
  {
    primeMoneyMarketpush_back(trans);
  }
    LongTermBond;
    ShortTermBond;
    indexFund;
    capitalValueFund;
    growthEquityFund;
    rowthIndexFund;
    valueFund;
    valueStockIndex;
void History:: printHistory()
{
  while(!LongTermBond.empty())
  {
    for(int i=0; i<LongTermBond.size(); i++)
    {
      cout<<LongTermBond[i]
    }
  }
  while(!ShortTermBond.empty())
  {
    for(int i=0; i<ShortTermBond.size(); i++)
    {
      cout<<ShortTermBond[i]
    }
  }
  while(!IndexFund.empty())
  {
    for(int i=0; i<indexFund.size(); i++)
    {
      cout<<IndexFund[i]
    }
  }

}
void History:: printHistory(int ID)
{
  if(ID==0)
  {
    if(!moneyMarket.empty())
    {
      for(int i=0; i<moneyMarket.size(); i++)
      {
        cout<<moneyMarket[i]
      }
    }
    else
    {
      cout<<trans.get
  }
  else if(ID==1)
  {
  