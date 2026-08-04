#include <iostream>
#include <string>
using namespace std;
class Teacher {
private:
    string name;
    int researchArea;
public:
    Teacher(string n, int r) {
        name = n;
        researchArea = r;
    }
    void displayTeacher() {
        cout << "Name: " << name << endl;
        cout << "Research Area: " << researchArea << endl;
    }
};
class Researcher {
private:
    string researchField;
public:
    Researcher(string rf) {
        researchField = rf;
    }
    void displayResearcher() {
        cout << "Research Field: " << researchField << endl;
    }
};
class Professor : public Teacher, public Researcher {
private:
    string university;
public:
    Professor(string n, int r, string rf, string u)
        : Teacher(n, r), Researcher(rf) {
        university = u;
    }
    void display() {
        displayTeacher();
        displayResearcher();
        cout << "University: " << university << endl;
    }
};
int main() {
    Professor p("Bissesh", 101, "OOP", "Tribhuvan University");
    p.display();
    return 0;
}
