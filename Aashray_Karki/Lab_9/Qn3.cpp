/*
Question 3:
Demonstrate exception handling with multiple catch blocks.
Handle division by zero, negative denominator, and unexpected exceptions.
*/

#include <iostream>
using namespace std;

class DivideByZeroException {
public:
    string message() const {
        return "Error: Division by zero is not allowed.";
    }
};

class NegativeDenominatorException {
public:
    string message() const {
        return "Error: Negative denominator is not allowed.";
    }
};

float divide(float a, float b) {
    if (b == 0)
        throw DivideByZeroException();

    if (b < 0)
        throw NegativeDenominatorException();

    return a / b;
}

int main() {
    float a, b;

    cout << "Enter numerator: ";
    cin >> a;

    cout << "Enter denominator: ";
    cin >> b;

    try {
        cout << "Result: " << divide(a, b) << endl;
    }
    catch (DivideByZeroException e) {
        cout << e.message() << endl;
    }
    catch (NegativeDenominatorException e) {
        cout << e.message() << endl;
    }
    catch (...) {
        cout << "Unexpected exception occurred." << endl;
    }

    return 0;
}