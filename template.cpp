#include <iostream>
#include <cctype>

using namespace std;

template <class Item>
class Art
{
  private:
    Item type;
  public:
    Art(){}
    Item addOne(Item a){ type=a; return ++type;}
};

template<>
class Art <char>
{
  private:
    char ch;
  public:
    Art(){}
    Art(char cha){ch=cha;}
    char toUpperL()const
    { cout<<toupper(ch)<<endl;
      return ch;}
};

int main()
{
  Art <char> a('n');
  Art <char> c ('l');
  
  
  char b=a.toUpperL();
  a=c;
  //b='z';
  cout<<"After: "<<b<<endl;
  Art <int> integ;
  int num=integ.addOne(7);
  cout<<num;
  
  return 0;
}
    