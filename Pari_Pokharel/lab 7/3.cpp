#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Vehicle
{
public:
    virtual string getType() { return "Vehicle"; }
    virtual ~Vehicle()
    {
        cout << "Vehicle Destructor Called" << endl;
    }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    Car(int doors) : numDoors(doors) {}
    string getType() override { return "Car"; }
    int getDoors() { return numDoors; }
    ~Car() override
    {
        cout << "Car Destructor Called" << endl;
    }
};

class Truck : public Vehicle
{
private:
    float payloadTons;

public:
    Truck(float payload) : payloadTons(payload) {}
    string getType() override { return "Truck"; }
    float getPayload() { return payloadTons; }
    ~Truck() override
    {
        cout << "Truck Destructor Called" << endl;
    }
};

int main()
{
    Vehicle *fleet[3];
    fleet[0] = new Vehicle();
    fleet[1] = new Car(4);
    fleet[2] = new Truck(5.5f);

    for (int i = 0; i < 3; ++i)
    {
        cout << "\n--- Processing Element " << i << " ---" << endl;

        cout << "Runtime Type: " << typeid(*fleet[i]).name() << endl;

        Car *carPtr = dynamic_cast<Car *>(fleet[i]);
        if (carPtr != nullptr)
        {
            cout << "Car doors: " << carPtr->getDoors() << endl;
        }

        Truck *truckPtr = dynamic_cast<Truck *>(fleet[i]);
        if (truckPtr != nullptr)
        {
            cout << "Truck Payload: " << truckPtr->getPayload() << " tons" << endl;
        }

        delete fleet[i];
    }

    return 0;
}