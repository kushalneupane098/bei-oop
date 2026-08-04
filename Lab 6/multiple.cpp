#include<iostream>
using namespace std;

class Teacher
{
private:
    int teacherID;
    string subject;

public:
    Teacher(int id,string s)
    {
        teacherID=id;
        subject=s;
    }

    void display()
    {
        cout<<"Teacher ID : "<<teacherID<<endl;
        cout<<"Subject : "<<subject<<endl;
    }
};

class Researcher
{
private:
    string researchArea;
    int publications;

public:
    Researcher(string r,int p)
    {
        researchArea=r;
        publications=p;
    }

    void display()
    {
        cout<<"Research Area : "<<researchArea<<endl;
        cout<<"Publications : "<<publications<<endl;
    }
};

class Professor : public Teacher, public Researcher
{
private:
    string university;

public:
    Professor(int id,string s,string r,int p,string u)
    :Teacher(id,s),Researcher(r,p)
    {
        university=u;
    }

    void display()
    {
        Teacher::display();
        Researcher::display();
        cout<<"University : "<<university<<endl;
    }
};

int main()
{
    Professor p(101,"Computer Science","Artificial Intelligence",20,"ABC University");

    p.display();

    return 0;
}

