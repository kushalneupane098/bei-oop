/*
Question 1:
Write a program with a class Complex having private members real and imag
(both float). Overload the binary + and - operators as member functions
to add and subtract two complex numbers. Overload the == operator as a
friend function to compare two complex numbers for equality. Overload
the << and >> operators as friend functions so that a Complex object can
be directly read from cin and printed to cout in the form (a + bi).
Demonstrate all operators in main.
*/

#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    friend bool operator==(const Complex& c1, const Complex& c2);

    friend istream& operator>>(istream& input, Complex& c);
    friend ostream& operator<<(ostream& output, const Complex& c);
};

bool operator==(const Complex& c1, const Complex& c2) {
    return c1.real == c2.real && c1.imag == c2.imag;
}

istream& operator>>(istream& input, Complex& c) {
    input >> c.real >> c.imag;
    return input;
}

ostream& operator<<(ostream& output, const Complex& c) {
    output << "(" << c.real;

    if (c.imag >= 0)
        output << " + " << c.imag << "i)";
    else
        output << " - " << -c.imag << "i)";

    return output;
}

int main() {
    Complex c1, c2;

    cout << "Enter real and imaginary parts of first complex number: ";
    cin >> c1;

    cout << "Enter real and imaginary parts of second complex number: ";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;

    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;

    if (c1 == c2)
        cout << "Both complex numbers are equal." << endl;
    else
        cout << "The complex numbers are not equal." << endl;

    return 0;
}