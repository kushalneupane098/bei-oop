#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    int age;

public:
    Animal(string name, int age) : name(name), age(age) {}

    string getName() const { return name; }
    int getAge() const { return age; }

    void display() const {
        cout << "Name       : " << name << endl;
        cout << "Age        : " << age << endl;
    }
};

class Mammal : virtual public Animal {
private:
    string furColor;

public:
    Mammal(string name, int age, string furColor)
        : Animal(name, age), furColor(furColor) {}

    string getFurColor() const { return furColor; }

    void display() const {
        Animal::display();
        cout << "Fur Color  : " << furColor << endl;
    }
};

class Bird : virtual public Animal {
private:
    float wingspan;

public:
    Bird(string name, int age, float wingspan)
        : Animal(name, age), wingspan(wingspan) {}

    float getWingspan() const { return wingspan; }

    void display() const {
        Animal::display();
        cout << "Wingspan   : " << wingspan << endl;
    }
};

class FlyingSquirrel : public Mammal, public Bird {
private:
    bool canGlide;

public:
    FlyingSquirrel(string name, int age, string furColor, float wingspan, bool canGlide)
        : Animal(name, age), Mammal(name, age, furColor), Bird(name, age, wingspan), canGlide(canGlide) {}

    void display() const {
        Animal::display();
        cout << "Fur Color  : " << getFurColor() << endl;
        cout << "Wingspan   : " << getWingspan() << endl;
        cout << "Can Glide  : " << (canGlide ? "Yes" : "No") << endl;
    }
};

int main() {
    FlyingSquirrel fs("Flying Squirrel", 2, "Reddish Brown", 0.3f, true);

    cout << "--- Flying Squirrel ---" << endl;
    fs.display();

    return 0;
}
