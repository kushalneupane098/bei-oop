#include <iostream>
#include <string>

using namespace std;

class Teacher
{
private:
    int teacherID;
    string subject;

public:
    Teacher(int id, string sub) : teacherID(id), subject(sub) {}

    void display() const
    {
        cout << "ID: " << teacherID << ", Subject: " << subject;
    }
};

class Researcher
{
private:
    string researchArea;
    int publications;

public:
    Researcher(string area, int pub) : researchArea(area), publications(pub) {}

    void display() const
    {
        cout << ", Area: " << researchArea << ", Pubs: " << publications;
    }
};

class Professor : public Teacher, public Researcher
{
private:
    string university;

public:
    Professor(int id, string sub, string area, int pub, string uni)
        : Teacher(id, sub), Researcher(area, pub), university(uni) {}

    void display() const
    {
        Teacher::display();
        Researcher::display();
        cout << ", Uni: " << university << endl;
    }
};

int main()
{
    Professor prof(9901, "BEI", "OOP", 14, "TU");
    prof.display();

    return 0;
}