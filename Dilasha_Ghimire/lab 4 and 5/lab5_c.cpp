
#include <iostream>
using namespace std;

class Celsius;

class Fahrenheit {
private:
    float temp;

public:
    Fahrenheit(float t = 0) {
        temp = t;
    }

    Fahrenheit(Celsius c);

    friend ostream& operator<<(ostream& out, const Fahrenheit& f);
};

class Celsius {
private:
    float temp;

public:
    Celsius(float t = 0) {
        temp = t;
    }

    operator float() {
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Celsius& c);
};

Fahrenheit::Fahrenheit(Celsius c) {
    temp = (float)c * 9 / 5 + 32;
}

ostream& operator<<(ostream& out, const Celsius& c) {
    out << c.temp << " C";
    return out;
}

ostream& operator<<(ostream& out,const Fahrenheit& f) {
    out << f.temp << " F";
    return out;
}

int main() {

    Celsius c1 = 25;
    cout << "Celsius = " << c1 << endl;
    float x = c1;
     cout << "Float Value = " << x << endl;
    Fahrenheit f1 = c1;

    cout << "Fahrenheit = " << f1 << endl;

    Celsius c2 = 100;

    Fahrenheit f2(c2);

    cout << "Converted Fahrenheit = "<< f2 << endl;

    return 0;
}