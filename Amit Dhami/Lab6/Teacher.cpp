#include <iostream>
using namespace std;

class Teacher
{
private:
    int teacherID;
    string subject;

public:
    Teacher(int id, string sub)
    {
        teacherID = id;
        subject = sub;
    }

    int getTeacherID()
    {
        return teacherID;
    }

    string getSubject()
    {
        return subject;
    }
};

class Researcher
{
private:
    string researchArea;
    int publications;

public:
    Researcher(string area, int pub)
    {
        researchArea = area;
        publications = pub;
    }

    string getResearchArea()
    {
        return researchArea;
    }

    int getPublications()
    {
        return publications;
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
        cout << "Teacher ID: " << getTeacherID() << endl;
        cout << "Subject: " << getSubject() << endl;
        cout << "Research Area: " << getResearchArea() << endl;
        cout << "Publications: " << getPublications() << endl;
        cout << "University: " << university << endl;
    }
};

int main()
{
    Professor p(4, "OOP", "Inheritance", 30, "Tribhuvan University");

    p.display();

    return 0;
}
