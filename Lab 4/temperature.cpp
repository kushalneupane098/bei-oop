#include <iostream>
using namespace std;

class Temperature
{
private:
    float celsius;

public:
    Temperature(float temp)
    {
        celsius = temp;
    }

    void setTemperature(float temp)
    {
        celsius = temp;
    }

    float getFahrenheit()
    {
        return (celsius * 9 / 5) + 32;
    }

    float getKelvin()
    {
        return celsius + 273.15;
    }

    friend bool areEqual(Temperature t1, Temperature t2);
};

bool areEqual(Temperature t1, Temperature t2)
{
    if (t1.celsius == t2.celsius)
        return true;
    else
        return false;
}

int main()
{
    Temperature t1(25);
    Temperature t2(30);

    cout << "Temperature in Fahrenheit: " << t1.getFahrenheit() << endl;
    cout << "Temperature in Kelvin: " << t1.getKelvin() << endl;

    t2.setTemperature(25);

    if (areEqual(t1, t2))
        cout << "Both temperatures are Equal." << endl;
    else
        cout << "Both temperatures are Not Equal." << endl;

    return 0;
}