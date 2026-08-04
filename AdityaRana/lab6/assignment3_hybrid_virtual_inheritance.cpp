#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {
        cout << "Animal constructor called for " << name << endl;
    }

    string getName() { return name; }
    int getAge() { return age; }
};

// virtual inheritance so Bat only gets ONE copy of Animal
class Mammal : virtual public Animal {
private:
    string furColor;

public:
    Mammal(string n, int a, string fur) : Animal(n, a), furColor(fur) {
        cout << "Mammal constructor called" << endl;
    }

    string getFurColor() { return furColor; }
};

class Bird : virtual public Animal {
private:
    float wingspan;

public:
    Bird(string n, int a, float ws) : Animal(n, a), wingspan(ws) {
        cout << "Bird constructor called" << endl;
    }

    float getWingspan() { return wingspan; }
};

// Bat inherits from BOTH Mammal and Bird, which both virtually inherit Animal
class Bat : public Mammal, public Bird {
private:
    bool echolocation;

public:
    // Because of virtual inheritance, Bat must call Animal's constructor
    // DIRECTLY (it is not called implicitly via Mammal/Bird)
    Bat(string n, int a, string fur, float ws, bool echo)
        : Animal(n, a), Mammal(n, a, fur), Bird(n, a, ws), echolocation(echo) {
        cout << "Bat constructor called" << endl;
    }

    void display() {
        cout << "Name: " << getName() << ", Age: " << getAge()
             << ", Fur Color: " << getFurColor()
             << ", Wingspan: " << getWingspan()
             << ", Echolocation: " << (echolocation ? "Yes" : "No") << endl;
    }
};

int main() {
    cout << "--- Creating Bat object ---" << endl;
    Bat b("Bruce", 3, "Brown", 0.3f, true);

    cout << "\n--- Displaying Bat details ---" << endl;
    b.display();

    return 0;
}

/*
WHY VIRTUAL INHERITANCE IS NEEDED HERE:

Without virtual inheritance, Bat inherits from both Mammal and Bird,
and each of THOSE classes has its own separate copy of Animal's
members (name, age). This creates the "diamond problem": a Bat object
would contain TWO separate Animal sub-objects, so calling something
like b.getName() would be ambiguous -- the compiler wouldn't know
whether to use the copy from Mammal's Animal or Bird's Animal.

By declaring "class Mammal : virtual public Animal" and
"class Bird : virtual public Animal", we tell the compiler that
Mammal and Bird should SHARE a single common Animal sub-object.
So a Bat object ends up with only ONE copy of name and age, resolving
the ambiguity. This also means the most-derived class (Bat) becomes
responsible for directly initializing the virtual base (Animal) in
its constructor initializer list, since the normal chain of implicit
calls is bypassed for virtual bases.
*/
