/*
Question 3:
Write a program demonstrating multiple inheritance. Create a class Teacher having
private members teacherID and subject. Create a class Researcher having private
members researchArea and publications. Derive a class Professor from both Teacher
and Researcher using public inheritance, adding a private member university.
Each class has a parameterized constructor and a display() function. The Professor
constructor must call both parent constructors. In main, create a Professor object
and call display() to show all data members. Explain in a comment how constructor
call order works.
*/

#include <iostream>
using namespace std;

class Teacher {
private:
    int teacherID;
    string subject;

public:
    Teacher(int id, string sub) {
        teacherID = id;
        subject = sub;
    }

    void display() {
        cout << "Teacher ID: " << teacherID << endl;
        cout << "Subject: " << subject << endl;
    }
};

class Researcher {
private:
    string researchArea;
    int publications;

public:
    Researcher(string area, int pub) {
        researchArea = area;
        publications = pub;
    }

    void display() {
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    string university;

public:
    Professor(int id, string sub, string area, int pub, string uni)
        : Teacher(id, sub), Researcher(area, pub) {
        university = uni;
    }

    void display() {
        Teacher::display();
        Researcher::display();
        cout << "University: " << university << endl;
    }

    /*
    Constructor call order:
    In multiple inheritance, base class constructors are called in the order
    they are inherited in the class declaration. Here, Teacher is called first,
    then Researcher, and finally Professor constructor is executed.
    */
};

int main() {
    Professor p1(101, "OOP", "Artificial Intelligence", 5, "HCOE");

    cout << "Professor Details:" << endl;
    p1.display();

    return 0;
}