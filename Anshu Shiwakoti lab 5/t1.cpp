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

    Complex operator+(const Complex &c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex &c)
    {
        return Complex(real - c.real, imag - c.imag);
    }

    friend bool operator==(const Complex &c1, const Complex &c2);

    friend istream &operator>>(istream &in, Complex &c);

    friend ostream &operator<<(ostream &out, const Complex &c);
};

bool operator==(const Complex &c1, const Complex &c2)
{
    return (c1.real == c2.real && c1.imag == c2.imag);
}

istream &operator>>(istream &in, Complex &c)
{
    cout << "Enter Real Part: ";
    in >> c.real;
    cout << "Enter Imaginary Part: ";
    in >> c.imag;
    return in;
}

ostream &operator<<(ostream &out, const Complex &c)
{
    out << "(" << c.real << " + " << c.imag << "i)";
    return out;
}

int main()
{
    Complex c1, c2, sum, diff;

    cout << "Enter First Complex Number\n";
    cin >> c1;

    cout << "\nEnter Second Complex Number\n";
    cin >> c2;

    sum = c1 + c2;
    diff = c1 - c2;

    cout << "\nFirst Complex = " << c1 << endl;
    cout << "Second Complex = " << c2 << endl;

    cout << "Sum = " << sum << endl;
    cout << "Difference = " << diff << endl;

    if (c1 == c2)
        cout << "Both Complex Numbers are Equal";
    else
        cout << "Both Complex Numbers are Not Equal";

    return 0;
}