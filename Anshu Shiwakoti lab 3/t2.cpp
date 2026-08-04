#include <iostream>
using namespace std;

class Time
{
private:
    int day, hour, minute, second;

public:
    Time(int d, int h, int m, int s)
    {
        day = d;
        hour = h;
        minute = m;
        second = s;
    }

    void addTime(Time t1, Time t2)
    {
        second = t1.second + t2.second;
        minute = t1.minute + t2.minute;
        hour = t1.hour + t2.hour;
        day = t1.day + t2.day;

        if (second >= 60)
        {
            minute += second / 60;
            second %= 60;
        }

        if (minute >= 60)
        {
            hour += minute / 60;
            minute %= 60;
        }

        if (hour >= 24)
        {
            day += hour / 24;
            hour %= 24;
        }
    }

    void display()
    {
        cout << day << " Day " << hour << " Hour " << minute << " Minute " << second << " Second" << endl;
    }
};

int main()
{
    Time t1(2, 20, 50, 40);
    Time t2(1, 10, 30, 30);
    Time t3(0, 0, 0, 0);

    t3.addTime(t1, t2);

    cout << "Time 1: ";
    t1.display();

    cout << "Time 2: ";
    t2.display();

    cout << "Result: ";
    t3.display();

    return 0;
}