#include <iostream>
#include <string>
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
private:
    int numDoors;
public:
    Car(int doors) : numDoors(doors) {}
    ~Car() override {
        cout << "Car Destructor" << endl;
    }
    int getDoors() { return numDoors; }
};

class Truck : public Vehicle {
private:
    float payloadTons;
public:
    Truck(float payload) : payloadTons(payload) {}
    ~Truck() override {
        cout << "Truck Destructor" << endl;
    }
    float getPayload() { return payloadTons; }
};

int main() {
    Vehicle* fleet[3];
    fleet[0] = new Car(4);
    fleet[1] = new Car(2);
    fleet[2] = new Truck(5.5f);

    for (int i = 0; i < 3; ++i) {
        cout << typeid(*fleet[i]).name() << endl;

        Car* carPtr = dynamic_cast<Car*>(fleet[i]);
        if (carPtr != nullptr) {
            cout << "Doors: " << carPtr->getDoors() << endl;
        }

        Truck* truckPtr = dynamic_cast<Truck*>(fleet[i]);
        if (truckPtr != nullptr) {
            cout << "Payload: " << truckPtr->getPayload() << endl;
        }

        delete fleet[i];
    }

    return 0;
}