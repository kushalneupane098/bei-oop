#include <iostream>
using namespace std;
int main() {
    float length, width;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;

    float perimeter = 2 * (length + width);
    cout << "Perimeter = " << perimeter << endl;
    return 0;
}