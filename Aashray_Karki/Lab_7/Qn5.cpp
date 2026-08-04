/*
Assignment 2:
Create abstract Employee class and derived FullTimeEmployee,
PartTimeEmployee, and Contractor classes.
*/

#include <iostream>
using namespace std;

class Employee {
public:
    virtual float calculateSalary() const = 0;
    virtual void display() const = 0;

    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
private:
    float monthlySalary;

public:
    FullTimeEmployee(float s) {
        monthlySalary = s;
    }

    float calculateSalary() const override {
        return monthlySalary;
    }

    void display() const override {
        cout << "Full Time Employee Salary: " << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    float hourlyRate;

public:
    PartTimeEmployee(int h, float r) {
        hoursWorked = h;
        hourlyRate = r;
    }

    float calculateSalary() const override {
        return hoursWorked * hourlyRate;
    }

    void display() const override {
        cout << "Part Time Employee Salary: " << calculateSalary() << endl;
    }
};

class Contractor : public Employee {
private:
    float projectFee;
    float taxRate;

public:
    Contractor(float f, float t) {
        projectFee = f;
        taxRate = t;
    }

    float calculateSalary() const override {
        return projectFee - (projectFee * taxRate / 100);
    }

    void display() const override {
        cout << "Contractor Salary: " << calculateSalary() << endl;
    }
};

int main() {
    Employee *emp[3];

    emp[0] = new FullTimeEmployee(50000);
    emp[1] = new PartTimeEmployee(80, 500);
    emp[2] = new Contractor(60000, 10);

    for (int i = 0; i < 3; i++) {
        emp[i]->display();
    }

    for (int i = 0; i < 3; i++) {
        delete emp[i];
    }

    return 0;
}