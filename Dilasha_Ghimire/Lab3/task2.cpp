#include <iostream>
using namespace std;

class Time {
private:
    int d, h, m, s;

public:
    Time(int dd = 0, int hh = 0, int mm = 0, int ss = 0) {
        d = dd;
        h = hh;
        m = mm;
        s = ss;
    }

    void addTime(Time t1, Time t2) {
        s = t1.s + t2.s;
        m = t1.m + t2.m + s / 60;
        s = s % 60;

        h = t1.h + t2.h + m / 60;
        m = m % 60;

        d = t1.d + t2.d + h / 24;
        h = h % 24;
    }

    void display() {
        cout << d << " day " << h << " hour " << m << " min " << s << " sec" << endl;
    }
};

int main() {
    Time t1(1, 14, 45, 50);
    Time t2(0, 11, 20, 25);
    Time t3;

    t3.addTime(t1, t2);

    cout << "T1: ";
    t1.display();

    cout << "T2: ";
    t2.display();

    cout << "Sum: ";
    t3.display();

    return 0;
}