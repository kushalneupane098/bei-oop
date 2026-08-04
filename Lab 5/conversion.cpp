#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius
{
private:
    float temp;

public:
    Celsius(float t = 0)
    {
        temp = t;
    }

    float getTemp()
    {
        return temp;
    }

    Fahrenheit toFahrenheit();

    friend ostream& operator<<(ostream &out, Celsius c);
};

class Fahrenheit
{
private:
    float temp;

public:
    Fahrenheit(float t = 0)
    {
        temp = t;
    }

    friend ostream& operator<<(ostream &out, Fahrenheit f);
};

Fahrenheit Celsius::toFahrenheit()
{
    return Fahrenheit(temp * 9 / 5 + 32);
}

ostream& operator<<(ostream &out, Celsius c)
{
    out << c.temp << " C";
    return out;
}

ostream& operator<<(ostream &out, Fahrenheit f)
{
    out << f.temp << " F";
    return out;
}

int main()
{
    Celsius c(25);

    float x = c.getTemp();

    Fahrenheit f = c.toFahrenheit();

    cout << "Celsius = " << c << endl;
    cout << "Float = " << x << endl;
    cout << "Fahrenheit = " << f << endl;

    return 0;
}