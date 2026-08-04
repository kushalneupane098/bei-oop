#include <iostream>
using namespace std;

class Box {
private:
    float l, b, h;

public:
    Box() {
        l = 0; b = 0; h = 0;
        cout << "Default constructor called." << endl;
    }

    Box(float length, float breadth, float height) {
        l = length;
        b = breadth;
        h = height;
        cout << "Parameterised constructor called." << endl;
    }

    Box(float side) {
        l = b = h = side;
        cout << "Constructor with default arguments (Cube) called." << endl;
    }

    Box(const Box &obj) {
        l = obj.l;
        b = obj.b;
        h = obj.h;
        cout << "Copy constructor called." << endl;
    }

    ~Box() {
        cout << "Destructor called: Object destroyed." << endl;
    }

    void display() {
        cout << "Dimensions: " << l << " x " << b << " x " << h << endl;
    }
};

int main() {
    cout << " Creating b1 " << endl;
    Box b1;
    
    cout << "\n Creating b2 " << endl;
    Box b2(5.5, 4.2, 3.0);
    
    cout << "\n Creating b3 " << endl;
    Box b3(4.0);
    
    cout << "\n Creating b4 " << endl;
    Box b4 = b2;

    cout << "\n Program Termination " << endl;
    return 0;
}