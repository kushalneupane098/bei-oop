#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    // + operator
    Complex operator+(Complex c) {
        return Complex(real + c.real,imag + c.imag);
    }
    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // == operator
    friend bool operator==(Complex c1,Complex c2);
    friend istream& operator>>(istream& in,Complex& c);

 
    friend ostream& operator<<(ostream& out, Complex& c);
};

bool operator==(Complex c1, Complex c2) {
    return (c1.real == c2.real && c1.imag == c2.imag);
}

istream& operator>>(istream& in,  Complex& c) {
    cout << "Enter Real Part: ";
    in >> c.real;

    cout << "Enter Imaginary Part: ";
    in >> c.imag;

    return in;
}

ostream& operator<<(ostream& out, Complex& c) {
    out << "(" << c.real
        << " + " << c.imag << "i)";
    return out;
}

int main() {
    Complex c1, c2, c3;

    cin >> c1;
    cin >> c2;

    c3 = c1 + c2;
    cout << "\nAddition = " << c3 << endl;

    c3 = c1 - c2;
    cout << "Subtraction = " << c3 << endl;

    if (c1 == c2)
        cout << "Both Complex Numbers are Equal";
    else
        cout << "Not Equal";

    return 0;
}