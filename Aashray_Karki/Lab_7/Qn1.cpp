/*
Question 1:
Demonstrate the need for virtual functions using Animal, Dog, and Cat.
First show non-virtual behavior, then virtual behavior.
*/

#include <iostream>
using namespace std;

class Animal1 {
public:
    void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog1 : public Animal1 {
public:
    void speak() {
        cout << "Dog barks" << endl;
    }
};

class Cat1 : public Animal1 {
public:
    void speak() {
        cout << "Cat meows" << endl;
    }
};

class Animal2 {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog2 : public Animal2 {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

class Cat2 : public Animal2 {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    /*
    Output without virtual:
    Animal speaks
    Animal speaks

    Output with virtual:
    Dog barks
    Cat meows
    */

    Dog1 d1;
    Cat1 c1;
    Animal1 *p1;

    cout << "Without virtual:" << endl;
    p1 = &d1;
    p1->speak();

    p1 = &c1;
    p1->speak();

    Dog2 d2;
    Cat2 c2;
    Animal2 *p2;

    cout << "\nWith virtual:" << endl;
    p2 = &d2;
    p2->speak();

    p2 = &c2;
    p2->speak();

    /*
    Explanation:
    Without virtual, function call depends on pointer type.
    With virtual, function call depends on actual object type at runtime.
    */

    return 0;
}