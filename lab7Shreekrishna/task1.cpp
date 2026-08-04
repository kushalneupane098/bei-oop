#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Dog d;
    Cat c;

    Animal* ptr;

    ptr = &d;
    ptr->speak();

    ptr = &c;
    ptr->speak();

    return 0;
}