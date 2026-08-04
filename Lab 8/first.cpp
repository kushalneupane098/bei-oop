#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
class converter{
public:
    void copyandconvert(){
        std::ifstream fin("source.txt");
        std::ofstream fout("destination.txt");
        char ch;
        if(!fin){
            cout<<"File not created"<<endl;
            return;
        }
        while(fin.get(ch)){
            if(islower((unsigned char)ch)){
                ch = (char)toupper((unsigned char)ch);
            }
            fout.put(ch);
        }
        cout<<"File Copied Successfully"<<endl;
        fin.close();
        fout.close();
    }

};
int main(){
    converter obj;
    obj.copyandconvert();
    return 0;
}