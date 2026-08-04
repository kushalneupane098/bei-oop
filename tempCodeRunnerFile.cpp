#include <iostream>
#include <fstream>
using namespace std;
class student{
    string name;
    int rollno;
public:
    void read_data(){
        cout<<"Enter the name: ";
        cin>>name;
        cout<<"Enter the roll no: ";
        cin>>rollno;
    }
    void display_data(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<rollno<<endl;
    }
};
int main(){
    student s;
    ofstream outfile("students.dat", ios::binary);
    for(int i = 0;i<10;i++){
    s.read_data();
    outfile.write(reinterpret_cast<char*>(&s),sizeof(s));
    }
    outfile.close();
    ifstream infile("students.dat",ios::binary);
    if(!infile){
        cout<<"Not found"<<endl;
        return 1;
    }
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(s))){
    s.display_data();
    }
    fstream file("students.dat",ios::binary| ios::in|ios::out);
    while(file.read(reinterpret_cast<char*>(&s),sizeof(s))){
        int pos = tellg();
        s.read_data();
        file.seekp(pos-sizeof(s));
        file.write(reinterpret_cast<char*>(&s),sizeof(s));
        
    }
    return 0;
}