#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Fraction {
private:
    int num, den;

    void simplify() {
        int g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;
    }

public:
    Fraction(int n = 0, int d = 1) {
        num = n;
        den = d;
        simplify();
    }

    Fraction operator+(Fraction f) {
        return Fraction(num*f.den + f.num*den, den*f.den);
    }

    Fraction operator-(Fraction f) {
        return Fraction(num*f.den - f.num*den, den*f.den);
    }

    Fraction operator*(Fraction f) {
        return Fraction(num*f.num, den*f.den);
    }

    Fraction operator/(Fraction f) {
        return Fraction(num*f.den, den*f.num);
    }

    friend bool operator==(Fraction a, Fraction b) {
        return (a.num == b.num && a.den == b.den);
    }

    friend ostream& operator<<(ostream &out, Fraction f) {
        out << f.num << "/" << f.den;
        return out;
    }
};

int main() {
    Fraction f1(2,3), f2(3,4);

    cout << f1 + f2 << endl;
    cout << f1 - f2 << endl;
    cout << f1 * f2 << endl;
    cout << f1 / f2 << endl;
}