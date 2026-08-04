#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Parameterised constructor
    Person(string n, int a) : name(n), age(a) {
        cout << "Person constructor called for " << name << endl;
    }

    // Getter functions
    string getName() { return name; }
    int getAge() { return age; }

    // Display function
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
private:
    int rollNo;
    float gpa;

public:
    // Student constructor calls base class constructor
    Student(string n, int a, int r, float g)
        : Person(n, a), rollNo(r), gpa(g) {
        cout << "Student constructor called for roll no " << rollNo << endl;
    }

    // Override display() to show all four members
    void display() {
        cout << "Name: " << getName() << ", Age: " << getAge()
             << ", Roll No: " << rollNo << ", GPA: " << gpa << endl;
    }
};

int main() {
    cout << "--- Creating Person object ---" << endl;
    Person p("Alice", 30);

    cout << "\n--- Creating Student object ---" << endl;
    Student s("Bob", 20, 101, 3.75f);

    cout << "\n--- Displaying objects ---" << endl;
    cout << "Person: ";
    p.display();

    cout << "Student: ";
    s.display();

    return 0;
}
