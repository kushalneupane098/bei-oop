#include<iostream>
using namespace std;

class Complex {
    float real, imag;
public:
    Complex(float r=0, float i=0): real(r), imag(i) {}
    Complex operator+(const Complex& c) { return Complex(real+c.real, imag+c.imag); }
    Complex operator-(const Complex& c) { return Complex(real-c.real, imag-c.imag); }
    friend bool operator==(const Complex& a, const Complex& b) { return a.real==b.real && a.imag==b.imag; }
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
    friend istream& operator>>(istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }
};

int main() {
    Complex a, b;
    cout << "Enter real and imag for a: "; cin >> a;
    cout << "Enter real and imag for b: "; cin >> b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a+b = " << a+b << endl;
    cout << "a-b = " << a-b << endl;
    cout << "a==b: " << (a==b ? "true" : "false") << endl;
    return 0;
}
