#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;

    virtual void display() {
        cout << "Area = " << area() << endl;
        cout << "Perimeter = " << perimeter() << endl;
    }
};

class Circle : public Shape {
    float r;

public:
    Circle(float r) {
        this->r = r;
    }

    float area() {
        return 3.1416 * r * r;
    }

    float perimeter() {
        return 2 * 3.1416 * r;
    }
};

class Rectangle : public Shape {
    float l, w;

public:
    Rectangle(float l, float w) {
        this->l = l;
        this->w = w;
    }

    float area() {
        return l * w;
    }

    float perimeter() {
        return 2 * (l + w);
    }
};

class Triangle : public Shape {
    float a, b, c;

public:
    Triangle(float a, float b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    float perimeter() {
        return a + b + c;
    }

    float area() {
        float s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 4, 5);

    Shape* ptr;

    ptr = &c;
    ptr->display();

    cout << endl;

    ptr = &r;
    ptr->display();

    cout << endl;

    ptr = &t;
    ptr->display();

    return 0;
}