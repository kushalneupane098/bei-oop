#include <iostream>
#include <string>
using namespace std;

class Shape {
private:
    string color;

public:
    Shape(string color) : color(color) {}

    string getColor() const { return color; }

    virtual float area() const = 0;
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(string color, float radius) : Shape(color), radius(radius) {}

    float area() const override {
        return 3.14159f * radius * radius;
    }

    void display() const {
        cout << "Color  : " << getColor() << endl;
        cout << "Radius : " << radius << endl;
        cout << "Area   : " << area() << endl;
    }
};

class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(string color, float length, float width) : Shape(color), length(length), width(width) {}

    float area() const override {
        return length * width;
    }

    void display() const {
        cout << "Color  : " << getColor() << endl;
        cout << "Length : " << length << endl;
        cout << "Width  : " << width << endl;
        cout << "Area   : " << area() << endl;
    }
};

class Triangle : public Shape {
private:
    float base, height;

public:
    Triangle(string color, float base, float height) : Shape(color), base(base), height(height) {}

    float area() const override {
        return 0.5f * base * height;
    }

    void display() const {
        cout << "Color  : " << getColor() << endl;
        cout << "Base   : " << base << endl;
        cout << "Height : " << height << endl;
        cout << "Area   : " << area() << endl;
    }
};

int main() {
    Circle c("Red", 5.0f);
    Rectangle r("Blue", 4.0f, 6.0f);
    Triangle t("Green", 3.0f, 8.0f);

    cout << "--- Circle ---" << endl;
    c.display();

    cout << "\n--- Rectangle ---" << endl;
    r.display();

    cout << "\n--- Triangle ---" << endl;
    t.display();

    return 0;
}
