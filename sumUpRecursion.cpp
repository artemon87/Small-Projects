#include <iostream>

using namespace std;

int sumUp(int n);
void printU(int n);



int main()
{
 cout<<"Hello"<<endl;
 cout<<sumUp(5)<<endl;
 printU(5);
 return 1;
}
int sumUp(int n)
{
  int sum=0;
  if (n==0)
  {
    return n;
  }
  else
  {
    sum=n+sumUp(n-1);
  }
  return sum;
}
void printU(int n)
{
  if(n==0)
  {
    cout<<n;
  }
  else
  {
    //cout<<n;
    printU(n-1);
    cout<<n;
  }
}