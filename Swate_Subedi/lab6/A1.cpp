#include <iostream>
#include <string>

using namespace std;

class Shape
{
private:
    string color;

public:
    Shape(string c) : color(c) {}

    string getColor() const { return color; }
    virtual float area() const = 0;
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(string c, float r) : Shape(c), radius(r) {}

    float area() const override
    {
        return 3.1416 * radius * radius;
    }

    void display() const
    {
        cout << "Circle Color: " << getColor() << ", Area: " << area() << endl;
    }
};

class Rectangle : public Shape
{
private:
    float w, h;

public:
    Rectangle(string c, float width, float height) : Shape(c), w(width), h(height) {}

    float area() const override
    {
        return w * h;
    }

    void display() const
    {
        cout << "Rectangle Color: " << getColor() << ", Area: " << area() << endl;
    }
};

class Triangle : public Shape
{
private:
    float b, h;

public:
    Triangle(string c, float base, float height) : Shape(c), b(base), h(height) {}

    float area() const override
    {
        return 0.5 * b * h;
    }

    void display() const
    {
        cout << "Triangle Color: " << getColor() << ", Area: " << area() << endl;
    }
};

int main()
{
    Circle c("Red", 5);
    Rectangle r("Blue", 4, 6);
    Triangle t("Green", 3, 7);

    c.display();
    r.display();
    t.display();

    return 0;
}