#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person
{
private:
    int rollNo;
    float gpa;

public:
    Student(string n, int a, int r, float g) : Person(n, a)
    {
        rollNo = r;
        gpa = g;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "GPA: " << gpa << endl;
    }
};

int main()
{
    Person p("Anshu", 20);
    Student s("Rahul", 21, 101, 3.85);

    cout << "Person Details:" << endl;
    p.display();

    cout << endl;

    cout << "Student Details:" << endl;
    s.display();

    return 0;
}