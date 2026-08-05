#include <iostream>
using namespace std;

class Temperature {
private:
	float celsius;

public:
	Temperature(float c = 0.0f) : celsius(c) {}

	float toFahrenheit() const {
		return (celsius * 9.0f / 5.0f) + 32.0f;
	}

	float toKelvin() const {
		return celsius + 273.15f;
	}

	void setTemp(float temp) {
		celsius = temp;
	}

	friend bool areEqual(Temperature t1, Temperature t2);
};

bool areEqual(Temperature t1, Temperature t2) {
	return t1.celsius == t2.celsius;
}

int main() {
	Temperature t1(25.0f), t2;

	cout << "Temperature 1 in Fahrenheit: " << t1.toFahrenheit() << endl;
	cout << "Temperature 1 in Kelvin: " << t1.toKelvin() << endl;

	t2.setTemp(25.0f);
	cout << "Temperature 2 in Fahrenheit: " << t2.toFahrenheit() << endl;
	cout << "Temperature 2 in Kelvin: " << t2.toKelvin() << endl;

	cout << "Are temperatures equal? " << (areEqual(t1, t2) ? "Yes" : "No") << endl;

	t2.setTemp(30.0f);
	cout << "After changing Temperature 2: " << (areEqual(t1, t2) ? "Yes" : "No") << endl;

	return 0;
}

