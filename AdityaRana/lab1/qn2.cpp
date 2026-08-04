#include <iostream>
using namespace std;

float area(float l, float w) {
    return l * w;
}

float perimeter(float l, float w) {
    return 2 * (l + w);
}
int main() {
    float length, width;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;

    cout << "Area = " << area(length, width) << endl;
    cout << "Perimeter = " << perimeter(length, width) << endl;
    return 0;
}