#include<iostream>
using namespace std;

class Vehicle
{
private:
    string make;
    int year;

public:
    Vehicle(string m,int y)
    {
        make=m;
        year=y;
    }

    string getMake()
    {
        return make;
    }

    int getYear()
    {
        return year;
    }

    void display()
    {
        cout<<"Make : "<<make<<endl;
        cout<<"Year : "<<year<<endl;
    }
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    Car(string m,int y,int d):Vehicle(m,y)
    {
        numDoors=d;
    }

    int getDoors()
    {
        return numDoors;
    }

    void display()
    {
        cout<<"Make : "<<getMake()<<endl;
        cout<<"Year : "<<getYear()<<endl;
        cout<<"Doors : "<<numDoors<<endl;
    }
};

class ElectricCar : public Car
{
private:
    float batteryCapacity;
    int range;

public:
    ElectricCar(string m,int y,int d,float b,int r)
    :Car(m,y,d)
    {
        batteryCapacity=b;
        range=r;
    }

    void display()
    {
        cout<<"Make : "<<getMake()<<endl;
        cout<<"Year : "<<getYear()<<endl;
        cout<<"Doors : "<<getDoors()<<endl;
        cout<<"Battery : "<<batteryCapacity<<" kWh"<<endl;
        cout<<"Range : "<<range<<" km"<<endl;
    }
};

int main()
{
    Vehicle v("Toyota",2022);
    Car c("Honda",2023,4);
    ElectricCar e("Tesla",2024,4,75,500);

    cout<<"Vehicle"<<endl;
    v.display();

    cout<<"\nCar"<<endl;
    c.display();

    cout<<"\nElectric Car"<<endl;
    e.display();

    return 0;
}