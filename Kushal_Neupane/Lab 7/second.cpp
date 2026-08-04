#include <iostream>
#include <cmath>
using namespace std;
class Shape{
    public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
    virtual void display(){}
    

};
class Rectangle: public Shape{
    int length;
    int breadth;
    public:
    Rectangle(){}
    Rectangle(int l, int b):length(l),breadth(b){}
    float area(){
        return length*breadth;
    }
    float perimeter(){
        return 2*(length + breadth);
    }
    void display(){
        cout<<"The area of rectangle is "<<area()<<endl;
        cout<<"Thte perimeter of rectangle is "<<perimeter()<<endl;
    }
};
class Circle: public Shape{
    int radius;
    public:
    Circle(){}
    Circle(int r):radius(r){}
    float area(){
        return 3.14 * radius *radius;
    }
    float perimeter(){
        return 2*3.14*radius;
    }
     void display(){
        cout<<"The area of circle is "<<area()<<endl;
        cout<<"Thte perimeter of circle is "<<perimeter()<<endl;
    }
};
class Triangle:public Shape{
    int length1;
    int length2;
    int length3;
    public:
    Triangle(){}
    Triangle(int a, int b, int c):length1(a), length2(b), length3(c){}
    int Perimeter = (length1 + length2 + length3);
    float area(){
        return(sqrt(Perimeter*(Perimeter-length1)*(Perimeter -length2)*(Perimeter - length3)));
    }
    float perimeter(){
        return Perimeter;
    }
     void display(){
        cout<<"The area of triangle is "<<area()<<endl;
        cout<<"Thte perimeter of triangle is "<<perimeter()<<endl;
    }

};
int main(){
    Shape *s;
    Rectangle r(2,3);
    Circle c(4);
    Triangle t(2,4,5);
    s = &r;
    s->display();
    s = &c;
    s->display();
    s = &t;
    s->display();
}