/*
Question 2:
Create abstract class Shape with pure virtual area() and perimeter().
Create Circle, Rectangle, and Triangle. Use Shape pointer to call display().
*/

#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual float area() const = 0;
    virtual float perimeter() const = 0;

    virtual void display() const {
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float area() const override {
        return 3.1416f * radius * radius;
    }

    float perimeter() const override {
        return 2 * 3.1416f * radius;
    }
};

class Rectangle : public Shape {
private:
    float length, breadth;

public:
    Rectangle(float l, float b) {
        length = l;
        breadth = b;
    }

    float area() const override {
        return length * breadth;
    }

    float perimeter() const override {
        return 2 * (length + breadth);
    }
};

class Triangle : public Shape {
private:
    float a, b, c;

public:
    Triangle(float x, float y, float z) {
        a = x;
        b = y;
        c = z;
    }

    float area() const override {
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    float perimeter() const override {
        return a + b + c;
    }
};

int main() {
    // Shape s; // Not allowed because Shape is an abstract class.

    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 4, 5);

    Shape *ptr;

    cout << "Circle:" << endl;
    ptr = &c;
    ptr->display();

    cout << "\nRectangle:" << endl;
    ptr = &r;
    ptr->display();

    cout << "\nTriangle:" << endl;
    ptr = &t;
    ptr->display();

    return 0;
}