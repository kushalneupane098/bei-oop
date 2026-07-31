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
        cout << "Person Details:" << endl;
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
        cout << "Student Details:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "GPA: " << gpa << endl;
    }
};


int main() {
    
    Person p1("Pratik", 20);
    p1.display();

    cout << endl;

    
    Student s1("Aarav", 22, 101, 3.8);
    s1.display();

    return 0;
}