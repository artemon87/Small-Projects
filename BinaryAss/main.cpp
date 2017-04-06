#include <iostream>
#include "Binary.h"

using namespace std;

int main()
{
    Binary c(3);
    Binary a;
    Binary b(2);
    Binary d(13);
    //Binary c(3);
    //Binary c2(15);
    a=b-1;
    a+=1;
    cout<<"Before: "<<a<<endl;
    a-=c;
    cout<<"After: "<<a<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
