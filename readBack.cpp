#include <iostream>
#include <string>

using namespace std;

void readBack(string str);
int i=0;
int main()
{
 //int num;
 string word;
 cout<<"Enter your word"<<endl;
 cin>>word;
 readBack(word);
 return 0;
}
void readBack(string str)
{
  //int length=str.length();
  if(str.length()>0)
  {
    cout<<"Call number: "<<i<<endl;
    i++;
    cout<<str.substr(str.length()-1, 1);
    readBack(str.substr(0, str.length()-1));
  }
}