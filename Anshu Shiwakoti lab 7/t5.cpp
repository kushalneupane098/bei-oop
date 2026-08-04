#include <iostream>
using namespace std;
class Employee
{
public:
    virtual float calculateSalary() = 0;
    virtual void display() = 0;
};
class FullTimeEmployee : public Employee
{
private:
    float monthlySalary;

public:
    FullTimeEmployee(float salary)
    {
        monthlySalary = salary;
    }

    float calculateSalary()
    {
        return monthlySalary;
    }

    void display()
    {
        cout << "\nFull-Time Employee" << endl;
        cout << "Monthly Salary = Rs. " << calculateSalary() << endl;
    }
};
class PartTimeEmployee : public Employee
{
private:
    int hoursWorked;
    float hourlyRate;

public:
    PartTimeEmployee(int hours, float rate)
    {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    float calculateSalary()
    {
        return hoursWorked * hourlyRate;
    }

    void display()
    {
        cout << "\nPart-Time Employee" << endl;
        cout << "Hours Worked = " << hoursWorked << endl;
        cout << "Hourly Rate = Rs. " << hourlyRate << endl;
        cout << "Salary = Rs. " << calculateSalary() << endl;
    }
};
class Contractor : public Employee
{
private:
    float projectFee;
    float taxRate;

public:
    Contractor(float fee, float tax)
    {
        projectFee = fee;
        taxRate = tax;
    }

    float calculateSalary()
    {
        return projectFee - (projectFee * taxRate / 100);
    }

    void display()
    {
        cout << "\nContractor" << endl;
        cout << "Project Fee = Rs. " << projectFee << endl;
        cout << "Tax Rate = " << taxRate << "%" << endl;
        cout << "Salary = Rs. " << calculateSalary() << endl;
    }
};

int main()
{
    Employee *emp[3];

    emp[0] = new FullTimeEmployee(50000);
    emp[1] = new PartTimeEmployee(80, 500);
    emp[2] = new Contractor(100000, 10);

    cout << "Employee Details\n";

    for (int i = 0; i < 3; i++)
    {
        emp[i]->display();
    }

    for (int i = 0; i < 3; i++)
    {
        delete emp[i];
    }
    return 0;
}