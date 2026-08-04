#include <iostream>

using namespace std;

class Fahrenheit;

class Celsius
{
private:
    float temperature;

public:
    Celsius(float temp = 0) : temperature(temp) {}

    operator float() const { return temperature; }
    operator Fahrenheit() const;

    friend ostream &operator<<(ostream &os, const Celsius &c)
    {
        return os << c.temperature << " C";
    }
};

class Fahrenheit
{
private:
    float temperature;

public:
    Fahrenheit(float temp = 32) : temperature(temp) {}
    Fahrenheit(const Celsius &c) : temperature(static_cast<float>(c) * 9.0 / 5.0 + 32.0) {}

    friend ostream &operator<<(ostream &os, const Fahrenheit &f)
    {
        return os << f.temperature << " F";
    }
};

Celsius::operator Fahrenheit() const
{
    return Fahrenheit(temperature * 9.0 / 5.0 + 32.0);
}

int main()
{
    Celsius c = 25.0f;
    cout << "Celsius: " << c << "\n";

    float f_val = c;
    cout << "Extracted float: " << f_val << "\n";

    Fahrenheit f = c;
    cout << "Converted to Fahrenheit: " << f << "\n";
    return 0;
}