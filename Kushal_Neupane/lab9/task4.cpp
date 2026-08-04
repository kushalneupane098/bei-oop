#include <iostream>
#include <stdexcept>
using namespace std;

void compute(int a, int b) {
    try {
        if (b == 0) throw runtime_error("Divide by zero!");
        cout << "Result: " << a / b << endl;
    }
    catch (runtime_error &e) {
        cout << "compute() caught exception: " << e.what() << endl;
        throw; // re-throw to caller
    }
}

int main() {
    try {
                compute(10, 0);
            }
            catch (runtime_error &e) {
                cout << "main() caught re-thrown exception: " << e.what() << endl;
            }
    return 0;
}
