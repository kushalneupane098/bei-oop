#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return abs(a);
    return gcd(b, a % b);
}

class Fraction {
    int num, den;

    void reduce() {
        int g = gcd(num, den);
        num /= g;
        den /= g;
        if (den < 0) {
            den = -den;
            num = -num;
        }
    }

public:
    Fraction(int n = 0, int d = 1) {
        num = n;
        den = d;
        reduce();
    }

    Fraction(double d) {
        den = 1000;
        num = (int)(d * den);
        reduce();
    }

    operator double() const {
        return (double)num / den;
    }

    friend Fraction operator+(Fraction a, Fraction b);
    friend Fraction operator-(Fraction a, Fraction b);
    friend Fraction operator*(Fraction a, Fraction b);
    friend Fraction operator/(Fraction a, Fraction b);

    friend bool operator<(Fraction a, Fraction b);
    friend bool operator>(Fraction a, Fraction b);
    friend bool operator==(Fraction a, Fraction b);

    friend ostream& operator<<(ostream& out, const Fraction& f);
    friend istream& operator>>(istream& in, Fraction& f);
};

Fraction operator+(Fraction a, Fraction b) {
    return Fraction(a.num * b.den + b.num * a.den,
                    a.den * b.den);
}

Fraction operator-(Fraction a, Fraction b) {
    return Fraction(a.num * b.den - b.num * a.den,
                    a.den * b.den);
}

Fraction operator*(Fraction a, Fraction b) {
    return Fraction(a.num * b.num,
                    a.den * b.den);
}

Fraction operator/(Fraction a, Fraction b) {
    return Fraction(a.num * b.den,
                    a.den * b.num);
}

bool operator<(Fraction a, Fraction b) {
    return a.num * b.den < b.num * a.den;
}

bool operator>(Fraction a, Fraction b) {
    return a.num * b.den > b.num * a.den;
}

bool operator==(Fraction a, Fraction b) {
    return a.num * b.den == b.num * a.den;
}

ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.num << "/" << f.den;
    return out;
}

istream& operator>>(istream& in, Fraction& f) {
    char ch;
    in >> f.num >> ch >> f.den;
    f.reduce();
    return in;
}

int main() {
    Fraction f1, f2;

    cout << "Enter first fraction (num/den): ";
    cin >> f1;

    cout << "Enter second fraction (num/den): ";
    cin >> f2;

    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction prod = f1 * f2;
    Fraction div = f1 / f2;

    cout << "\nf1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    cout << "\nAddition: " << sum << endl;
    cout << "Subtraction: " << diff << endl;
    cout << "Multiplication: " << prod << endl;
    cout << "Division: " << div << endl;

    if (f1 < f2)
        cout << "\nf1 < f2" << endl;
    else if (f1 > f2)
        cout << "\nf1 > f2" << endl;
    else
        cout << "\nf1 == f2" << endl;

    double val = f1;
    cout << "\nDecimal value of f1: " << val << endl;

    double x = 3.141;
    Fraction f3 = x;
    cout << "Fraction from double (3.141): " << f3 << endl;

    return 0;
}
