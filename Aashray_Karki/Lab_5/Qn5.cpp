/*
Assignment 2:
Write a program with a class Fraction having private members numerator and
denominator (both int). Overload the +, -, *, and / binary operators as
friend functions, each returning a Fraction in reduced form by dividing
by their GCD. Overload the relational operators <, >, and == as friend
functions. Overload << to print in the form numerator/denominator and >>
to read in the same form. Write a conversion operator operator double() const
that returns the decimal value of the fraction, and a conversion constructor
Fraction(double) that approximates a double as a fraction with denominator
up to 1000. Demonstrate all operations in main.
*/

#include <iostream>
#include <numeric>
#include <cmath>
#include <stdexcept>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        if (denominator == 0)
            throw invalid_argument("Denominator cannot be zero.");

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int divisor = gcd(abs(numerator), abs(denominator));

        numerator /= divisor;
        denominator /= divisor;
    }

public:
    Fraction(int n = 0, int d = 1) {
        numerator = n;
        denominator = d;
        reduce();
    }

    Fraction(double value) {
        double minimumError = 1e9;
        int bestNumerator = 0;
        int bestDenominator = 1;

        for (int d = 1; d <= 1000; d++) {
            int n = static_cast<int>(round(value * d));
            double error = abs(value - static_cast<double>(n) / d);

            if (error < minimumError) {
                minimumError = error;
                bestNumerator = n;
                bestDenominator = d;
            }
        }

        numerator = bestNumerator;
        denominator = bestDenominator;
        reduce();
    }

    operator double() const {
        return static_cast<double>(numerator) / denominator;
    }

    friend Fraction operator+(const Fraction& a, const Fraction& b);
    friend Fraction operator-(const Fraction& a, const Fraction& b);
    friend Fraction operator*(const Fraction& a, const Fraction& b);
    friend Fraction operator/(const Fraction& a, const Fraction& b);

    friend bool operator<(const Fraction& a, const Fraction& b);
    friend bool operator>(const Fraction& a, const Fraction& b);
    friend bool operator==(const Fraction& a, const Fraction& b);

    friend istream& operator>>(istream& input, Fraction& f);
    friend ostream& operator<<(ostream& output, const Fraction& f);
};

Fraction operator+(const Fraction& a, const Fraction& b) {
    return Fraction(
        a.numerator * b.denominator + b.numerator * a.denominator,
        a.denominator * b.denominator
    );
}

Fraction operator-(const Fraction& a, const Fraction& b) {
    return Fraction(
        a.numerator * b.denominator - b.numerator * a.denominator,
        a.denominator * b.denominator
    );
}

Fraction operator*(const Fraction& a, const Fraction& b) {
    return Fraction(
        a.numerator * b.numerator,
        a.denominator * b.denominator
    );
}

Fraction operator/(const Fraction& a, const Fraction& b) {
    if (b.numerator == 0)
        throw invalid_argument("Division by zero fraction is not allowed.");

    return Fraction(
        a.numerator * b.denominator,
        a.denominator * b.numerator
    );
}

bool operator<(const Fraction& a, const Fraction& b) {
    return a.numerator * b.denominator <
           b.numerator * a.denominator;
}

bool operator>(const Fraction& a, const Fraction& b) {
    return a.numerator * b.denominator >
           b.numerator * a.denominator;
}

bool operator==(const Fraction& a, const Fraction& b) {
    return a.numerator == b.numerator &&
           a.denominator == b.denominator;
}

istream& operator>>(istream& input, Fraction& f) {
    int numerator, denominator;
    char slash;

    input >> numerator >> slash >> denominator;

    if (slash != '/' || denominator == 0) {
        input.setstate(ios::failbit);
        return input;
    }

    f = Fraction(numerator, denominator);
    return input;
}

ostream& operator<<(ostream& output, const Fraction& f) {
    output << f.numerator << "/" << f.denominator;
    return output;
}

int main() {
    try {
        Fraction f1, f2;

        cout << "Enter first fraction in a/b form: ";
        cin >> f1;

        cout << "Enter second fraction in a/b form: ";
        cin >> f2;

        if (!cin) {
            cout << "Invalid fraction input." << endl;
            return 1;
        }

        cout << "\nFirst Fraction: " << f1 << endl;
        cout << "Second Fraction: " << f2 << endl;

        cout << "Addition: " << f1 + f2 << endl;
        cout << "Subtraction: " << f1 - f2 << endl;
        cout << "Multiplication: " << f1 * f2 << endl;
        cout << "Division: " << f1 / f2 << endl;

        cout << "\nDecimal Value of First Fraction: "
             << static_cast<double>(f1) << endl;

        if (f1 < f2)
            cout << f1 << " is smaller than " << f2 << endl;
        else if (f1 > f2)
            cout << f1 << " is greater than " << f2 << endl;
        else
            cout << "Both fractions are equal." << endl;

        double decimalValue;
        cout << "\nEnter a decimal value: ";
        cin >> decimalValue;

        Fraction converted(decimalValue);

        cout << "Fraction Approximation: " << converted << endl;
    }
    catch (const exception& error) {
        cout << "Error: " << error.what() << endl;
    }

    return 0;
}