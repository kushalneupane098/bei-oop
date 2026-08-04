#include<iostream>
using namespace std;

class Fahrenheit;

class Celsius {
    float temp;
public:
    Celsius(float t=0): temp(t) {}
    operator float() const { return temp; }
    operator Fahrenheit() const;
    friend ostream& operator<<(ostream& os, const Celsius& c) {
        os << c.temp << "C";
        return os;
    }
};

class Fahrenheit {
    float temp;
public:
    Fahrenheit(float t=0): temp(t) {}
    friend ostream& operator<<(ostream& os, const Fahrenheit& f) {
        os << f.temp << "F";
        return os;
    }
};

Celsius::operator Fahrenheit() const { return Fahrenheit(temp * 9.0f/5.0f + 32); }

int main() {
    Celsius c = 100.0f;
    cout << "Celsius: " << c << endl;
    float t = c;
    cout << "As float: " << t << endl;
    Fahrenheit f = c;
    cout << "Converted to Fahrenheit: " << f << endl;
    return 0;
}
