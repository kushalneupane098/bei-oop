/*
Question 3:
Demonstrate virtual destructors and RTTI using typeid and dynamic_cast.
*/

#include <iostream>
#include <typeinfo>
using namespace std;

class Vehicle {
public:
    virtual string getType() const {
        return "Vehicle";
    }

    virtual ~Vehicle() {
        cout << "Vehicle destructor called" << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(int d) {
        numDoors = d;
    }

    string getType() const override {
        return "Car";
    }

    int getDoors() const {
        return numDoors;
    }

    ~Car() override {
        cout << "Car destructor called" << endl;
    }
};

class Truck : public Vehicle {
private:
    float payloadTons;

public:
    Truck(float p) {
        payloadTons = p;
    }

    string getType() const override {
        return "Truck";
    }

    float getPayload() const {
        return payloadTons;
    }

    ~Truck() override {
        cout << "Truck destructor called" << endl;
    }
};

int main() {
    Vehicle *v[3];

    v[0] = new Vehicle();
    v[1] = new Car(4);
    v[2] = new Truck(8.5);

    for (int i = 0; i < 3; i++) {
        cout << "\nObject " << i + 1 << endl;
        cout << "getType(): " << v[i]->getType() << endl;
        cout << "typeid: " << typeid(*v[i]).name() << endl;

        Car *c = dynamic_cast<Car*>(v[i]);
        if (c != NULL)
            cout << "Doors: " << c->getDoors() << endl;
        else
            cout << "Not a Car" << endl;

        Truck *t = dynamic_cast<Truck*>(v[i]);
        if (t != NULL)
            cout << "Payload: " << t->getPayload() << " tons" << endl;
        else
            cout << "Not a Truck" << endl;

        cout << "Deleting object:" << endl;
        delete v[i];
    }

    /*
    dynamic_cast returns NULL when the actual object is not of the target type.
    If the base destructor were not virtual, derived destructors would not run properly
    when deleting through a base class pointer.
    */

    return 0;
}