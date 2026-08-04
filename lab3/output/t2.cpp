#include <iostream>
using namespace std;

class Time {
private:
    int hour, minute, second, day;

public:
    Time() {
        hour = minute = second = day = 0;
    }


    Time(int hr, int min, int sec, int d) {
        hour = hr;
        minute = min;
        second = sec;
        day = d;
    }


    void display() {
        cout << "Time = "
             << day << " days "
             << hour << " hours "
             << minute << " minutes "
             << second << " seconds" << endl;
    }


    Time add_time(Time T2) {
        Time T3;

        T3.second = second + T2.second;
        T3.minute = minute + T2.minute + T3.second / 60;
        T3.second %= 60;

        T3.hour = hour + T2.hour + T3.minute / 60;
        T3.minute %= 60;

        T3.day = day + T2.day + T3.hour / 24;
        T3.hour %= 24;

        return T3;
    }
};

int main() {
    Time t1(50, 3, 50, 799);
    Time t2(50, 3, 50, 799);

    Time result;

    result = t1.add_time(t2);

    result.display();

    return 0;
}