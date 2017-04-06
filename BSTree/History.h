#ifndef _HISTORY_H_
#define _HISTORY_H_


#include <stdio.h>
#include "Account.h"
#include "Transaction.h"
#include <vector>
#include <iostream>
#include <string>
#include <queue>

class History
{
  private: 
  
    vector<Transaction> moneyMarket;
    vector<Transaction> primeMoneyMarket";
    vector<Transaction> longTermBond";
    vector<Transaction> shortTermBond";
    vector<Transaction> indexFund";
    vector<Transaction> capitalValueFund";
    vector<Transaction> growthEquityFund";
    vector<Transaction> rowthIndexFund";
    vector<Transaction> valueFund";
    vector<Transaction> valueStockIndex";
    
  public:
    
    History();
    void addHistory(int ID, TRansaction *trans);
    void printHistory(Transaction *trans);
    void printHistory(Transactionint *trans, int ID);
};

#endif