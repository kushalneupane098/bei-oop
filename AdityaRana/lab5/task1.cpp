#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float img;

public:
    Complex(float r = 0, float i = 0) {
        real = r;
        img = i;
    }

    Complex operator+(const Complex &obj) const {
        return Complex(real + obj.real, img + obj.img);
    }

    Complex operator-(const Complex &obj) const {
        return Complex(real - obj.real, img - obj.img);
    }

    friend bool operator==(const Complex &a, const Complex &b) {
        return (a.real == b.real && a.img == b.img);
    }

    friend ostream& operator<<(ostream &out, const Complex &c) {
        out << "(" << c.real;
        if (c.img >= 0)
            out << "+" << c.img << "i)";
        else
            out << c.img << "i)";
        return out;
    }

    friend istream& operator>>(istream &in, Complex &c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.img;
        return in;
    }
};

int main() {
    Complex c1, c2;

    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "Enter second complex number:\n";
    cin >> c2;

    cout << "\n c1 = " << c1 << endl;
    cout << "\n c2 = " << c2 << endl;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\n c1 + c2 = " << sum << endl;
    cout << "\n c1 - c2 = " << diff << endl;

    if (c1 == c2)
        cout << "equal";
    else
        cout << "not equal";

    return 0;
}