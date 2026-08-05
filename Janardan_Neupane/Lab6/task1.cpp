#include<iostream>
#include<string>
using namespace std;
class Person
{
    private:
        string name;
        int age;
    public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
    
void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    int getAge()
    {
        return age;
    }
    string getName()
    {
        return name;
    }
};
class Student :public Person{
    private:
    int rollNo;
    float gpa;
    public:
    Student(int r , float g,int a,string n):Person(n,a)
    { 
        rollNo = r; 
        gpa = g; 
    }
void display()
{
    cout<<"Roll No: "<<rollNo<<endl;
    cout<<"GPA: "<<gpa<<endl;
    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
}
};
void main()
{
    Student s1(101, 3.5, 20, "John Doe");
    s1.display();
    Person p1("Jane Smith", 25);
    p1.display();
}