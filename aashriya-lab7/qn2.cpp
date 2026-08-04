#include <iostream>
#include <cmath>
using namespace std;
class Shape{ 
    public:
    virtual float area()=0;
    virtual float perimeter()=0;
    void display() {
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};
class Circle: public Shape{
    private:
    float radius;
    public:
    Circle(float r) {
        radius = r;
    }   
    float area() {
        return 3.14 * radius * radius;
    }
    float perimeter() {
        return 2 * 3.14 * radius;
    }
    void display() {
        cout << "Circle: " << endl;
        Shape::display();
    }

};
class Rectangle: public Shape{
    private:
    float length;
    float width;
    public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }
    float area() {
        return length * width;
    }
    float perimeter() {
        return 2 * (length + width);
    }
    void display() {
        cout << "Rectangle: " << endl;
        Shape::display();
    }
};
class Triangle: public Shape{
    private:
    float base;
    float height;
    public:
    Triangle(float b, float h) {
        base = b;
        height = h;
    }
    float area() {
        return 0.5 * base * height;
    }
    float perimeter() {
        return base + height + sqrt(base * base + height * height);
    }
    void display() {
        cout << "Triangle: " << endl;
        Shape::display();
    }
};
int main() {
    Shape *ptr;
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 4);
    ptr = &c;
    ptr->display();
    ptr = &r;
    ptr->display();
    ptr = &t;
    ptr->display();
    return 0;
}