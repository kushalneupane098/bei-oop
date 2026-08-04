#include<iostream>
using namespace std;
class Temp {
    private:
        float cel;
    public:
        Temp(float c) 
		{
            cel = c;
        }
        void setTemp(float c) 
		{
            cel = c;
        }
        float toF() const 
		{
            return (cel * 9 / 5) + 32;
        }
        float toK() const {
            return cel + 273.15;
        }
        void show() const 
		{
            cout<<"Celsius:"<<cel<<endl;
            cout<<"Fahrenheit:"<<toF()<<endl;
            cout<<"Kelvin:"<<toK()<<endl;
        }
        friend bool areEqual(Temp t1, Temp t2);
};
bool areEqual(Temp t1, Temp t2) 
{
    return t1.cel == t2.cel;
}
int main() {
    Temp t1(25);
    Temp t2(25);
    cout<<"Temperature 1"<<endl;
    t1.show();
    cout<<"\nTemperature 2"<<endl;
    t2.show();
    if(areEqual(t1, t2))
        cout<<"\nBoth temperatures are equal"<<endl;
    else
        cout<<"\nTemperatures are not equal"<<endl;
    t2.setTemp(30);
    cout<<"\nTemperature 2 after change"<<endl;
    t2.show();
    if(areEqual(t1, t2))
        cout<<"\nBoth temperatures are equal"<<endl;
    else
        cout<<"\nTemperatures are not equal"<<endl;
    return 0;
}
