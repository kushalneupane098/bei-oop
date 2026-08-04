#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
    float temp;

public:
    Celsius(float t = 0) {
        temp = t;
    }

    operator float() {
        return temp;
    }

    operator Fahrenheit();

    friend ostream& operator<<(ostream& out, const Celsius& c);
};

class Fahrenheit {
    float temp;

public:
    Fahrenheit(float t = 0) {
        temp = t;
    }

    explicit Fahrenheit(Celsius c) {
        temp = (float)c * 9.0/5.0 + 32;
    }

    friend ostream& operator<<(ostream& out, const Fahrenheit& f);
};

Celsius::operator Fahrenheit() {
    return Fahrenheit(temp * 9.0/5.0 + 32);
}

ostream& operator<<(ostream& out, const Celsius& c) {
    out << c.temp << " Celsius";
    return out;
}

ostream& operator<<(ostream& out, const Fahrenheit& f) {
    out << f.temp << " Fahrenheit";
    return out;
}

int main() {
    Celsius c = 30.0;

    float value = c;

    Fahrenheit f = c;

    Celsius c2 = 10;
    Fahrenheit f2 = c2;

    cout << "Celsius value: " << c << endl;
    cout << "Float is: " << value << endl;
    cout << "Converted to Fahrenheit: " << f << endl;
    cout << "Another conversion: " << f2 << endl;

    return 0;
}