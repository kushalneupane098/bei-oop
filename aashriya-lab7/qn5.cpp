#include <iostream>
using namespace std;

class Employee {
public:
    virtual float calculateSalary() = 0;
    virtual void display() = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    float monthlySalary;

public:
    FullTimeEmployee(float salary)
        : monthlySalary(salary) {}

    float calculateSalary() override {
        return monthlySalary;
    }

    void display() override {
        cout << "Full-Time Employee Salary = "
             << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee {
    int hoursWorked;
    float hourlyRate;

public:
    PartTimeEmployee(int h, float r)
        : hoursWorked(h), hourlyRate(r) {}

    float calculateSalary() override {
        return hoursWorked * hourlyRate;
    }

    void display() override {
        cout << "Part-Time Employee Salary = "
             << calculateSalary() << endl;
    }
};

class Contractor : public Employee {
    float projectFee;
    float taxRate;

public:
    Contractor(float fee, float tax)
        : projectFee(fee), taxRate(tax) {}

    float calculateSalary() override {
        return projectFee - (projectFee * taxRate / 100);
    }

    void display() override {
        cout << "Contractor Salary = "
             << calculateSalary() << endl;
    }
};

int main() {
    Employee* employees[3];

    employees[0] = new FullTimeEmployee(50000);
    employees[1] = new PartTimeEmployee(80, 500);
    employees[2] = new Contractor(60000, 10);

    for (int i = 0; i < 3; i++) {
        employees[i]->display();
    }

    for (int i = 0; i < 3; i++) {
        delete employees[i];
    }

    return 0;
}