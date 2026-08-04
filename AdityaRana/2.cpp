#include <iostream>
using namespace std;

class Time {
public:
    int day, hour, minute, second;
    Time(int d, int h, int m, int s) {
        day = d;
        hour = h;
        minute = m;
        second = s;
    }

    void addTime(Time t1, Time t2) {
        second = t1.second + t2.second;
        minute = t1.minute + t2.minute + second / 60;
        second = second % 60;
        hour   = t1.hour   + t2.hour   + minute / 60;
        minute = minute % 60;
        day    = t1.day    + t2.day    + hour / 24;
        hour   = hour % 24;
    }

    void display() {
        cout << day << "d " << hour << "h " << minute << "m " << second << "s" << endl;
    }
};

int main() {
    Time t1(1, 23, 45, 50);   
    Time t2(0,  2, 30, 25);   
    Time t3(0,  0,  0,  0);  

    cout << "Time 1: "; t1.display();
    cout << "Time 2: "; t2.display();

    t3.addTime(t1, t2);

    cout << "Sum   : "; t3.display();

    return 0;
}
