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
    void speak() override {
        cout << "Woof" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow" << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;
    Animal* ptr;

    ptr = &dog;
    ptr->speak();

    ptr = &cat;
    ptr->speak();

    return 0;
}