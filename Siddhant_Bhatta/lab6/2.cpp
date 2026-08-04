#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
private:
    string make;
    int year;

public:
    Vehicle(string m, int y) : make(m), year(y) {}

    void display() const
    {
        cout << "Make: " << make << ", Year: " << year;
    }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    Car(string m, int y, int d) : Vehicle(m, y), numDoors(d) {}

    void display() const
    {
        Vehicle::display();
        cout << ", Doors: " << numDoors;
    }
};

class ElectricCar : public Car
{
private:
    float batteryCapacity;
    int range;

public:
    ElectricCar(string m, int y, int d, float c, int r)
        : Car(m, y, d), batteryCapacity(c), range(r) {}

    void display() const
    {
        Car::display();
        cout << ", Battery: " << batteryCapacity << "kWh, Range: " << range << endl;
    }
};

int main()
{
    Vehicle v("Ford", 2018);
    Car c("Toyota", 2021, 4);
    ElectricCar ec("Tesla", 2024, 4, 75.5, 320);

    v.display();
    cout << endl;

    c.display();
    cout << endl;

    ec.display();

    return 0;
}