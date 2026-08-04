#include <iostream>
using namespace std;

class Complex
{
private:
    float real, imag;

public:
    Complex(float r = 0, float i = 0)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(Complex c)
    {
        return Complex(real - c.real, imag - c.imag);
    }

    friend bool operator==(Complex c1, Complex c2);

    friend ostream &operator<<(ostream &out, Complex c);
    friend istream &operator>>(istream &in, Complex &c);
};

bool operator==(Complex c1, Complex c2)
{
    return (c1.real == c2.real && c1.imag == c2.imag);
}

ostream &operator<<(ostream &out, Complex c)
{
    out << "(" << c.real << " + " << c.imag << "i)";
    return out;
}

istream &operator>>(istream &in, Complex &c)
{
    in >> c.real >> c.imag;
    return in;
}

int main()
{
    Complex c1, c2;

    cout << "Enter first complex (real imag): ";
    cin >> c1;

    cout << "Enter second complex (real imag): ";
    cin >> c2;

    cout << "Sum = " << c1 + c2 << endl;
    cout << "Difference = " << c1 - c2 << endl;

    if (c1 == c2)
        cout << "Equal\n";
    else
        cout << "Not Equal\n";

    return 0;
}