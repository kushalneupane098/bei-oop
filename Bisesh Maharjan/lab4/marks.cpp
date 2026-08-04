#include<iostream>
using namespace std;
class Maths;
class Physics {
    private:
        int p;
    public:
        Physics(int x) {
            p = x;
        }
        friend int total(Physics, Maths);
        friend bool distinction(Physics, Maths);
};
class Maths {
    private:
        int m;
    public:
        Maths(int x) {
            m = x;
        }
        friend int total(Physics, Maths);
        friend bool distinction(Physics, Maths);
};

int total(Physics a, Maths b) {
    return a.p + b.m;
}
bool distinction(Physics a, Maths b) {
    return total(a, b) >= 160;
}
int main() {
    int p, m;
    cout<<"Enter Physics marks:";
    cin>>p;
    cout<<"Enter Maths marks:";
    cin>>m;
    Physics a(p);
    Maths b(m);
    cout<<"Total Marks:"<<total(a, b)<<endl;
    if(distinction(a, b))
        cout<<"Result:Distinction"<<endl;
    else
        cout<<"Result:No Distinction"<<endl;
    return 0;
}
