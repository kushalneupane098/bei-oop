#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    int teacherID;
    string subject;

public:
    Teacher(int id, string sub) : teacherID(id), subject(sub) {
        cout << "Teacher constructor called (ID: " << teacherID << ")" << endl;
    }

    void display() {
        cout << "Teacher ID: " << teacherID << ", Subject: " << subject << endl;
    }
};

class Researcher {
private:
    string researchArea;
    int publications;

public:
    Researcher(string area, int pubs) : researchArea(area), publications(pubs) {
        cout << "Researcher constructor called (Area: " << researchArea << ")" << endl;
    }

    void display() {
        cout << "Research Area: " << researchArea
             << ", Publications: " << publications << endl;
    }
};

// Multiple inheritance: Professor inherits from Teacher AND Researcher
class Professor : public Teacher, public Researcher {
private:
    string university;

public:
    // Must explicitly call both parent constructors
    Professor(int id, string sub, string area, int pubs, string uni)
        : Teacher(id, sub), Researcher(area, pubs), university(uni) {
        cout << "Professor constructor called (University: " << university << ")" << endl;
    }

    void display() {
        Teacher::display();
        Researcher::display();
        cout << "University: " << university << endl;
    }
};

int main() {
    cout << "--- Creating Professor object ---" << endl;
    Professor prof(501, "Computer Science", "Machine Learning", 42, "MIT");

    cout << "\n--- Displaying Professor details ---" << endl;
    prof.display();

    // Constructor call order explanation:
    // When a Professor object is created, C++ constructs base classes
    // in the ORDER THEY ARE LISTED IN THE CLASS DECLARATION
    // (i.e. "class Professor : public Teacher, public Researcher"),
    // NOT the order they appear in the member initializer list.
    // So Teacher's constructor runs first, then Researcher's constructor,
    // and finally Professor's own constructor body runs last.
    // Destructors run in the exact reverse order: Professor -> Researcher -> Teacher.

    return 0;
}
