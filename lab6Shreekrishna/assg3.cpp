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

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }
};

class Mammal : virtual public Animal {
private:
    string furColor;

public:
    Mammal(string n, int a, string f)
        : Animal(n, a) {
        furColor = f;
    }

    string getFurColor() {
        return furColor;
    }
};

class Bird : virtual public Animal {
private:
    float wingspan;

public:
    Bird(string n, int a, float w)
        : Animal(n, a) {
        wingspan = w;
    }

    float getWingspan() {
        return wingspan;
    }
};

class Bat : public Mammal, public Bird {
private:
    bool echolocation;

public:
    Bat(string n, int a, string f,
        float w, bool e)
        : Animal(n, a),
          Mammal(n, a, f),
          Bird(n, a, w) {
        echolocation = e;
    }

    void display() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Fur Color: " << getFurColor() << endl;
        cout << "Wingspan: " << getWingspan() << endl;
        cout << "Echolocation: "
             << (echolocation ? "Yes" : "No")
             << endl;
    }
};

int main() {
    Bat b("Batman", 3, "Black", 1.5, true);

    b.display();

    return 0;
}

