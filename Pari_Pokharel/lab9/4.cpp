#include <iostream>

using namespace std;

void compute(int a, int b) {
    try {
        if (b == 0) {
            throw "DivisionByZero";
        }
        cout << "Result: " << (a / b) << endl;
    }
    catch (const char* err) {
        cout << "compute() caught: " << err << ". Re-throwing..." << endl;
        throw;
    }
}

int main() {
    try {
        compute(10, 2);
        compute(10, 0);
    }
    catch (const char* err) {
        cout << "main() caught: " << err << endl;
    }

    return 0;
}