#include <iostream>
using namespace std;
class Animal{
    public:
    virtual void speaks(){
        cout<<"Animal speaks"<<endl;
    }
};
class Dog:public Animal{
    public:
    void speaks(){
        cout<<"Woof"<<endl;
    }
};
class Cat:public Animal{
    public:
    void speaks(){
        cout<<"Meow"<<endl;
    }
};
int main(){
    Animal *ptr;
    Dog d;
    Cat c;
    ptr = &d;
    ptr->speaks();
    ptr = &c;
    ptr->speaks();
}
/* Output without virtual function
Animal speaks
Animal speaks*/
/* Output with virtual function
Woof
Meow*/