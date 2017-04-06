#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;
class Base;
string toString(string a, string b, int c);
void Func1(Base *b, Base &d);

class Base
{
  public:
  Base()
  {
    cout<<"base constructor was created"<<endl;
  }
  Base (const Base &source)
  {
    this->b1=source.b1;
    this->b2=source.b2;
    cout<<"Copy constructor call "<<endl;
  }
  /*Base(int a, int b)
  {
    b1=a;
    b2=b;  
  }*/
  ~Base()
  {
    cout<<"Base distructor is called"<<endl;
    }
  virtual void print()
  {
    cout<<"this is the base class"<<endl;
  }
  Base Func1(Base &copy)
  {
    return copy;
  }
  Base Func2(Base copy)
  {
    b1=copy.b1;
    b2=copy.b2;
  }
  Base& Func3(Base &copy)
  {
    return copy;
  }
  void get()
  {
    cout<< b1 << " " << b2 <<endl;;
  }
  Base(Base first, const Base &second, Base &third)
  {
    int x=second.b1;
    b2 = second.b2;
    this->b1 = third.b1;
    third.b1 = b1;
    third.b1 = x;
  }
  private:
  int b1;
  int b2;
};
class Drived: public Base
{
  public:
  Drived()
  {
    cout<<"Drived constructor was created"<<endl;
  }
  Drived(int n, int m)
  {
   //cout<<"You just created initialized object using NEW"<<n*m<<endl;
   d1=m+n;
  }
  ~Drived()
  {
   cout<<"Drived distructor is called"<<endl;
  }
  void print()
  {
    cout<<"this is the Drived class"<<endl;
    cout<<this->d1<<endl;//<<" "<<this->d2<<endl;
    //Base:: print();
  }
  void getItem(int m, int n);
  private: 
  int d1;
};

/*void ErrorCheck(Base first, const Base &second, Base &third)const
{
  int x=second.b1;
  b1 = first.b1;
  this->b1 = third.b1;
  third.b1 = b1;
  third.b1 = x
}*/
int main()
{

  Drived drived1 (1, 2);
  Base *base1;
  Base base;
  drived1.print();
  Drived drived2 (2,5);
  base1=&drived1;
  base1->print();
  Base *base2=new Base();
  delete base2;
  base2=NULL;
  base2=&drived2;
  base2->print();
  Func1(base1, base);
  
 
  
  
  
   
  //string zxS=string (zx);
  string aa="Hello";
  string bb="World";
  int cc=3;
  char ch[4]={0,1,2,3};
  char *chP=&ch[3];
  cout<<"CH pointer: "<<*chP<<endl;
  //toString(aa, bb, cc);
  
  
  
  return 0;
}
string toString(string aa, string bb, int cc)
{
  stringstream abc;
  abc<<aa<<" "<<bb<<" "<<cc<<endl;
  string result=abc.str();
  cout<<result<<endl;
}
void Func1(Base *b, Base &d)
{
  Base *z=b;
  cout<<"Printing Z pointer"<<endl;
  z->print();
  delete z;
  z=NULL;
  
  z=&d;
  cout<<"Printing Z pointer"<<endl;
  z->print();
}