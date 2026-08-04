/*
Assignment 1:
Write a program demonstrating hierarchical inheritance. Create a base class Shape
having private member color and a pure virtual function area() returning float.
Derive three classes Circle, Rectangle, and Triangle from Shape, each adding the
necessary private dimension members. Each derived class must implement area()
using the correct formula and have a parameterized constructor that passes color
to the base class constructor. Write a display() function in each derived class
that prints the color and computed area. In main, create one object of each
derived class and call display().
*/

#include <iostream>
using namespace std;

class Shape {
private:
    string color;

public:
    Shape(string c) {
        color = c;
    }

    string getColor() {
        return color;
    }

    virtual float area() = 0;
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(string c, float r) : Shape(c) {
        radius = r;
    }

    float area() {
        return 3.1416 * radius * radius;
    }

    void display() {
        cout << "Circle Color: " << getColor() << endl;
        cout << "Circle Area: " << area() << endl;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float breadth;

public:
    Rectangle(string c, float l, float b) : Shape(c) {
        length = l;
        breadth = b;
    }

    float area() {
        return length * breadth;
    }

    void display() {
        cout << "Rectangle Color: " << getColor() << endl;
        cout << "Rectangle Area: " << area() << endl;
    }
};

class Triangle : public Shape {
private:
    float base;
    float height;

public:
    Triangle(string c, float b, float h) : Shape(c) {
        base = b;
        height = h;
    }

    float area() {
        return 0.5 * base * height;
    }

    void display() {
        cout << "Triangle Color: " << getColor() << endl;
        cout << "Triangle Area: " << area() << endl;
    }
};

int main() {
    Circle c1("Red", 5);
    Rectangle r1("Blue", 4, 6);
    Triangle t1("Green", 5, 8);

    c1.display();
    cout << endl;

    r1.display();
    cout << endl;

    t1.display();

    return 0;
}