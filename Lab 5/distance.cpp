#include<iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance(int f=0,float i=0)
    {
        feet=f;
        inches=i;
    }

    Distance operator-()
    {
        return Distance(-feet,-inches);
    }

    Distance operator++()
    {
        inches++;

        if(inches>=12)
        {
            feet++;
            inches=0;
        }

        return *this;
    }

    Distance operator++(int)
    {
        Distance temp=*this;

        inches++;

        if(inches>=12)
        {
            feet++;
            inches=0;
        }

        return temp;
    }

    friend Distance operator*(Distance d,int n);
    friend Distance operator*(int n,Distance d);

    void display()
    {
        cout<<feet<<" feet "<<inches<<" inches"<<endl;
    }
};

Distance operator*(Distance d,int n)
{
    return Distance(d.feet*n,d.inches*n);
}

Distance operator*(int n,Distance d)
{
    return Distance(d.feet*n,d.inches*n);
}

int main()
{
    Distance d1(5,10),d2;

    cout<<"Original : ";
    d1.display();

    d2=-d1;
    cout<<"Negation : ";
    d2.display();

    ++d1;
    cout<<"Prefix ++ : ";
    d1.display();

    d1++;
    cout<<"Postfix ++ : ";
    d1.display();

    d2=d1*2;
    cout<<"Distance * 2 : ";
    d2.display();

    d2=3*d1;
    cout<<"3 * Distance : ";
    d2.display();

    return 0;
}