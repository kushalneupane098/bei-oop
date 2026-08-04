#include <iostream>
using namespace std;

void compute(int a, int b) {
    try {
        if (b == 0)
            throw b;

        cout << "Result = "
             << a / b << endl;
    }

    catch (int) {
        cout << "compute(): Divide-by-zero exception caught.\n";

        throw;     
    }
}

int main() {
    try {
        compute(10, 0);
    }

    catch (int) {
        cout << "main(): Re-thrown exception handled.\n";
    }

    return 0;
}