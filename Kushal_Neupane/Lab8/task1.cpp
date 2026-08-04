#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    ofstream fin1;
    fin1.open("read.txt");
    fin1 << "hello world";
    fin1.close();
    ifstream fin;
    fin.open("read.txt");
    ofstream fout;
    fout.open("write.txt");
    if(!fin)    {
        cout<<"File not found";
    }
if(!fout )
{
cout<<"error in opening file";
}
    char ch;
    while(!fin.eof())
    {
        fin.get(ch);
        fout.put(toupper(ch));
    }
    fin.close();
    fout.close();
    return 0;
}