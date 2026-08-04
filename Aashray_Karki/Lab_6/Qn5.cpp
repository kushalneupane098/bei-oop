/*
Assignment 2:
Write a program demonstrating multilevel inheritance with constructor and destructor
ordering. Create a base class A with a parameterized constructor and destructor,
each printing a message showing the class name and a value. Derive class B from A
adding its own data member, and derive class C from B adding another data member.
Each constructor must explicitly call its parent constructor and print its own
message; each destructor must also print its message. In main, create two objects
of class C with different values and observe the exact order in which constructors
and destructors are called. Write the expected output as a comment block in main.
*/

#include <iostream>
using namespace std;

class A {
private:
    int valueA;

public:
    A(int a) {
        valueA = a;
        cout << "Constructor of A called with value: " << valueA << endl;
    }

    ~A() {
        cout << "Destructor of A called with value: " << valueA << endl;
    }
};

class B : public A {
private:
    int valueB;

public:
    B(int a, int b) : A(a) {
        valueB = b;
        cout << "Constructor of B called with value: " << valueB << endl;
    }

    ~B() {
        cout << "Destructor of B called with value: " << valueB << endl;
    }
};

class C : public B {
private:
    int valueC;

public:
    C(int a, int b, int c) : B(a, b) {
        valueC = c;
        cout << "Constructor of C called with value: " << valueC << endl;
    }

    ~C() {
        cout << "Destructor of C called with value: " << valueC << endl;
    }
};

int main() {
    /*
    Expected Order:
    For each C object:
    1. Constructor of A is called first.
    2. Constructor of B is called second.
    3. Constructor of C is called third.

    During destruction:
    1. Destructor of C is called first.
    2. Destructor of B is called second.
    3. Destructor of A is called last.

    Objects are destroyed in reverse order of creation.
    */

    cout << "Creating first object:" << endl;
    C obj1(10, 20, 30);

    cout << "\nCreating second object:" << endl;
    C obj2(40, 50, 60);

    cout << "\nEnd of main function." << endl;

    return 0;
}