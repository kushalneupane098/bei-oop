#include <iostream>
#include<string.h>
using namespace std;
class Vehicle{
    private:
    string make;
    int year;
    public:
    Vehicle(string m,int y){
        make=m;
        year=y;
    }
    void display()
    {
        cout<<"make:"<<make<<endl<<"year:"<<year<<endl;
    }
};
    class Car:public Vehicle{
        private:
        int door;
        public:
        Car(string m,int y,int d):Vehicle(m,y){
            door=d;
        }
        void display(){
            Vehicle::display();
            cout<<"No of door:"<<door<<endl;
        }
    };
    class ElectricCar:public Car{
        private:
        int batcap;
        int range;
        public:
        ElectricCar(string m,int y,int d,int bc,int r):Car(m,y,d){
            batcap=bc;
            range=r;
        }
        void display(){
            Car::display();
            cout<<"battery capacity:"<<batcap<<endl<<"range"<<range<<endl;
        }
    };
    int main(){
        ElectricCar E("Gadi",2000,25,200,10);
        cout<<"all details"<<endl;
        E.display();
        return 0;
    }
