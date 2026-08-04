#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius
{
    float temp;

public:
    Celsius(float t = 0)
    {
        temp = t;
    }

    operator float() const
    {
        return temp;
    }

    operator Fahrenheit() const;

    friend ostream &operator<<(ostream &out, const Celsius &c);
};

class Fahrenheit
{
    float temp;

public:
    Fahrenheit(float t = 0)
    {
        temp = t;
    }

    Fahrenheit(const Celsius &c)
    {
        temp = (float)c * 9 / 5 + 32;
    }

    friend ostream &operator<<(ostream &out, const Fahrenheit &f);
};

Celsius::operator Fahrenheit() const
{
    return Fahrenheit(temp * 9 / 5 + 32);
}

ostream &operator<<(ostream &out, const Celsius &c)
{
    out << c.temp << " C";
    return out;
}

ostream &operator<<(ostream &out, const Fahrenheit &f)
{
    out << f.temp << " F";
    return out;
}

int main()
{
    Celsius c1(25);

    float x = c1;

    Fahrenheit f1 = c1;

    Celsius c2(100);

    Fahrenheit f2(c2);

    cout << "Celsius object: " << c1 << endl;
    cout << "Float value: " << x << endl;
    cout << "Celsius to Fahrenheit: " << f1 << endl;
    cout << "Another conversion: " << f2 << endl;

    return 0;
}
