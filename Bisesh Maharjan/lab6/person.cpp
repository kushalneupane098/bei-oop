#include<iostream>
#include<string>
using namespace std;
class Person{
    private:
    string name;
    int age;
    public:
    Person(string n,int a){
        name=n;
        age=a;
    }
    string getname() {
        return name;
    }
    int getage() {
        return age;
    }
    void display() {
        cout<<"Name:"<<name<<endl<<"Age:"<<age<< endl;
    }
};
class student : public Person
{
    private:
    int rollno;
    float gpa;
    public:
    student(string n, int a, int r,float g):Person(n, a){
        rollno=r;
        gpa=g;
    }
    void display() {
        Person::display();
        cout<<"Roll No:"<<rollno <<endl<< "GPA: " << gpa << endl;
    }
};
int main() {
    Person p("Ashray",45);
    p.display();
    student s("Bisesh",20,101,3.8);
    s.display();
    return 0;
}
