#include<iostream>
#include<fstream>
using namespace std;

class Student
{
public:
    int roll;
    char name[20];
    float marks;
};

int main()
{
    Student s;

    ofstream fout("student.dat",ios::binary);

    for(int i=0;i<5;i++)
    {
        cout<<"Enter Roll Name Marks: ";
        cin>>s.roll>>s.name>>s.marks;

        fout.write((char*)&s,sizeof(s));
    }

    fout.close();

    int r;
    cout<<"Enter Roll to Modify: ";
    cin>>r;

    fstream file("student.dat",ios::binary|ios::in|ios::out);

    while(file.read((char*)&s,sizeof(s)))
    {
        if(s.roll==r)
        {
            cout<<"Enter New Name and Marks: ";
            cin>>s.name>>s.marks;

            file.seekp(-sizeof(s),ios::cur);
            file.write((char*)&s,sizeof(s));
            break;
        }
    }

    file.clear();
    file.seekg(0);

    cout<<"\nStudent Records\n";

    while(file.read((char*)&s,sizeof(s)))
    {
        cout<<s.roll<<" "<<s.name<<" "<<s.marks<<endl;
    }

    file.close();

    return 0;
}