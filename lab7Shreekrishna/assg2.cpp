#include <iostream>
using namespace std;

class Employee
{
public:
    virtual float calculateSalary() = 0;
    virtual void display() = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee
{
    float salary;

public:
    FullTimeEmployee(float s)
    {
        salary = s;
    }

    float calculateSalary()
    {
        return salary;
    }

    void display()
    {
        cout << "Full Time Employee" << endl;
        cout << "Salary: " << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee
{
    int hoursWorked;
    float hourlyRate;

public:
    PartTimeEmployee(int h, float r)
    {
        hoursWorked = h;
        hourlyRate = r;
    }

    float calculateSalary()
    {
        return hoursWorked * hourlyRate;
    }

    void display()
    {
        cout << "Part Time Employee" << endl;
        cout << "Salary: " << calculateSalary() << endl;
    }
};

class Contractor : public Employee
{
    float projectFee;
    float taxRate;

public:
    Contractor(float p, float t)
    {
        projectFee = p;
        taxRate = t;
    }

    float calculateSalary()
    {
        return projectFee - (projectFee * taxRate / 100);
    }

    void display()
    {
        cout << "Contractor" << endl;
        cout << "Salary: " << calculateSalary() << endl;
    }
};

int main()
{
    Employee *e[3];

    e[0] = new FullTimeEmployee(50000);
    e[1] = new PartTimeEmployee(100, 300);
    e[2] = new Contractor(80000, 10);

    for (int i = 0; i < 3; i++)
    {
        e[i]->display();
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete e[i];
    }

    return 0;
}