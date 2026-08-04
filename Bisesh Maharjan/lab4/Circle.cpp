#include<iostream>
using namespace std;
class Circle {
    private:
        float rad;
    public:
        Circle(float r=0) {
            rad = r;
        }
        void setRad(float x) {
            rad = x;
        }
        float area() const {
            return 3.1416 * rad * rad;
        }
        float circum() const {
            return 2 * 3.1416 * rad;
        }
        void show() const {
            cout<<"Radius:"<<rad<<endl;
            cout<<"Area:"<<area()<<endl;
            cout<<"Circumference:"<<circum()<<endl;
        }
};
int main() {
    Circle c1(5);
    const Circle c2(3);
    cout <<"Normal Circle"<<endl;
    c1.show();
    c1.setRad(7);
    cout <<"\nAfter changing radius:"<<endl;
    c1.show();
    cout <<"\nConst Circle"<< endl;
    c2.show();
    cout<<"Area:"<<c2.area()<<endl;
    cout<<"Circumference:"<<c2.circum()<<endl;
    return 0;
}
