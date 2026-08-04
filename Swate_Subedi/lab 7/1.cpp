#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak() override
    {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak() override
    {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    Dog myDog;
    Cat myCat;
    Animal *animalPtr;

    cout << "--- Calling via Base Pointer ---" << endl;
    animalPtr = &myDog;
    animalPtr->speak();

    animalPtr = &myCat;
    animalPtr->speak();

    return 0;
}