#include <iostream>

using namespace std;

int sumUp(int b);
int main()
{
  int number=6;
  int *pointer;
  cout<<"Number stored in Number is: "<<number<<endl;
  cout<<"Location of that Number is: "<<&number<<endl;
  cout<<"Pointer is located: "<<&pointer<<endl;
  pointer=&number;
  cout<<"Pointer is pointing to address that has a vlues stored as: "<<*pointer<<endl;
  cout<<"Pointer is pointing to this location: "<<pointer<<endl;
  cout<<"Pointer's actual address is: "<<&pointer<<endl;
  
  *pointer=7;
  cout<<"Now pointer is pointing to the address whose value is: "<<*pointer<<endl;
  cout<<"Number's vules is" <<number<<endl;
  
  int array[4]={1, 2, 3, 4};
  pointer=array;
  int n=sizeof(array)/sizeof(array[0]);
  cout<<"SIZE of an array "<<n<<endl;
  for(int i=0; i<n; i++)
  {
    cout<<*(pointer+i)<<endl;
  }
  int *p=new int[2];
  int *p2=(int*)malloc
  cout<<endl;
  cout<<"Array's address is " <<&array<<endl;
  cout<<"Pointer is pointing to arrays address " <<pointer<<endl;
  cout<<"The value that pointer is pointing to is " <<*pointer<<endl;
  cout<<"Now pointer has moved to the next value of an array "<<*pointer+3<<endl;
  
 // printArray(&array);
 int a=1;
 int b=4;
cout<<sumUp(10);
//cout<<"A= "<<a<<endl;
  
  return 0;
}
int sumUp(int a)
{
//cout<<"QQQQQQQQQQQQQQQ"<<endl;
int sum=0;
 if(a>0)
 {
   //cout<<"A before: "<<a<<endl;;
   sum=a+sumUp(a-1);
   cout<<"A after: "<<a<<endl;
   cout<<"First sum "<<sum<<endl;

   return sum;
   //cout<<a;
 }
 else
 {
   sum=a;
   cout<<"First !!! sum= "<<sum<<endl;
   //cout<<"And then it goes back to what ever was after the function call()"<<endl;
 }
 return sum;
 }