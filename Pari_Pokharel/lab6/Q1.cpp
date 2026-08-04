#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    string getName() const { return name; }
    int getAge() const { return age; }

    void display() const
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person
{
private:
    int rollNo;
    float gpa;

public:
    Student(string n, int a, int r, float g) : Person(n, a), rollNo(r), gpa(g) {}

    void display() const
    {
        cout << "Name: " << getName() << ", Age: " << getAge()
             << ", Roll No: " << rollNo << ", GPA: " << gpa << endl;
    }
};

int main()
{
    Person p("kushal", 45);
    Student s("khushi", 20, 101, 3.8);

    p.display();
    s.display();

    return 0;
}