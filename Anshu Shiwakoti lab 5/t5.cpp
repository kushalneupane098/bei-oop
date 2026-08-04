#include <iostream>
#include <cmath>
using namespace std;

class Fraction
{
private:
    int numerator, denominator;

    void reduce()
    {
        int a = abs(numerator);
        int b = abs(denominator);

        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }

        numerator /= a;
        denominator /= a;

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int n = 0, int d = 1)
    {
        numerator = n;
        denominator = d;
        reduce();
    }

    Fraction(double value)
    {
        denominator = 1000;
        numerator = value * denominator;
        reduce();
    }

    operator double() const
    {
        return (double)numerator / denominator;
    }

    friend Fraction operator+(Fraction a, Fraction b);
    friend Fraction operator-(Fraction a, Fraction b);
    friend Fraction operator*(Fraction a, Fraction b);
    friend Fraction operator/(Fraction a, Fraction b);

    friend bool operator<(Fraction a, Fraction b);
    friend bool operator>(Fraction a, Fraction b);
    friend bool operator==(Fraction a, Fraction b);

    friend ostream &operator<<(ostream &out, Fraction f);
    friend istream &operator>>(istream &in, Fraction &f);
};

Fraction operator+(Fraction a, Fraction b)
{
    return Fraction(a.numerator * b.denominator + b.numerator * a.denominator,
                    a.denominator * b.denominator);
}

Fraction operator-(Fraction a, Fraction b)
{
    return Fraction(a.numerator * b.denominator - b.numerator * a.denominator,
                    a.denominator * b.denominator);
}

Fraction operator*(Fraction a, Fraction b)
{
    return Fraction(a.numerator * b.numerator,
                    a.denominator * b.denominator);
}

Fraction operator/(Fraction a, Fraction b)
{
    return Fraction(a.numerator * b.denominator,
                    a.denominator * b.numerator);
}

bool operator<(Fraction a, Fraction b)
{
    return a.numerator * b.denominator < b.numerator * a.denominator;
}

bool operator>(Fraction a, Fraction b)
{
    return a.numerator * b.denominator > b.numerator * a.denominator;
}

bool operator==(Fraction a, Fraction b)
{
    return a.numerator == b.numerator &&
           a.denominator == b.denominator;
}

ostream &operator<<(ostream &out, Fraction f)
{
    out << f.numerator << "/" << f.denominator;
    return out;
}

istream &operator>>(istream &in, Fraction &f)
{
    char ch;
    in >> f.numerator >> ch >> f.denominator;
    f.reduce();
    return in;
}

int main()
{
    Fraction f1, f2;

    cout << "Enter first fraction (a/b): ";
    cin >> f1;

    cout << "Enter second fraction (a/b): ";
    cin >> f2;

    cout << "First Fraction: " << f1 << endl;
    cout << "Second Fraction: " << f2 << endl;

    cout << "Addition: " << f1 + f2 << endl;
    cout << "Subtraction: " << f1 - f2 << endl;
    cout << "Multiplication: " << f1 * f2 << endl;
    cout << "Division: " << f1 / f2 << endl;

    if (f1 < f2)
        cout << "First fraction is smaller." << endl;
    else if (f1 > f2)
        cout << "First fraction is greater." << endl;
    else
        cout << "Both fractions are equal." << endl;

    double d = f1;
    cout << "Fraction to double: " << d << endl;

    Fraction f3 = 2.75;
    cout << "Double to Fraction: " << f3 << endl;

    return 0;
}