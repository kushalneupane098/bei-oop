#include <iostream>

using namespace std;

class Vehicle {
public:
    virtual ~Vehicle() {
        cout << "Vehicle destructor" << endl;
    }

    virtual string getType() {
        return "Vehicle";
    }
};

class Car : public Vehicle {
    int numDoors;
public:
    Car(int d) : numDoors(d) {}
    ~Car() {
        cout << "Car destructor" << endl;
    }

    int getDoors() {
        return numDoors;
    }

    string getType() {
        return "Car";
    }
};

class Truck : public Vehicle {
    float payloadTons;
public:
    Truck(float p) : payloadTons(p) {}

    ~Truck() {
        cout << "Truck destructor" << endl;
    }

    float getPayload() {
        return payloadTons;
    }

    string getType() {
        return "Truck";
    }
};

int main() {
    Vehicle* arr[3];

    arr[0] = new Vehicle();
    arr[1] = new Car(4);
    arr[2] = new Truck(10.5);

    for (int i = 0; i < 3; i++) {
        cout << "Type: " << typeid(*arr[i]).name() << endl;

        Car* c = dynamic_cast<Car*>(arr[i]);
        if (c) {
            cout << "Doors: " << c->getDoors() << endl;
        }

        Truck* t = dynamic_cast<Truck*>(arr[i]);
        if (t) {
            cout << "Payload: " << t->getPayload() << endl;
        }

        delete arr[i];
        cout << endl;
    }

    return 0;
}