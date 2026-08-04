#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    Distance(int f = 0, float i = 0) {
        feet = f;
        inches = i;
    }

    Distance operator-() {
        return Distance(-feet, -inches);
    }

    Distance operator++() {
        ++feet;
        return *this;
    }

    Distance operator++(int) {
        Distance temp = *this;
        feet++;
        return temp;
    }

    Distance operator--() {
        --feet;
        return *this;
    }

    Distance operator--(int) {
        Distance temp = *this;
        feet--;
        return temp;
    }

    friend Distance operator*(Distance d, int x) {
        return Distance(d.feet * x, d.inches * x);
    }

    friend Distance operator*(int x, Distance d) {
        return Distance(d.feet * x, d.inches * x);
    }

    friend ostream& operator<<(ostream &out, const Distance &d) {
        out << d.feet << " ft " << d.inches << " in";
        return out;
    }
};

int main() {
    Distance d(5, 6);

    cout << "Original: " << d << endl;
    cout << "Unary - : " << -d << endl;

    cout << "++d: " << ++d << endl;
    cout << "d++: " << d++ << endl;
    cout << "After d++: " << d << endl;

    cout << "--d: " << --d << endl;
    cout << "d--: " << d-- << endl;

    cout << "After d--: " << d << endl;

    cout << "d * 2: " << d * 2 << endl;
    cout << "2 * d: " << 2 * d << endl;
}