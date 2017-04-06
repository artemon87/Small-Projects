#include <iostream>
#include "TimeSpan.h"

using namespace std;

int main()
{
    TimeSpan time (1, 0, -13);
    TimeSpan time2(0, 1, 13);
    TimeSpan time3;
    time3=time2+time;
    cout<<"Tem3=: "<<time3<<endl;
    time.getHours();
    time.getMinutes();
    //time.cast(1, 84, -68);

    //cout << "Hello world!" << endl;
    return 0;
}
