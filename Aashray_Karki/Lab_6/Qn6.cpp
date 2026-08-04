/*
Assignment 3:
Write a program demonstrating hybrid inheritance combining hierarchical and multiple
inheritance. Create a base class Animal having private members name and age.
Derive two classes separately: Mammal from Animal adding private member furColor,
and Bird from Animal adding private member wingspan. Derive a class Bat from both
Mammal and Bird using virtual inheritance to resolve the diamond problem, adding
a private member echolocation. Each class has a parameterized constructor that
calls its parent constructors and a display() function that prints all its members.
In main, create a Bat object and call display(). Explain in a comment why virtual
inheritance is needed here.
*/

#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    int age;

public:
    Animal(string n, int a) {
        name = n;
        age = a;
    }

    void displayAnimal() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Mammal : virtual public Animal {
private:
    string furColor;

public:
    Mammal(string n, int a, string f) : Animal(n, a) {
        furColor = f;
    }

    void displayMammal() {
        cout << "Fur Color: " << furColor << endl;
    }
};

class Bird : virtual public Animal {
private:
    float wingspan;

public:
    Bird(string n, int a, float w) : Animal(n, a) {
        wingspan = w;
    }

    void displayBird() {
        cout << "Wingspan: " << wingspan << " meters" << endl;
    }
};

class Bat : public Mammal, public Bird {
private:
    bool echolocation;

public:
    Bat(string n, int a, string f, float w, bool e)
        : Animal(n, a), Mammal(n, a, f), Bird(n, a, w) {
        echolocation = e;
    }

    void display() {
        displayAnimal();
        displayMammal();
        displayBird();
        cout << "Echolocation: " << (echolocation ? "Yes" : "No") << endl;
    }

    /*
    Virtual inheritance is needed here because Mammal and Bird both inherit
    from Animal. Without virtual inheritance, Bat would contain two copies
    of Animal, causing ambiguity. Virtual inheritance ensures that Bat has
    only one shared Animal base class object.
    */
};

int main() {
    Bat b1("Bat", 3, "Black", 0.8, true);

    cout << "Bat Details:" << endl;
    b1.display();

    return 0;
}