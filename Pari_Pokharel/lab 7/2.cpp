#include <iostream>
using namespace std;

class Shape
{
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;

    virtual void display()
    {
        cout << "Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }
    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r) : radius(r) {}
    float area() override { return 3.14159f * radius * radius; }
    float perimeter() override { return 2 * 3.14159f * radius; }
};

class Rectangle : public Shape
{
private:
    float length, width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}
    float area() override { return length * width; }
    float perimeter() override { return 2 * (length + width); }
};

class Triangle : public Shape
{
private:
    float base, height, side1, side2;

public:
    Triangle(float b, float h, float s1, float s2) : base(b), height(h), side1(s1), side2(s2) {}
    float area() override { return 0.5f * base * height; }
    float perimeter() override { return base + side1 + side2; }
};

int main()
{
    Circle circle(5.0f);
    Rectangle rect(4.0f, 6.0f);
    Triangle tri(3.0f, 4.0f, 4.0f, 5.0f);

    Shape *shapePtr = nullptr;

    cout << "Circle Details -> ";
    shapePtr = &circle;
    shapePtr->display();

    cout << "Rectangle Details -> ";
    shapePtr = &rect;
    shapePtr->display();

    cout << "Triangle Details -> ";
    shapePtr = &tri;
    shapePtr->display();

    return 0;
}