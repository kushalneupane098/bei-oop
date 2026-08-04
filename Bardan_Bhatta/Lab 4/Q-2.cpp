#include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    void setRadius(float r) {
        radius = r;
    }

    float getArea() const {
        return 3.14159 * radius * radius;
    }

    float getCircumference() const {
        return 2 * 3.14159 * radius;
    }

    void display() const {
        cout << "Radius: " << radius << ", Area: " << getArea() 
             << ", Circumference: " << getCircumference() << endl;
    }
};

int main() {
    Circle normalCircle(5.0);
    cout << "Normal Object Operations" << endl;
    normalCircle.setRadius(7.0); 
    normalCircle.display();      

    const Circle constCircle(4.0);
    cout << "\nConstant Object Operations" << endl;
    cout << "Area of Const Circle: " << constCircle.getArea() << endl;
    cout << "Circumference of Const Circle: " << constCircle.getCircumference() << endl;
    constCircle.display();

    return 0;
}