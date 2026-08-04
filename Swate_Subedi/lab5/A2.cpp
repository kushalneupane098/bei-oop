#include <iostream>

using namespace std;

class Fraction
{
private:
    int num, den;

    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return (a < 0) ? -a : a;
        }
        return gcd(b, a % b);
    }

    void reduce()
    {
        int g = gcd(num, den);
        num /= g;
        den /= g;
    }

public:
    Fraction()
    {
        num = 0;
        den = 1;
    }

    Fraction(int n, int d)
    {
        num = n;
        den = d;
        reduce();
    }

    Fraction(double val)
    {
        num = val * 1000;
        den = 1000;
        reduce();
    }

    operator double() const
    {
        return (double)num / den;
    }

    friend Fraction operator+(Fraction f1, Fraction f2)
    {
        return Fraction(f1.num * f2.den + f2.num * f1.den, f1.den * f2.den);
    }

    friend Fraction operator-(Fraction f1, Fraction f2)
    {
        return Fraction(f1.num * f2.den - f2.num * f1.den, f1.den * f2.den);
    }

    friend Fraction operator*(Fraction f1, Fraction f2)
    {
        return Fraction(f1.num * f2.num, f1.den * f2.den);
    }

    friend Fraction operator/(Fraction f1, Fraction f2)
    {
        return Fraction(f1.num * f2.den, f1.den * f2.num);
    }

    friend bool operator<(Fraction f1, Fraction f2)
    {
        return (f1.num * f2.den) < (f2.num * f1.den);
    }

    friend bool operator>(Fraction f1, Fraction f2)
    {
        return (f1.num * f2.den) > (f2.num * f1.den);
    }

    friend bool operator==(Fraction f1, Fraction f2)
    {
        return (f1.num * f2.den) == (f2.num * f1.den);
    }

    friend ostream &operator<<(ostream &os, Fraction f)
    {
        os << f.num << "/" << f.den;
        return os;
    }

    friend istream &operator>>(istream &is, Fraction &f)
    {
        char slash;
        is >> f.num >> slash >> f.den;
        f.reduce();
        return is;
    }
};

int main()
{
    Fraction f1, f2;

    cout << "Enter f1 (n/d): ";
    cin >> f1;
    cout << "Enter f2 (n/d): ";
    cin >> f2;

    cout << "\nAdd: " << f1 + f2 << "\n";
    cout << "Sub: " << f1 - f2 << "\n";
    cout << "Mul: " << f1 * f2 << "\n";
    cout << "Div: " << f1 / f2 << "\n";

    cout << "\nf1 < f2: " << (f1 < f2) << "\n";
    cout << "f1 > f2: " << (f1 > f2) << "\n";
    cout << "f1 == f2: " << (f1 == f2) << "\n";

    double d = f1;
    cout << "\nDouble value of f1: " << d << "\n";
    cout << "From double (0.25): " << Fraction(0.25) << "\n";

    return 0;
}