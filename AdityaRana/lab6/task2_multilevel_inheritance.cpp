#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string make;
    int year;

public:
    Vehicle(string mk, int yr) : make(mk), year(yr) {}

    void display() {
        cout << "Make: " << make << ", Year: " << year;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    // Calls immediate parent (Vehicle) constructor
    Car(string mk, int yr, int doors) : Vehicle(mk, yr), numDoors(doors) {}

    void display() {
        Vehicle::display();
        cout << ", Doors: " << numDoors;
        cout << endl;
    }
};

class ElectricCar : public Car {
private:
    float batteryCapacity;
    int range;

public:
    // Calls immediate parent (Car) constructor
    ElectricCar(string mk, int yr, int doors, float battery, int rng)
        : Car(mk, yr, doors), batteryCapacity(battery), range(rng) {}

    // Prints all data members of this level and all levels above
    void display() {
        Car::display(); // prints Make, Year, Doors (ends with newline)
        cout << "Battery Capacity: " << batteryCapacity
             << " kWh, Range: " << range << " km" << endl;
    }
};

int main() {
    cout << "--- Vehicle object ---" << endl;
    Vehicle v("Toyota", 2015);
    v.display();
    cout << endl;

    cout << "\n--- Car object ---" << endl;
    Car c("Honda", 2019, 4);
    c.display();

    cout << "\n--- ElectricCar object ---" << endl;
    ElectricCar ec("Tesla", 2023, 4, 75.0f, 500);
    ec.display();

    return 0;
}
