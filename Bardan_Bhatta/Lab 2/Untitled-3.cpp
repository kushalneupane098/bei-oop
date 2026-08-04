#include <iostream>
#include <typeinfo>

using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Vau vau" << endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "kukruku" << endl;
    }
    void bark() {
        cout << "bhau bhau!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Me aau" << endl;
    }
};

int main() {
    Animal* animalPtr = new Dog();

    Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);

    if (dogPtr != nullptr) {
        dogPtr->bark(); 
    } else {
        cout << "failed!" << endl;
    }

    delete animalPtr;
    return 0;
}