#include <iostream>
using namespace std;

class Shape
{
protected:
    string color;

public:
    Shape(string c)
    {
        color = c;
    }

    virtual float area() = 0;
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(string c, float r)
        : Shape(c)
    {
        radius = r;
    }

    float area()
    {
        return 3.1416 * radius * radius;
    }

    void display()
    {
        cout << "Circle Color: " << color
             << ", Area: " << area() << endl;
    }
};

class Rectangle : public Shape
{
private:
    float length, breadth;

public:
    Rectangle(string c, float l, float b)
        : Shape(c)
    {
        length = l;
        breadth = b;
    }

    float area()
    {
        return length * breadth;
    }

    void display()
    {
        cout << "Rectangle Color: " << color
             << ", Area: " << area() << endl;
    }
};

class Triangle : public Shape
{
private:
    float base, height;

public:
    Triangle(string c, float b, float h)
        : Shape(c)
    {
        base = b;
        height = h;
    }

    float area()
    {
        return 0.5 * base * height;
    }

    void display()
    {
        cout << "Triangle Color: " << color
             << ", Area: " << area() << endl;
    }
};

int main()
{
    Circle c("Rad", 5);
    Rectangle r("Blue", 4, 6);
    Triangle t("Green", 8, 4);

    c.display();
    r.display();
    t.display();

    return 0;
}