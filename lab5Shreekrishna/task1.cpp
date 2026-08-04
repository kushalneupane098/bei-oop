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

    friend istream& operator>>(istream& in, Complex& c);

    friend ostream& operator<<(ostream& out, Complex c);
};

bool operator==(Complex c1, Complex c2)
{
    return (c1.real == c2.real && c1.imag == c2.imag);
}

istream& operator>>(istream& in, Complex& c)
{
    in >> c.real >> c.imag;
    return in;
}

ostream& operator<<(ostream& out, Complex c)
{
    out << "(" << c.real << " + " << c.imag << "i)";
    return out;
}

int main()
{
    Complex c1, c2, sum, diff;

    cout << "Enter first complex number (real imag): ";
    cin >> c1;

    cout << "Enter second complex number (real imag): ";
    cin >> c2;

    sum = c1 + c2;
    diff = c1 - c2;

    cout << "\nSum = " << sum;
    cout << "\nDifference = " << diff;

    if (c1 == c2)
        cout << "\nBoth complex numbers are equal.";
    else
        cout << "\nBoth complex numbers are not equal.";

    return 0;
}