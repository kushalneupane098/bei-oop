#include <iostream>
using namespace std;

class Fahrenheit;
class Celsius;

class Celsius {
private:
    float temp;

public:
    Celsius(float t = 0) : temp(t) {}

    Celsius(const Fahrenheit &f);

    operator float() const {
        return (temp * 9.0 / 5.0) + 32.0;
    }

    friend ostream& operator<<(ostream &out, const Celsius &c) {
        out << c.temp << " C";
        return out;
    }
    
    float getTemp() const { return temp; }
};

class Fahrenheit {
private:
    float temp;

public:
    Fahrenheit(float t = 0) : temp(t) {}

    Fahrenheit(const Celsius &c) {
        temp = (float)c; 
    }

    operator float() const {
        return (temp - 32.0) * 5.0 / 9.0;
    }

    friend ostream& operator<<(ostream &out, const Fahrenheit &f) {
        out << f.temp << " F";
        return out;
    }
};

Celsius::Celsius(const Fahrenheit &f) {
    temp = (float)f; 
}

int main() {
    Celsius c(25);
    Fahrenheit f = c;

    cout << "Celsius: " << c << endl;
    cout << "Converted to Fahrenheit: " << f << endl;

    Fahrenheit f2(77);
    Celsius c2 = f2; 
    
    cout << "\nFahrenheit: " << f2 << endl;
    cout << "Converted to Celsius: " << c2 << endl;

    return 0;
}