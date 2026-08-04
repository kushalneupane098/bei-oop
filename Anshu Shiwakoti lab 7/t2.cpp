#include<iostream>
#include<cmath>
using namespace std;
const float PI=3.14;
class Shape{
    public:
    virtual float area(){

    }
    virtual float perimeter(){

    }
    void display(){
        cout<<"Area is:"<<area()<<endl;
        cout<<"perimeter is"<<perimeter()<<endl;
    }
};
class Circle: public Shape{
    private:
    float r;
    public:
    Circle(float radius){
r=radius;
    }
    float area(){
        return PI*r*r;
    }
    float perimeter(){
        return 2*PI*r;
    }
};
class Rectangle:public Shape{
private:
float l,b;
public:
Rectangle(float len, float bre){
l=len;
b=bre;
    }
    float area(){
        return l*b;
    }
    float perimeter(){
        return 2*(l+b);
    }
};
class Triangle : public Shape
{
private:
    float a, b, c;

public:
    Triangle(float x, float y, float z)
    {
        a = x;
        b = y;
        c = z;
    }

    float perimeter()
    {
        return a + b + c;
    }

    float area()
    {
        float s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c)); 
    }
};

int main(){
    Shape *ptr;
    Circle c(7);
    Rectangle r(8, 5);
    Triangle t(3, 4, 5);
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
