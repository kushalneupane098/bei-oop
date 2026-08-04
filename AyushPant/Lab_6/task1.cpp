#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}

    string getName() const { return name; }
    int getAge() const { return age; }

    void display() const {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};

class Student : public Person {
private:
    int rollNo;
    float gpa;

public:
    Student(string name, int age, int rollNo, float gpa)
        : Person(name, age), rollNo(rollNo), gpa(gpa) {}

    void display() const {
        Person::display();              
        cout << "Roll : " << rollNo << endl;
        cout << "GPA  : " << gpa << endl;
    }
};

int main() {
    Person p("Ram Sharma", 45);
    Student s("Sita Thapa", 20, 101, 3.85f);

    cout << "--- Person ---" << endl;
    p.display();

    cout << "\n--- Student ---" << endl;
    s.display();

    return 0;
}
