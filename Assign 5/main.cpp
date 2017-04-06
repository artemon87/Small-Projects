
#include <iostream>
#include "BSTree.h"
#include "Transaction.h"
#include <fstream>

using namespace std;

int main() {


  cout<<"TAMAGOCHA"<<endl;
    //Account t;

    Transaction a;
    cout<<"Tam"<<endl;
    BSTree tree;
    cout<<"ma"<<endl;
    queue<Transaction> myQ;
    cout<<"go"<<endl;
    a.ReadFromAFile("BankTrans.txt", myQ);
    cout<<"cha"<<endl;
    a.PopFromQueue(myQ, tree);
    tree.Display();
    //std::cout << "Hello, World!\n";
    //Account a;
    //BSTree tree;
    //tree.Insert(&a);
    return 0;
}
