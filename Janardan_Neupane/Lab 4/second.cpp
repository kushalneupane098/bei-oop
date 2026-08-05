#include <iostream>
using namespace std;
class Circle{
    double radius;

    public:
Circle(){}
Circle(double r):radius(r){}
double  getarea(double rad)const {
    return 3.14 * rad*rad; 
}
double  getcircumference(double rad)const{
    return 2*3.14*rad;
}
void  display(double rad)const {
    cout<<"Area: "<<getarea(rad)<<endl;
    cout<<"Circumference: "<<getcircumference(rad)<<endl;
}
void setradius(double rad){
    rad = radius;
}
};
int main(){
    double rad;
    cout<<"Enter the value of radius: ";
    cin>>rad;
    Circle c(rad);
    c.display(rad);
    cout<<"Now taking const"<<endl;
    const Circle c1;
    c1.display(rad);
    return 0;
}

// const object is called only for the constant function so if we tried to call it to the function which is not const, then there will be error due to it.