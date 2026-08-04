#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {}

    void display() const
    {
        cout << "Name: " << name << ", Age: " << age;
    }
};

class Mammal : virtual public Animal
{
private:
    string furColor;

public:
    Mammal(string n, int a, string f) : Animal(n, a), furColor(f) {}

    void display() const
    {
        cout << ", Fur: " << furColor;
    }
};

class Bird : virtual public Animal
{
private:
    float wingspan;

public:
    Bird(string n, int a, float w) : Animal(n, a), wingspan(w) {}

    void display() const
    {
        cout << ", Wingspan: " << wingspan;
    }
};

class Bat : public Mammal, public Bird
{
private:
    bool echolocation;

public:
    Bat(string n, int a, string f, float w, bool e)
        : Animal(n, a), Mammal(n, a, f), Bird(n, a, w), echolocation(e) {}

    void display() const
    {
        Animal::display();
        Mammal::display();
        Bird::display();
        cout << ", Echo: " << echolocation << endl;
    }
};

int main()
{
    Bat b("Fruit Bat", 3, "Brown", 0.6, true);
    b.display();

    return 0;
}