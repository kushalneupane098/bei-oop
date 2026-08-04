/*
Question 1:
Write a program using function template to find the maximum of three numbers.
The template function max3() should accept three arguments of any type and return
the largest. Demonstrate with int, float, and char data types.
*/

#include <iostream>
using namespace std;

template <class T>
T max3(T a, T b, T c) {
    T largest = a;

    if (b > largest)
        largest = b;

    if (c > largest)
        largest = c;

    return largest;
}

int main() {
    cout << "Maximum integer: " << max3(10, 25, 15) << endl;
    cout << "Maximum float: " << max3(5.5f, 2.3f, 9.8f) << endl;
    cout << "Maximum character: " << max3('A', 'Z', 'M') << endl;

    return 0;
}