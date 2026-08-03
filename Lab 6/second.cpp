#include <iostream>
using namespace std;

class Vehicle
{
private:
    string make;
    int year;

public:
    Vehicle(string m, int y)
    {
        make = m;
        year = y;
    }

    string getMake()
    {
        return make;
    }

    int getYear()
    {
        return year;
    }

    virtual void display()
    {
        cout << "Vehicle Details:" << endl;
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    Car(string m, int y, int d) : Vehicle(m, y)
    {
        numDoors = d;
    }

    int getNumDoors()
    {
        return numDoors;
    }

    void display() override
    {
        cout << "Car Details:" << endl;
        cout << "Make: " << getMake() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class ElectricCar : public Car
{
private:
    float batteryCapacity;
    int range;

public:
    ElectricCar(string m, int y, int d, float b, int r) : Car(m, y, d)
    {
        batteryCapacity = b;
        range = r;
    }

    void display() override
    {
        cout << "Electric Car Details:" << endl;
        cout << "Make: " << getMake() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Number of Doors: " << getNumDoors() << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Range: " << range << " km" << endl;
    }
};

int main()
{
    Vehicle v1("Toyota", 2015);
    Car c1("Honda", 2018, 4);
    ElectricCar e1("Tesla", 2023, 4, 75.5, 500);

    v1.display();
    cout << endl;

    c1.display();
    cout << endl;

    e1.display();

    return 0;
}
