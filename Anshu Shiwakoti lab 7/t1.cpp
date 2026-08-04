#include <iostream>
using namespace std;
class Animal1
{
public:
    void speak()
    {
        cout << "Animal speaks" << endl;
    }
};

class Dog1 : public Animal1
{
public:
    void speak()
    {
        cout << "Dog barks" << endl;
    }
};

class Cat1 : public Animal1
{
public:
    void speak()
    {
        cout << "Cat meows" << endl;
    }
};

class Animal2
{
public:
    virtual void speak()
    {
        cout << "Animal speaks" << endl;
    }
};

class Dog2 : public Animal2
{
public:
    void speak()
    {
        cout << "Dog barks" << endl;
    }
};

class Cat2 : public Animal2
{
public:
    void speak()
    {
        cout << "Cat meows" << endl;
    }
};

int main()
{
    cout << "Without Virtual Function:" << endl;
    Animal1 *ptr1;
    Dog1 d1;
    Cat1 c1;
    ptr1 = &d1;
    ptr1->speak();
    ptr1 = &c1;
    ptr1->speak();
    cout << "\nWith Virtual Function:" << endl;
    Animal2 *ptr2;
    Dog2 d2;
    Cat2 c2;
    ptr2 = &d2;
    ptr2->speak();
    ptr2 = &c2;
    ptr2->speak();
    return 0;
}