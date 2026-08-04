#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char ch;

    while(fin.get(ch))
    {
        fout.put(toupper(ch));
    }

    fin.close();
    fout.close();

    cout<<"File copied successfully.";
    return 0;
}