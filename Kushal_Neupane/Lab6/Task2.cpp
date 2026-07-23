#include<iostream>
#include<string>
using namespace std;
class Vechile{
    private:
    string make;
    int year;
    public:
    Vechile(string m,int y)
    {
        make =m;
        year=y;
    }
    void display()
    {
        cout<<"Make: "<<make<<endl;
        cout<<"Year: "<<year<<endl;
    }
    string getMake()
    {
        return make;
    }
    int getYear()
    {
        return year;
    }
};
class Car:public Vechile{
    private:
    int numDoors;
    public:
    Car(string m, int y ,int num):Vechile(m,y)
    {
        numDoors=num;
    }
    void display()
    {
        cout<<"Number of Doors: "<<numDoors<<endl;
        cout << "Make: " << getMake() << endl;
        cout << "Year: " << getYear() << endl;
    }
    int getNumDoors()
    {
        return numDoors;
    }
};
class ElectricCar:public Car{
    private:
    float batteryCapacity;
    int range;
    public:
    ElectricCar(float cap,int r, int num,int y,string m):Car(m,y,num)
    {
        batteryCapacity=cap;
        range=r;
    } 
    void display()
    {
        cout<<"Battery Capacity: "<<batteryCapacity<<endl;
        cout<<"Range: "<<range <<endl;
        cout << "Number of Doors: " << getNumDoors() << endl;
        cout << "Make: " << getMake() << endl;
        cout << "Year: " << getYear() << endl;
    }
    float getBatteryCapacity()
    {
        return batteryCapacity;
    }
    int getRange()
    {
        return range;
    }
};
int main()
{
    ElectricCar e1(75, 300, 4, 2022, "Tesla");
    e1.display();
    Car c1("Toyota", 2020, 4);
    c1.display();
    Vechile v1("Honda", 2018);
    v1.display();
    return 0;
}