#include<iostream>
#include<string>
using namespace std;
class Teacher{
    private:
    int teacherId;
    string subject;
    public:
    Teacher(int id,string sub)
    {
        teacherId=id;
        subject=sub;
    }
    void display()
    {
        cout<<"Teacher ID: "<<teacherId<<endl;
        cout<<"Subject: "<<subject<<endl;
    }
    int getTeacherId()
    {
        return teacherId;
    }
    string getSubject()
    {
        return subject;
    }
};
class Researcher {
    private:
    string researchArea;
    int publications;
    public:
    Researcher(string area,int pub)
    {
        researchArea=area;
        publications=pub;
    }
    void display()
    {
        cout<<"Research Area: "<<researchArea<<endl;
        cout<<"Number of Publications: "<<publications<<endl;
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
class Professor:public Researcher , public Teacher{
    private:
    string memberUniversity;
    public:
    Professor(int id,string sub,string area,int num,string dep):Teacher(id,sub),Researcher(area,num)
    {
        memberUniversity=dep;
    }
    void display()
    {
        cout<<"University: "<<memberUniversity<<endl;
        cout << "Research Area: " << getResearchArea() << endl;
        cout << "Number of Publications: " << getPublications() << endl;
        cout << "Teacher ID: " << getTeacherId() << endl;
        cout << "Subject: " << getSubject() << endl;
    }
};
int main()
{
    Professor p1(101,"Computer Science",5,"Engineering");
    p1.display();
    Researcher r1("Artificial Intelligence", 3);
    r1.display();
    Teacher t1(103,"Physics");
    t1.display();
}