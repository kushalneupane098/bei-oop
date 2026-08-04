#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    int teacherID;
    string subject;

public:
    Teacher(int teacherID, string subject) : teacherID(teacherID), subject(subject) {}

    void display() const {
        cout << "Teacher ID : " << teacherID << endl;
        cout << "Subject    : " << subject << endl;
    }
};

class Researcher {
private:
    string researchArea;
    int publications;

public:
    Researcher(string researchArea, int publications) : researchArea(researchArea), publications(publications) {}

    void display() const {
        cout << "Research   : " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    string university;

public:
    Professor(int teacherID, string subject, string researchArea, int publications, string university)
        : Teacher(teacherID, subject), Researcher(researchArea, publications), university(university) {}

    void display() const {
        Teacher::display();
        Researcher::display();
        cout << "University : " << university << endl;
    }
};

int main() {
    Professor p(101, "Mathematics", "Quantum Computing", 35, "Tribhuvan University");

    cout << "--- Professor ---" << endl;
    p.display();

    return 0;
}
