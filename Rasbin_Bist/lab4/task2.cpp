#include<iostream>
using namespace std;
class circle{
    int radius;
public:
circle(int r=0){
    radius=r;
}
void area() const{
    cout<< "AREA "<<3.14*radius*radius<<"\n";
}
void circumference() const{
    cout<< "Circumference "<<3.14*radius*2<<"\n";
}
void display() const{
        area();
        circumference();
}
void setRadius(){
    radius=4;
}
};

int main(){

    circle c1(3);
    const circle c2(5);
    c1.setRadius();
    c1.display();
    c2.display();

    return 0;

}
