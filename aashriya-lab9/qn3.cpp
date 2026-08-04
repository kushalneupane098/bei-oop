#include <iostream>
using namespace std;

class DivideByZeroException {
public:
    const char* message() {
        return "Division by zero is not allowed.";
    }
};

class NegativeDenominatorException {
public:
    const char* message() {
        return "Denominator cannot be negative.";
    }
};

int main() {
    double num, den;

    cout << "Enter numerator: ";
    cin >> num;

    cout << "Enter denominator: ";
    cin >> den;

    try {
        if (den == 0)
            throw DivideByZeroException();

        if (den < 0)
            throw NegativeDenominatorException();

        cout << "Result = "
             << num / den << endl;
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