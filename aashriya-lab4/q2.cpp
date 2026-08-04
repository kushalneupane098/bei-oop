#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    // Constructor
    Circle(double r = 0) {
        radius = r;
    }

    // Non-const member function
    void setRadius(double r) {
        radius = r;
    }

    // Const member functions
    double getArea() const {
        return 3.14159 * radius * radius;
    }

    double getCircumference() const {
        return 2 * 3.14159 * radius;
    }

    void display() const {
        cout << "Radius: " << radius << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Circumference: " << getCircumference() << endl;
    }
};

int main() {
    // Normal object
    Circle c1(5);

    // Const object
    const Circle c2(10);

    cout << "Normal Circle Object:\n";
    c1.display();
    c1.setRadius(7);   // Allowed: non-const object can call non-const function
    c1.display();

    cout << "\nConst Circle Object:\n";
    c2.display();             // Allowed
    cout << "Area = " << c2.getArea() << endl; // Allowed
    cout << "Circumference = " << c2.getCircumference() << endl; // Allowed

    // c2.setRadius(15);  // ERROR!
      // ERROR!
    // Not allowed because c2 is a const object.
    // A const object can only call const member functions.
    // setRadius() is non-const because it modifies the object's state.

    return 0;
}