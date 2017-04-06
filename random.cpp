#include <iostream>
#include <string>

using namespace std;

int some(int &);
int hash(string , int);
int main ()
{
  int *one;
  int two=2;
  int three[1];
  
  int *four=&two;
  
  some(*four);
  string strin = "Apple";
  int num = strin[0];
  cout<< num <<endl;
  int size = 10;
  int hashN = hash(strin, size);
  cout<< hashN <<endl;
  return 0;
}
int some (int &num)
{
  return num;
}

int hash(string name, int size)
{
  int hashNum = 0;
  for(int i = 0; i < name.length(); i++)
  {
    hashNum = 37*hashNum + name[i];
  }
  cout<< hashNum <<endl;
  hashNum %= size;
  if(hashNum < 0)
  {
    hashNum += size;
  }
  return hashNum;
}