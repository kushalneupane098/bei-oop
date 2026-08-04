#include <iostream>
using namespace std;
class Animal {
public:
  virtual void speaks() {
        cout << "Animal speaks" << endl;
    }};
    class Dog : public Animal{ 
         void speaks() {
            cout << "Dog barks" << endl;
        }
    };
     class Cat : public Animal {
        void speaks() {
            cout << "Cat meows" << endl;
        }};
int main() {
   Animal *ptr;
   Dog d;
    Cat c;
    ptr = &d;
    ptr->speaks();
    ptr = &c;
    ptr->speaks();
    return 0;
}        