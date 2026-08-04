#include <iostream>
using namespace std;

class Box {
private:
    float l, b, h;

public:
    Box() {
        l = b = h = 0;
        cout << "Default constructor called\n";
    }
    Box(float length, float breadth, float height) {
        l = length;
        b = breadth;
        h = height;
        cout << "Parameterized constructor called\n";
    }
    Box(const Box &B) {
        l = B.l;
        b = B.b;
        h = B.h;
        cout << "Copy constructor called\n";
    }
    void display() {
        cout << "Length: " << l
             << ", Breadth: " << b
             << ", Height: " << h << endl;
    }
    ~Box() {
        cout << "Destructor called\n";
    }
};

int main() {
    Box box1;
    box1.display();

    Box box2(2.5, 3.5, 4.5);
    box2.display();


    Box box3(5.0, 6.0, 7.0);
    box3.display();

 
    Box box4 = box2;
    box4.display();

    return 0;
}