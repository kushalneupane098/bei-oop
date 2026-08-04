#include<iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    Circle(float r) {       
        radius = r;
    }

    float getArea() const { 
        return 3.14f * radius * radius;
    }

    float getCircum() const { 
        return 2 * 3.14f * radius;
    }

    void display() const {
        cout << "Radius: " << radius << endl;
        cout << "Area of the Circle: " << getArea() << endl;        
        cout << "Circumference: "      << getCircum() << endl;      
    }

    void setRadius(float r) {
        radius = r;
    }
};

int main() {
    Circle c1(5.0f);        
    const Circle c2(7.0f); 
    c1.setRadius(10.0f);
    c1.display();

    
    c2.display();
   
}