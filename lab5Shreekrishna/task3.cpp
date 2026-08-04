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

    friend ostream& operator<<(ostream& out, Celsius c);
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
        temp = (float)c * 9 / 5 + 32;
    }

    friend ostream& operator<<(ostream& out, Fahrenheit f);
};

ostream& operator<<(ostream& out, Celsius c)
{
    out << c.temp << " C";
    return out;
}

ostream& operator<<(ostream& out, Fahrenheit f)
{
    out << f.temp << " F";
    return out;
}

int main()
{
    Celsius c1 = 25.0;

    float x = c1;

    Fahrenheit f1 = c1;

    Celsius c2(100);

    Fahrenheit f2(c2);

    cout << "Celsius c1 = " << c1 << endl;
    cout << "Float value = " << x << endl;
    cout << "Fahrenheit f1 = " << f1 << endl;
    cout << "Celsius c2 = " << c2 << endl;
    cout << "Fahrenheit f2 = " << f2 << endl;

    return 0;
}