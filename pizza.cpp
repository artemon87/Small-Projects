#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

double const price=10.99;
double const toppings=2.99;
double perP;
double perT;
int number;
string cheese;
string combo;
string papperoni;

class firstClass
{
 

public: 
firstClass()
{
  cheese="Cheese";
  combo="Combo";
  papperoni="Papperoni";
  //cout <<"No parameters" <<endl;
}
void something(int a, int b, int c)
{
  //int array[number];
  number=a+b+c;
  //while(tot>number)
  //{
   // cout<<"you have ordered too many pizzas. You hab=ve initially ordered only "<<number<<" pizzas\n";
   // cout<<"Let us know again the total # of pizzas you would like to order" <<endl;
   // cin>>number;
  //}
  vector <int> vectorArray;
  vectorArray.push_back(a);
  vectorArray.push_back(b);
  vectorArray.push_back(c);
  //for(i+0; i<vectorArray.size(); ++i)
  //{
    cout<<"You have ordered:\n "<<vectorArray[0] <<" of "<<cheese<<" pizza\n " <<vectorArray[1] <<" of "<<combo<< " pizza\n "<< vectorArray[2]<<" of "<<papperoni<<" pizzas"<<endl;  
  
}
void Wellcome()
{
  cout << "Wellcome to Pizzaria\n" << "Please tell us your name" <<endl;
}
};



void pizzaNumber(int a)
{
  perP=a*price;
}
void pizzaToppings(int b)
{
while (b>3 && b!=0)
{
  cout <<"You cant have more than 3 and less then 1 toppings per pizza. Enter amount 3 or less" <<endl;
  cout << "how many toppings per pizza?\n";
  cin>>b;
}
if (b==1)
{
    perT=0;
}
else
{
  perT=toppings*b;
}
}
double total()
{
  return perP+perT;
}
void pizzaType()
{
  cout<<"How many "<<cheese<<" pizza would you like to order\n";
  int che;
  cin>>che;
  cout << "How many "<<combo<<" pizza would you like to order\n";
  int com;
  cin>>com;
  cout<<"How many "<<papperoni<<" pizza would you like to order\n";
  int pap;
  cin>>pap;
  firstClass f;
  f.something(che, com, pap); 
  
}
int main()
{
  firstClass first;
  first.Wellcome();
  string name;
  cin>>name;
  for(int i=0; i<name.length(); ++i)
  {
    name[i]=toupper(name[i]);
  }
  cout <<"Thank you for choosing our pizza " <<name <<endl;
  //cout<<"How many pizzas would you like to order?\n";
  //int number;
  //cin >> number;
  pizzaType();
  pizzaNumber(number);
  //pizzaType();
  cout << "How many toppings per pizza?\n";
  int top;
  cin>>top;
  pizzaToppings(top);
  double totalpizza=total();
  cout<< "Your total " <<name <<" is " <<totalpizza <<endl;
}