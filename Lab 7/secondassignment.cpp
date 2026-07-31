#include <iostream>
using namespace std;

class Employee
{
public:
    virtual float calculateSalary() = 0;
    virtual void display() = 0;
    virtual ~Employee()
    {
    }
};

class FullTimeEmployee : public Employee
{
private:
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
        cout << "Full Time Employee Salary: " << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee
{
private:
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
        cout << "Part Time Employee Salary: " << calculateSalary() << endl;
    }
};

class Contractor : public Employee
{
private:
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
        cout << "Contractor Salary: " << calculateSalary() << endl;
    }
};

int main()
{
    Employee *employees[3];

    employees[0] = new FullTimeEmployee(50000);
    employees[1] = new PartTimeEmployee(80, 200);
    employees[2] = new Contractor(100000, 10);

    for(int i = 0; i < 3; i++)
    {
        employees[i]->display();
    }

    for(int i = 0; i < 3; i++)
    {
        delete employees[i];
    }

    return 0;
}