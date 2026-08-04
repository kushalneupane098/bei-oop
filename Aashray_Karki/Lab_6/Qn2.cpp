/*
Question 2:
Write a program demonstrating multilevel inheritance. Create a base class Vehicle
having private members make and year. Derive a class Car from Vehicle adding
private member numDoors. Derive a class ElectricCar from Car adding private
members batteryCapacity and range. Each class must have a parameterized constructor
that calls its immediate parent constructor, and its own display() function that
prints all data members of that level and all levels above. In main, create one
object of each class and call display().
*/

#include <iostream>
using namespace std;

class Vehicle {
private:
    string make;
    int year;

public:
    Vehicle(string m, int y) {
        make = m;
        year = y;
    }

    void display() {
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(string m, int y, int d) : Vehicle(m, y) {
        numDoors = d;
    }

    void display() {
        Vehicle::display();
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class ElectricCar : public Car {
private:
    float batteryCapacity;
    int range;

public:
    ElectricCar(string m, int y, int d, float b, int r) : Car(m, y, d) {
        batteryCapacity = b;
        range = r;
    }

    void display() {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Range: " << range << " km" << endl;
    }
};

int main() {
    Vehicle v1("Toyota", 2020);
    Car c1("Honda", 2022, 4);
    ElectricCar e1("Tesla", 2024, 4, 75.5, 450);

    cout << "Vehicle Details:" << endl;
    v1.display();

    cout << "\nCar Details:" << endl;
    c1.display();

    cout << "\nElectric Car Details:" << endl;
    e1.display();

    return 0;
}