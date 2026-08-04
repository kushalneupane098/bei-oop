#include <iostream>
using namespace std;

class Box {
private:
    float l, b, h;

public:
    Box() {
        l = b = h = 0;
        cout << "Default constructor\n";
    }

    Box(float len, float bre, float hei) {
        l = len;
        b = bre;
        h = hei;
        cout << "Parameterized constructor\n";
    }

    Box(float len, float bre = 1.0) {
        l = len;
        b = bre;
        h = 1.0;
        cout << "Default argument constructor\n";
    }

    Box(const Box &other) {
        l = other.l;
        b = other.b;
        h = other.h;
        cout << "Copy constructor\n";
    }

    ~Box() {
        cout << "Destructor called\n";
    }
};

int main() {
    cout << "b1\n";
    Box b1;

    cout << "b2\n";
    Box b2(5.5, 4.2, 3.0);

    cout << "b3\n";
    Box b3(7.5);

    cout << "b4\n";
    Box b4(b2);

    cout << "end\n";
    return 0;
}