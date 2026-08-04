#include <iostream>
#include <string>
using namespace std;

class Shape {
private:
    string color;

public:
    Shape(string c) : color(c) {}

    string getColor() { return color; }

    virtual float area() = 0;

    virtual void display() {
        cout << "Color: " << color << ", Area: " << area() << endl;
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(string c, float r) : Shape(c), radius(r) {}

    float area() override {
        return 3.14159f * radius * radius;
    }

    void display() override {
        cout << "Circle - Color: " << getColor()
             << ", Area: " << area() << endl;
    }
};

class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(string c, float l, float w) : Shape(c), length(l), width(w) {}

    float area() override {
        return length * width;
    }

    void display() override {
        cout << "Rectangle - Color: " << getColor()
             << ", Area: " << area() << endl;
    }
};

class Triangle : public Shape {
private:
    float base, height;

public:
    Triangle(string c, float b, float h) : Shape(c), base(b), height(h) {}

    float area() override {
        return 0.5f * base * height;
    }

    void display() override {
        cout << "Triangle - Color: " << getColor()
             << ", Area: " << area() << endl;
    }
};

int main() {
    Circle circ("Red", 5.0f);
    Rectangle rect("Blue", 4.0f, 6.0f);
    Triangle tri("Green", 3.0f, 8.0f);

    circ.display();
    rect.display();
    tri.display();

    return 0;
}
