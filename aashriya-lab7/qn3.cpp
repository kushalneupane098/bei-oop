#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
class Vehicle {
    public:
    virtual ~Vehicle(){
        cout << "Vehicle destructor called" << endl;
    }
    virtual string getType(){
        return "Vehicle";
    }};
    class Car : public Vehicle {
     ~Car(){
            cout << "Car destructor called" << endl;
        }
       private:
       int numDoors;
       public:
        void getDoors() {
            cout << "Number of doors: " << numDoors << endl;
        }
    
       };
       class Truck : public Vehicle {
        ~Truck(){
            cout << "Truck destructor called" << endl;
        
        } 
    private:
    int payloadCapacity;
        public:
        void getPayload() {
            cout << "Payload capacity: " << payloadCapacity << endl;
        }
};
int main(){
 Vehicle* vehicle[3];
    vehicle[0] = new Vehicle();
    vehicle[1] = new Car();
    vehicle[2] = new Truck();
    for (int i = 0; i < 3; i++) {
        cout<< "\nOject "<< i + 1  << endl;
      cout<< "Runtime type: " << typeid(*vehicle[i]).name() << endl;
       


      Car* carPtr = dynamic_cast<Car*>(vehicle[i]);
        if(carPtr!= nullptr) {
            carPtr->getDoors();
        }
      Truck* truckPtr= dynamic_cast<Truck*>(vehicle[i]);
        if(truckPtr!= nullptr){
             truckPtr->getPayload();
        }  
        delete vehicle[i];
    }
    return 0;}