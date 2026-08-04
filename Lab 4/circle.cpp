#include<iostream>
using namespace std;

class Circle
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    void setRadius(float r)
    {
        radius = r;
    }

    float getArea() const
    {
        return 3.14 * radius * radius;
    }

    float getCircumference() const
    {
        return 2 * 3.14 * radius;
    }

    void display() const
    {
        cout<<"Radius = "<<radius<<endl;
    }
};

int main()
{
    Circle c1(5);
    const Circle c2(10);

    c1.display();
    c1.setRadius(8);

    cout<<"Area = "<<c2.getArea()<<endl;
    cout<<"Circumference = "<<c2.getCircumference()<<endl;

   
    return 0;
}