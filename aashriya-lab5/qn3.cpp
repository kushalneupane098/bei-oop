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

    operator float()
    {
        return temp;
    }

    operator Fahrenheit();

    friend ostream &operator<<(ostream &out, Celsius c);
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

    Fahrenheit(Celsius c)
    {
        float ct = (float)c;
        temp = ct * 9 / 5 + 32;
    }

    friend ostream &operator<<(ostream &out, Fahrenheit f);
};

Celsius::operator Fahrenheit()
{
    return Fahrenheit(temp * 9 / 5 + 32);
}

ostream &operator<<(ostream &out, Celsius c)
{
    out << c.temp << " C";
    return out;
}

ostream &operator<<(ostream &out, Fahrenheit f)
{
    out << f.temp << " F";
    return out;
}

int main()
{
    Celsius c = 25.5;

    float x = c;

    Fahrenheit f1 = c;
    Fahrenheit f2(c);

    cout << "Celsius = " << c << endl;
    cout << "Float = " << x << endl;
    cout << "Fahrenheit = " << f1 << endl;

    return 0;
}