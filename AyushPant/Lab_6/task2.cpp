#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string make;
    int year;

public:
    Vehicle(string make, int year) : make(make), year(year) {}

    void display() const {
        cout << "Make  : " << make << endl;
        cout << "Year  : " << year << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(string make, int year, int numDoors)
        : Vehicle(make, year), numDoors(numDoors) {}

    void display() const {
        Vehicle::display();
        cout << "Doors : " << numDoors << endl;
    }
};

class Bike : public Vehicle {
private:
    int gears;

public:
    Bike(string make, int year, int gears)
        : Vehicle(make, year), gears(gears) {}

    void display() const {
        Vehicle::display();
        cout << "Gears : " << gears << endl;
    }
};

class ElectricCar : public Car {
private:
    float batteryCapacity;
    int range;

public:
    ElectricCar(string make, int year, int numDoors, float batteryCapacity, int range)
        : Car(make, year, numDoors), batteryCapacity(batteryCapacity), range(range) {}

    void display() const {
        Car::display();
        cout << "Battery: " << batteryCapacity << " kWh" << endl;
        cout << "Range  : " << range << " km" << endl;
    }
};

int main() {
    Car c("Toyota", 2021, 4);
    Bike b("Trek", 2022, 21);
    ElectricCar e("Tesla", 2024, 4, 100.0f, 570);

    cout << "--- Car ---" << endl;
    c.display();

    cout << "\n--- Bike ---" << endl;
    b.display();

    cout << "\n--- ElectricCar ---" << endl;
    e.display();

    return 0;
}
