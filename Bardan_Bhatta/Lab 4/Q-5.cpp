#include <iostream>
using namespace std;

class Temperature {
private:
    float celsius;

public:
    Temperature(float c) {
        celsius = c;
    }

    void setTemp(float c) {
        celsius = c;
    }

    float toFahrenheit() const {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    float toKelvin() const {
        return celsius + 273.15;
    }

    void display() const {
        cout << celsius << " C (" << toFahrenheit() << " F | " << toKelvin() << " K)" << endl;
    }

    friend bool areEqual(Temperature t1, Temperature t2);
};

bool areEqual(Temperature t1, Temperature t2) {
    return (t1.celsius == t2.celsius);
}

int main() {
    Temperature temp1(37.0); 
    Temperature temp2(37.0);
    Temperature temp3(100.0); 

    cout << "Temperature 1: "; temp1.display();
    cout << "Temperature 2: "; temp2.display();
    cout << "Temperature 3: "; temp3.display();

    cout << "\nComparing Temperature 1 and Temperature 2..." << endl;
    if (areEqual(temp1, temp2)) {
        cout << "Result: The temperatures are identical." << endl;
    } else {
        cout << "Result: The temperatures differ." << endl;
    }

    cout << "\nComparing Temperature 1 and Temperature 3..." << endl;
    if (areEqual(temp1, temp3)) {
        cout << "Result: The temperatures are identical." << endl;
    } else {
        cout << "Result: The temperatures differ." << endl;
    }

    return 0;
}