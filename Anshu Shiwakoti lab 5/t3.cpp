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

    operator float() const
    {
        return temp;
    }

    operator Fahrenheit() const;

    friend ostream &operator<<(ostream &out, const Celsius &c);
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
    Celsius c = 25.0;        
    float x = c;             
    Fahrenheit f = c;       

    cout << "Celsius = " << c << endl;
    cout << "Float = " << x << endl;
    cout << "Fahrenheit = " << f << endl;

    return 0;
}