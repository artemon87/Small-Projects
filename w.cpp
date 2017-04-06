#include <iostream>
using namespace std;

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
    cout <<letter << " ";
    
    
  }
    cout <<endl;
    cout << "Number of letters " << a;
  
  return 0;
}