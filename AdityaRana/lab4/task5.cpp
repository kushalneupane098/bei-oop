#include <iostream>
using namespace std;

class Temperature {
private:
    float celsius;

public:
    Temperature(float c) {
        celsius = c;
    }

    float toFahrenheit() {
        return (celsius * 9 / 5) + 32;
    }

    float toKelvin() {
        return celsius + 273.15;
    }

    friend bool areEqual(Temperature, Temperature);
};

Temperature temp(float value) {
    return Temperature(value);
}

bool areEqual(Temperature t1, Temperature t2) {
    return t1.celsius == t2.celsius;
}

int main() {
    Temperature t1 = temp(25);
    Temperature t2 = temp(25);

    cout << "Fahrenheit: " << t1.toFahrenheit() << endl;
    cout << "Kelvin: " << t1.toKelvin() << endl;

    if (areEqual(t1, t2))
        cout << "Temperatures are equal\n";
    else
        cout << "Temperatures are not equal\n";

    return 0;
}