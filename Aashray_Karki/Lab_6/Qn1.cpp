/*
Question 1:
Write a program demonstrating single inheritance. Create a base class Person
having private members name and age with a parameterized constructor, a display()
function, and getter functions getName() and getAge(). Derive a class Student
from Person using public inheritance, adding private members rollNo and gpa with
its own parameterized constructor that calls the base class constructor. Override
display() in Student to show all four members. In main, create one Person object
and one Student object and call display() on each.
*/

#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
private:
    int rollNo;
    float gpa;

public:
    Student(string n, int a, int r, float g) : Person(n, a) {
        rollNo = r;
        gpa = g;
    }

    void display() {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int main() {
    Person p1("Aashray", 19);
    Student s1("Aashray", 19, 1, 3.8);

    cout << "Person Details:" << endl;
    p1.display();

    cout << "\nStudent Details:" << endl;
    s1.display();

    return 0;
}