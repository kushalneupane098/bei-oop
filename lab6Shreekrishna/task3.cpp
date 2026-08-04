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

    int getID() {
        return teacherID;
    }

    string getSubject() {
        return subject;
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

    string getArea() {
        return researchArea;
    }

    int getPublications() {
        return publications;
    }
};

class Professor : public Teacher, public Researcher {
private:
    string university;

public:
    Professor(int id, string sub, string area,
              int pub, string uni)
        : Teacher(id, sub),
          Researcher(area, pub) {
        university = uni;
    }

    void display() {
        cout << "Teacher ID: " << getID() << endl;
        cout << "Subject: " << getSubject() << endl;
        cout << "Research Area: " << getArea() << endl;
        cout << "Publications: " << getPublications() << endl;
        cout << "University: " << university << endl;
    }
};

int main() {
    Professor p(101, "OOP", "Artificial Intelligence", 25, "TU");

    p.display();

    return 0;
}

