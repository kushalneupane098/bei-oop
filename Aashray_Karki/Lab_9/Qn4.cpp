/*
Question 4:
Demonstrate re-throwing of exceptions. compute() catches divide-by-zero locally,
prints a message, and re-throws it to main.
*/

#include <iostream>
using namespace std;

float compute(int a, int b) {
    try {
        if (b == 0)
            throw "Divide by zero exception";

        return static_cast<float>(a) / b;
    }
    catch (const char *msg) {
        cout << "Exception caught inside compute(): " << msg << endl;
        throw;
    }
}

int main() {
    int a, b;

    cout << "Enter numerator: ";
    cin >> a;

    cout << "Enter denominator: ";
    cin >> b;

    try {
        cout << "Result: " << compute(a, b) << endl;
    }
    catch (const char *msg) {
        cout << "Exception caught again in main(): " << msg << endl;
    }

    return 0;
}