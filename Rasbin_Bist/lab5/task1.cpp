#include <iostream>

using namespace std;

class Complex
{
private:
    float real, imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    Complex operator+(const Complex &other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex &other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    friend bool operator==(const Complex &lhs, const Complex &rhs)
    {
        return (lhs.real == rhs.real && lhs.imag == rhs.imag);
    }

    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << "(" << c.real << " + " << c.imag << "i)";
        return os;
    }

    friend istream &operator>>(istream &is, Complex &c)
    {
        is >> c.real >> c.imag;
        return is;
    }
};

int main()
{
    Complex c1, c2;
    cout << "Enter c1 (real imag): ";
    cin >> c1;
    cout << "Enter c2 (real imag): ";
    cin >> c2;

    cout << "c1 + c2 = " << c1 + c2 << "\n";
    cout << "c1 - c2 = " << c1 - c2 << "\n";
    cout << "c1 == c2: " << (c1 == c2 ? "True" : "False") << "\n";
    return 0;
}