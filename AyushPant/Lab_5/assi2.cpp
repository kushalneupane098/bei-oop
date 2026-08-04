#include<iostream>
#include<cmath>
using namespace std;

class Fraction {
    int num, den;
    int gcd(int a, int b) { return b==0 ? abs(a) : gcd(b, a%b); }
    void reduce() { int g=gcd(num,den); num/=g; den/=g; if(den<0){num=-num;den=-den;} }
public:
    Fraction(int n=0, int d=1): num(n), den(d) { reduce(); }
    Fraction(double v) {
        den = 1000;
        num = (int)round(v * den);
        reduce();
    }
    operator double() const { return (double)num/den; }
    friend Fraction operator+(const Fraction& a, const Fraction& b) { return Fraction(a.num*b.den + b.num*a.den, a.den*b.den); }
    friend Fraction operator-(const Fraction& a, const Fraction& b) { return Fraction(a.num*b.den - b.num*a.den, a.den*b.den); }
    friend Fraction operator*(const Fraction& a, const Fraction& b) { return Fraction(a.num*b.num, a.den*b.den); }
    friend Fraction operator/(const Fraction& a, const Fraction& b) { return Fraction(a.num*b.den, a.den*b.num); }
    friend bool operator<(const Fraction& a, const Fraction& b) { return a.num*b.den < b.num*a.den; }
    friend bool operator>(const Fraction& a, const Fraction& b) { return a.num*b.den > b.num*a.den; }
    friend bool operator==(const Fraction& a, const Fraction& b) { return a.num==b.num && a.den==b.den; }
    friend ostream& operator<<(ostream& os, const Fraction& f) { os << f.num << "/" << f.den; return os; }
    friend istream& operator>>(istream& is, Fraction& f) { char c; is >> f.num >> c >> f.den; f.reduce(); return is; }
};

int main() {
    Fraction a(1,2), b(1,3);
    cout << "a=" << a << " b=" << b << endl;
    cout << "a+b=" << a+b << endl;
    cout << "a-b=" << a-b << endl;
    cout << "a*b=" << a*b << endl;
    cout << "a/b=" << a/b << endl;
    cout << "a<b: " << (a<b) << " a>b: " << (a>b) << " a==b: " << (a==b) << endl;
    cout << "double(a)=" << double(a) << endl;
    Fraction c(0.75);
    cout << "Fraction(0.75)=" << c << endl;
    return 0;
}
