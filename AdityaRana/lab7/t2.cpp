#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
    
    void display() {
        cout << "Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}
    float area() override { return 3.14159f * radius * radius; }
    float perimeter() override { return 2.0f * 3.14159f * radius; }
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    float area() override { return length * width; }
    float perimeter() override { return 2.0f * (length + width); }
};

class Triangle : public Shape {
private:
    float a, b, c;
public:
    Triangle(float side1, float side2, float side3) : a(side1), b(side2), c(side3) {}
    float area() override {
        float s = (a + b + c) / 2.0f;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    float perimeter() override { return a + b + c; }
};

int main() {
    Circle circle(5.0f);
    Rectangle rect(4.0f, 6.0f);
    Triangle tri(3.0f, 4.0f, 5.0f);

    Shape* ptr;

    ptr = &circle;
    ptr->display();

    ptr = &rect;
    ptr->display();

    ptr = &tri;
    ptr->display();

    return 0;
}