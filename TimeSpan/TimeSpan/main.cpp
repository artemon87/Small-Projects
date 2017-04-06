#include "TimeSpan.h"
#include <iostream>


using namespace std;

int main()
{
    int x=2;
    double m=2.5;
    m=int (x);
    cout<<m<<endl;
    TimeSpan <double> in;
    cout<<"Enter houts, minutes, and seconds "<<endl;
    //cin>>in;
    //cout<<in;
    TimeSpan <double> time (1, 0, -13);
    TimeSpan <double> time2(0, 1, 13);
    TimeSpan <double> time3;
    time3=time2+time;
    //cout<<"Tem3=: "<<time3<<endl;
    //cout<<"Hours: "<<time.getHours()<<endl;
    time.getMinutes();
    //time.cast(1, 84, -68);

    //cout << "Hello world!" << endl;
    return 0;
}

