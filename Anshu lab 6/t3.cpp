#include <iostream>
using namespace std;

class Teacher
{
protected:
    int teacherID;
    string subject;

public:
    Teacher(int id, string sub)
    {
        teacherID = id;
        subject = sub;
    }

    void display()
    {
        cout << "Teacher ID: " << teacherID << endl;
        cout << "Subject: " << subject << endl;
    }
};

class Researcher
{
protected:
    string researchArea;
    int publications;

public:
    Researcher(string area, int pub)
    {
        researchArea = area;
        publications = pub;
    }

    void display()
    {
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

class Professor : public Teacher, public Researcher
{
private:
    string university;

public:
    Professor(int id, string sub, string area, int pub, string uni)
        : Teacher(id, sub), Researcher(area, pub)
    {
        university = uni;
    }

    void display()
    {
        cout << "Teacher ID: " << teacherID << endl;
        cout << "Subject: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
        cout << "University: " << university << endl;
    }
};

int main()
{
    Professor p(101, "OOP", "Artificial Intelligence", 25, "Tribhuvan University");

    p.display();

    return 0;
}