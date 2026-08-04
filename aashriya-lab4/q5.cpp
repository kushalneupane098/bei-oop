#include <iostream>
using namespace std;

class Temperature {
private:
    float celsius;

public:
    
    Temperature(float c) {
        celsius = c;
    }

    
    void setTemp(float t) {
        celsius = t;
    }

   
    float toFahrenheit() const {
        return (celsius * 9.0 / 5.0) + 32;
    }

    float toKelvin() const {
        return celsius + 273.15;
    }

  
    friend bool areEqual(Temperature t1, Temperature t2);
};


bool areEqual(Temperature t1, Temperature t2) {
    return t1.celsius == t2.celsius;
}

int main() {
    Temperature t1(25);
    Temperature t2(25);

    cout << "Temperature 1:" << endl;
    cout << "Fahrenheit: " << t1.toFahrenheit() << endl;
    cout << "Kelvin: " << t1.toKelvin() << endl;

    cout << "\nTemperature 2:" << endl;
    cout << "Fahrenheit: " << t2.toFahrenheit() << endl;
    cout << "Kelvin: " << t2.toKelvin() << endl;

    if (areEqual(t1, t2))
        cout << "\nBoth temperatures are equal." << endl;
    else
        cout << "\nTemperatures are not equal." << endl;


    t2.setTemp(30);

    cout << "\nAfter changing Temperature 2:" << endl;

    if (areEqual(t1, t2))
        cout << "Both temperatures are equal." << endl;
    else
        cout << "Temperatures are not equal." << endl;

    return 0;
}