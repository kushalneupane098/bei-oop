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

    void display()
    {
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
    }

protected:
    string getMake() { return make; }
    int getYear() { return year; }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    Car(string m, int y, int d)
        : Vehicle(m, y)
    {
        numDoors = d;
    }

    void display()
    {
        cout << "Make: " << getMake() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Doors: " << numDoors << endl;
    }

protected:
    int getDoors() { return numDoors; }
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
        cout << "Make: " << getMake() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Doors: " << getDoors() << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Range: " << range << " km" << endl;
    }
};

int main()
{
    Vehicle v("Toyota", 2020);
    Car c("Honda", 2021, 4);
    ElectricCar e("Tesla", 2024, 4, 75.5, 500);

    cout << "Vehicle:\n";
    v.display();

    cout << "\nCar:\n";
    c.display();

    cout << "\nElectric Car:\n";
    e.display();

    return 0;
}