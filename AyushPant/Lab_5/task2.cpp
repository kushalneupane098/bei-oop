#include<iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    Distance(int f=0, float i=0): feet(f), inches(i) {}
    Distance operator-() { return Distance(-feet, -inches); }
    Distance& operator++() {
        inches++;
        if(inches >= 12) { feet++; inches -= 12; }
        return *this;
    }
    Distance operator++(int) {
        Distance temp = *this;
        ++(*this);
        return temp;
    }
    friend Distance operator*(const Distance& d, int s) { return Distance(d.feet*s, d.inches*s); }
    friend Distance operator*(int s, const Distance& d) { return Distance(d.feet*s, d.inches*s); }
    friend ostream& operator<<(ostream& os, const Distance& d) {
        os << d.feet << "ft " << d.inches << "in";
        return os;
    }
};

int main() {
    Distance d(3, 11.5);
    cout << "d = " << d << endl;
    cout << "-d = " << -d << endl;
    cout << "++d = " << ++d << endl;
    cout << "d++ = " << d++ << endl;
    cout << "after d++ = " << d << endl;
    cout << "d*3 = " << d*3 << endl;
    cout << "2*d = " << 2*d << endl;
    return 0;
}
