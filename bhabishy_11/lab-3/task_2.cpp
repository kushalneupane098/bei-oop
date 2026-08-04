#include <iostream>

class Time {
private:
    int day, hour, minute, second;

public:
    Time(int d, int h, int m, int s) {
        day = d;
        hour = h;
        minute = m;
        second = s;
    }

    void addTime(const Time &t1, const Time &t2) {
        second = t1.second + t2.second;
        minute = t1.minute + t2.minute + (second / 60);
        second %= 60;

        hour = t1.hour + t2.hour + (minute / 60);
        minute %= 60;

        day = t1.day + t2.day + (hour / 24);
        hour %= 24;
    }

    void display() const {
        std::cout << day << " Days, " << hour << " Hours, " 
                  << minute << " Minutes, " << second << " Seconds\n";
    }
};

int main() {
    Time t1(1, 14, 45, 50);
    Time t2(2, 18, 20, 30);
    
    Time t3(0, 0, 0, 0); 
    t3.addTime(t1, t2);

    std::cout << "Time 1: "; t1.display();
    std::cout << "Time 2: "; t2.display();
    std::cout << "Summed Time (Time 3): "; t3.display();
    system("pause");
    return 0;
}