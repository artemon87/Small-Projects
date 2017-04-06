#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <algorithm>
#include <array>
#include <vector>



using namespace std;
class Grabber{
public:
 int a;
 int b;
 int c;
};

class Tuition{
double tuition, fees;

public:
void calculate(int credit)
{
  double cred2=795.00;
  double cred3=1192.00;
  double cred4=1589.00;
  double cred5=1986.00;
  double cred6=2383.00;
  double cred7=2780.00;
  double cred8=3177.00;
  double cred9=3574.00;
  double cred10up18=3971.00;

  if(credit==5)
  {
  cout<<"Your tuition fees are $"<<cred5<<"\n";
  }
  if(credit==10 || credit==12 || credit==15)
  {
  cout<<"Your tuition fees are $"<<cred10up18<<"\n";
  }
 }
};




void hello(string words)
    {
      //transform(words.begin(), words.end(), words.begin(), tolower);
      for(int i=0; i<words.length(); ++i)
      {
        words[i]=tolower(words[i]);
      }
      if(words=="artem")
      {
        cout <<"Your last name is Kovtunenko" <<endl;
        //return words;
       }
       else
       {
        cout <<"Your last name is unknown" <<endl;
       // return words;
       }
     }

int main()
{
  cout <<"Please print the name you would like to reverse" <<endl;
  char word[20];
  cin >> word;
  cout <<"That name is " <<word <<endl;
  int a=0;
  int len;
  len=strlen(word)-1;
 for(int i=0; i<=strlen(word)-1; ++i)
  {  
    ++a;
    char letter=word[len];
    --len;
    cout <<letter << "";
    
  }
  cout<<endl;
  string stword(word);
  cout<<"Your random name is: ";
  int num;
  num=strlen(word); //returns the length of the word
   //cout<<"Num is: "<<num<<endl;
  vector<int> vec;
  int r=num;
  for(int i=0; i<num; ++i)
  {
    int random=rand()%r;
    if(find(vec.begin(), vec.end(), random)!=vec.end())
    {
    ++num;
    }
    else{
      vec.push_back(random);
      cout<<stword.at(random);
         }
    
  }
  cout<<endl;
    //stringstream charTOstring;
    //string stringWord;
    //charTOstring << word;
    //chartTOstring << stringWord;
    string stringWord(word); //converting char to string
    string myname="Artem";
    hello(stringWord);
    cout <<endl;
    cout << "Number of letters " << a <<endl;
    int some=2;
    //cout <<some <<endl;
    int random=rand() % 10+1;
    cout << "Now chose any random number from 1-10. If you win your are lucky" <<endl;
    int ran;
    cin>>ran;
    cout <<"your number is " <<ran <<endl;
    int count=0;
    while(ran!=random)
    {
      count++;
      cout<< "Try again. Random # is:" <<random <<endl;
      random=rand() % 10+1;
      cin>>ran;
     }
     cout<<"After "<<count <<" tries you got lucky. Random # is "<<random <<endl;
    //string s("Hello");
    //cout << s;
    cout<<"Enter 5 of you luckiest numbers\n";
   
    int array[5];
    for(int i=0; i<5; ++i)
    {
      cin>>array[i];
    }
    cout<<"You have entered those numbers: ";
for(int elem:array)
{
  cout<<elem <<" ";
    
}
cout<<endl;  
random=rand()%5+1;
cout<<"Your luckiest number right now is "<<array[random]<<endl;
cout<<"How many credits are you going to take this quater?"<<endl;
int c;
cin>>c;
Tuition t;
t.calculate(c);

  //return 0;
Grabber first;
Grabber second;
first.a=2;
second.a=3;
second.b=16;
cout<<"First.a = "<<first.a<<endl;
cout<<"Second.a ="<<second.a<<endl;
}




























































































