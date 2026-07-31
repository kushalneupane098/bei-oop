#include <iostream>
using namespace std;
template <class T>
T max3(T a, T b, T c){
    if(a>b&&a>c){
        return a;
    }
    else if(b>a&&b>c){
        return b;
    }
    else{
        return c;
    }
};
int main(){
    int a,b,c;
    char p,q,r;
    double m,n,o;
    cout<<"Enter the three numbers(int): ";
    cin>>a>>b>>c;
    cout<<"The maximum of those numbers is "<<max3(a,b,c)<<endl;
    cout<<"Enter the three characters(char): ";
    cin>>p>>q>>r;
    cout<<"The maximum of those characters is "<<max3(p,q,r)<<endl;
    cout<<"Enter the three numbers(double): ";
    cin>>m>>n>>o;
    cout<<"The maximum of those numbers is "<<max3(m,n,o)<<endl;
    return 0;
}