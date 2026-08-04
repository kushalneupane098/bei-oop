#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string make;
    int year;

public:
    Vehicle(string m, int y)
    {
        make = m;
        year = y;
    }

    virtual void display()
    {
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle
{
protected:
    int numDoors;

public:
    Car(string m, int y, int d) : Vehicle(m, y)
    {
        numDoors = d;
    }

    void display()
    {
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class ElectricCar : public Car
{
private:
    float batteryCapacity;
    int range;

public:
    ElectricCar(string m, int y, int d, float b, int r)
        : Car(m, y, d)
    {
        batteryCapacity = b;
        range = r;
    }

    void display()
    {
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Range: " << range << " km" << endl;
    }
};

int main()
{
    Vehicle v("Toyota", 2020);
    Car c("Honda", 2021, 4);
    ElectricCar e("Tesla", 2024, 4, 75.5, 500);

    cout << "Vehicle Details" << endl;
    v.display();

    cout << endl;

    cout << "Car Details" << endl;
    c.display();

    cout << endl;

    cout << "Electric Car Details" << endl;
    e.display();

    return 0;
}