#include <iostream>
#include <typeinfo>
using namespace std;

class Vehicle {
public:
    virtual ~Vehicle() {
        cout << "Vehicle Destructor" << endl;
    }

    virtual string getType() {
        return "Vehicle";
    }
};

class Car : public Vehicle {
    int numDoors;

public:
    Car(int d = 4) {
        numDoors = d;
    }

    int getDoors() {
        return numDoors;
    }

    ~Car() {
        cout << "Car Destructor" << endl;
    }
};

class Truck : public Vehicle {
    float payloadTons;

public:
    Truck(float p = 10) {
        payloadTons = p;
    }

    float getPayload() {
        return payloadTons;
    }

    ~Truck() {
        cout << "Truck Destructor" << endl;
    }
};

int main() {
    Vehicle* v[3];

    v[0] = new Vehicle();
    v[1] = new Car(4);
    v[2] = new Truck(12.5);

    for (int i = 0; i < 3; i++) {
        cout << "Type: " << typeid(*v[i]).name() << endl;

        Car* c = dynamic_cast<Car*>(v[i]);
        if (c)
            cout << "Doors: " << c->getDoors() << endl;

        Truck* t = dynamic_cast<Truck*>(v[i]);
        if (t)
            cout << "Payload: " << t->getPayload() << " tons" << endl;

        delete v[i];
        cout << endl;
    }

    return 0;
}