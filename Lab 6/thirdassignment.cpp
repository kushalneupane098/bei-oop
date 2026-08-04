#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    string name;
    int age;

public:
    Animal(string n, int a)
    {
        name = n;
        age = a;
    }

    void displayAnimal()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Mammal : virtual public Animal
{
private:
    string furColor;

public:
    Mammal(string n, int a, string f) : Animal(n, a)
    {
        furColor = f;
    }

    void displayMammal()
    {
        cout << "Fur Color: " << furColor << endl;
    }
};

class Bird : virtual public Animal
{
private:
    float wingspan;

public:
    Bird(string n, int a, float w) : Animal(n, a)
    {
        wingspan = w;
    }

    void displayBird()
    {
        cout << "Wingspan: " << wingspan << endl;
    }
};

class Bat : public Mammal, public Bird
{
private:
    bool echolocation;

public:
    Bat(string n, int a, string f, float w, bool e)
        : Animal(n, a), Mammal(n, a, f), Bird(n, a, w)
    {
        echolocation = e;
    }

    void display()
    {
        displayAnimal();
        displayMammal();
        displayBird();
        cout << "Echolocation: " << (echolocation ? "Yes" : "No") << endl;
    }
};

int main()
{
    /*
    Virtual inheritance is needed because Mammal and Bird both inherit
    from Animal. Without virtual inheritance, Bat would contain two
    copies of Animal causing ambiguity.
    */

    Bat b("Dracula", 5, "Black", 1.5, true);

    b.display();

    return 0;
}