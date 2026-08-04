#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int age;

public:
    Animal(string n, int a)
    {
        name = n;
        age = a;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Mammal : virtual public Animal
{
protected:
    string furColor;

public:
    Mammal(string n, int a, string f) : Animal(n, a)
    {
        furColor = f;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Fur Color: " << furColor << endl;
    }
};

class Bird : virtual public Animal
{
protected:
    float wingspan;

public:
    Bird(string n, int a, float w) : Animal(n, a)
    {
        wingspan = w;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Wingspan: " << wingspan << " m" << endl;
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
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Fur Color: " << furColor << endl;
        cout << "Wingspan: " << wingspan << " m" << endl;
        cout << "Echolocation: ";

        if (echolocation)
            cout << "Yes";
        else
            cout << "No";

        cout << endl;
    }
};

int main()
{

    Bat b("Fruit Bat", 3, "Brown", 1.5, true);

    b.display();

    return 0;
}