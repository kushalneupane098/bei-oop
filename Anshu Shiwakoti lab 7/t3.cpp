#include <iostream>
#include <typeinfo>
using namespace std;

class Vehicle
{
public:
    virtual ~Vehicle()
    {
        cout << "Vehicle Destructor Called" << endl;
    }

    virtual string getType()
    {
        return "Vehicle";
    }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    Car(int d)
    {
        numDoors = d;
    }

    int getDoors()
    {
        return numDoors;
    }

    ~Car()
    {
        cout << "Car Destructor Called" << endl;
    }

    string getType()
    {
        return "Car";
    }
};


class Truck : public Vehicle
{
private:
    float payloadTons;

public:
    Truck(float p)
    {
        payloadTons = p;
    }

    float getPayload()
    {
        return payloadTons;
    }

    ~Truck()
    {
        cout << "Truck Destructor Called" << endl;
    }

    string getType()
    {
        return "Truck";
    }
};

int main()
{
    Vehicle *v[3];

    v[0] = new Vehicle();
    v[1] = new Car(4);
    v[2] = new Truck(12.5);

    for (int i = 0; i < 3; i++)
    {
        cout << "\nObject " << i + 1 << endl;
        cout << "Runtime Type: " << typeid(*v[i]).name() << endl;
        Car *c = dynamic_cast<Car *>(v[i]);
        if (c != nullptr)
            cout << "Number of Doors = " << c->getDoors() << endl;
        Truck *t = dynamic_cast<Truck *>(v[i]);

        if (t != nullptr)
            cout << "Payload = " << t->getPayload() << " tons" << endl;
        delete v[i];
    }
    return 0;
}