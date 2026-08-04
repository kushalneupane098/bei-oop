#include<iostream>
using namespace std;

class Distance
{
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
        Distance temp;
        temp.feet=-feet;
        temp.inches=-inches;
        return temp;
    }

    Distance operator++()
    {
        inches++;
        if(inches>=12)
        {
            inches-=12;
            feet++;
        }
        return *this;
    }

    Distance operator++(int)
    {
        Distance temp=*this;
        inches++;
        if(inches>=12)
        {
            inches-=12;
            feet++;
        }
        return temp;
    }

    friend Distance operator*(Distance d,int n);
    friend Distance operator*(int n,Distance d);
    friend ostream& operator<<(ostream& out,Distance d);
    friend istream& operator>>(istream& in,Distance& d);
};

Distance operator*(Distance d,int n)
{
    float total=(d.feet*12+d.inches)*n;
    int f=(int)(total/12);
    float i=total-f*12;
    return Distance(f,i);
}

Distance operator*(int n,Distance d)
{
    return d*n;
}

ostream& operator<<(ostream& out,Distance d)
{
    out<<d.feet<<"feet "<<d.inches<<"inches";
    return out;
}

istream& operator>>(istream& in,Distance& d)
{
    cout<<"Enter feet:";
    in>>d.feet;
    cout<<"Enter inches:";
    in>>d.inches;
    return in;
}

int main()
{
    Distance d1,d2,d3,d4;
    cin>>d1;
    cout<<"D1="<<d1<<endl;
    d2=-d1;
    cout<<"-D1="<<d2<<endl;
    ++d1;
    cout<<"After ++D1= "<<d1<<endl;
    d1++;
    cout<<"After D1++= "<<d1<<endl;
    d3=d1*3;
    cout<<"D1*3= "<<d3<<endl;
    d4=2*d1;
    cout<<"2*D1= "<<d4<<endl;
    return 0;
}
