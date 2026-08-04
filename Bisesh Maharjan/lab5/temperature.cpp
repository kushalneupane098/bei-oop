#include<iostream>
using namespace std;
class Fahrenheit;
class Celsius
{
    float temp;

public:
    Celsius(float t=0)
    {
        temp=t;
    }

    operator float()
    {
        return temp;
    }

    operator Fahrenheit();

    friend ostream& operator<<(ostream& out,Celsius c)
    {
        out<<c.temp<<" C";
        return out;
    }
};
class Fahrenheit
{
    float temp;

public:
    Fahrenheit(float t=0)
    {
        temp=t;
    }

    friend ostream& operator<<(ostream& out,Fahrenheit f)
    {
        out<<f.temp<<" F";
        return out;
    }
};
Celsius::operator Fahrenheit()
{
    return Fahrenheit(temp*9.0/5.0+32);
}

int main()
{
    Celsius c1=100;
    cout<<"Celsius object:"<<c1<<endl;
    float val=c1;
    cout<<"Float from C1:"<<val<<endl;
    Fahrenheit f1=c1;
    cout<<"C1 to Fahrenheit:"<<f1<<endl;
    Celsius c2(37.5);
    Fahrenheit f2=c2;
    cout<<"37.5 C in F:"<<f2<<endl;
    return 0;
}

