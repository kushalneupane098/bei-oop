/*
Question 3:
Write a program with two classes Celsius and Fahrenheit, each having a
private float member for temperature. In the Celsius class, write a
conversion constructor from float, a conversion operator to float, and
a conversion operator to Fahrenheit using F = C * 9 / 5 + 32. In the
Fahrenheit class, write a conversion constructor from Celsius. Overload
<< for both classes. In main, demonstrate assigning a float directly to
a Celsius object, extracting a float from a Celsius object, and converting
between Celsius and Fahrenheit objects.
*/

#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
private:
    float temperature;

public:
    Celsius(float temp = 0) {
        temperature = temp;
    }

    operator float() const {
        return temperature;
    }

    operator Fahrenheit() const;

    float getTemperature() const {
        return temperature;
    }

    friend ostream& operator<<(ostream& output, const Celsius& c);
};

class Fahrenheit {
private:
    float temperature;

public:
    Fahrenheit(float temp = 0) {
        temperature = temp;
    }

    Fahrenheit(const Celsius& c) {
        temperature = c.getTemperature() * 9.0f / 5.0f + 32;
    }

    float getTemperature() const {
        return temperature;
    }

    friend ostream& operator<<(ostream& output, const Fahrenheit& f);
};

Celsius::operator Fahrenheit() const {
    return Fahrenheit(temperature * 9.0f / 5.0f + 32);
}

ostream& operator<<(ostream& output, const Celsius& c) {
    output << c.temperature << " degree Celsius";
    return output;
}

ostream& operator<<(ostream& output, const Fahrenheit& f) {
    output << f.temperature << " degree Fahrenheit";
    return output;
}

int main() {
    // Conversion from float to Celsius
    Celsius c1 = 25.0f;

    cout << "Celsius Temperature: " << c1 << endl;

    // Conversion from Celsius to float
    float value = static_cast<float>(c1);
    cout << "Extracted Float Value: " << value << endl;

    // Using the Celsius conversion operator
    Fahrenheit f1 = c1.operator Fahrenheit();
    cout << "Converted Using Conversion Operator: " << f1 << endl;

    // Using Fahrenheit conversion constructor
    Fahrenheit f2(c1);
    cout << "Converted Using Conversion Constructor: " << f2 << endl;

    return 0;
}