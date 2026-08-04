#include <iostream>
using namespace std;

template <typename T>
T max3(T a, T b, T c) {
    if (a >= b && a >= c) return a;
    else if (b >= a && b >= c) return b;
    else return c;
}

int main() {
    cout << "Max of ints (10, 25, 15): " << max3(10, 25, 15) << endl;
    cout << "Max of floats (3.5, 7.2, 5.8): " << max3(3.5f, 7.2f, 5.8f) << endl;
    cout << "Max of chars ('a','z','m'): " << max3('a', 'z', 'm') << endl;
    return 0;
}
