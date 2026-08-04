#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
T max3(T a, T b, T c)
{
    return max({a, b, c});
}

int main()
{
    int i1 = 15, i2 = 42, i3 = 23;
    cout << "Max int: " << max3(i1, i2, i3) << endl;

    float f1 = 3.14f, f2 = 2.71f, f3 = 3.61f;
    cout << "Max float: " << max3(f1, f2, f3) << endl;

    char c1 = 'a', c2 = 'z', c3 = 'm';
    cout << "Max char: " << max3(c1, c2, c3) << endl;

    return 0;
}