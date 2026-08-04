#include <iostream>
using namespace std;

class Fraction
{
private:
    int num, den;

    void reduce()
    {
        int a=num,b=den;

        while(b)
        {
            int t=a%b;
            a=b;
            b=t;
        }

        num/=a;
        den/=a;
    }

public:
    Fraction(int n=0,int d=1)
    {
        num=n;
        den=d;
        reduce();
    }

    Fraction(double x)
    {
        den=1000;
        num=x*1000;
        reduce();
    }

    operator double() const
    {
        return (double)num/den;
    }

    friend Fraction operator+(Fraction,Fraction);
    friend Fraction operator-(Fraction,Fraction);
    friend Fraction operator*(Fraction,Fraction);
    friend Fraction operator/(Fraction,Fraction);

    friend bool operator<(Fraction,Fraction);
    friend bool operator>(Fraction,Fraction);
    friend bool operator==(Fraction,Fraction);

    friend ostream& operator<<(ostream&,Fraction);
    friend istream& operator>>(istream&,Fraction&);
};

Fraction operator+(Fraction a,Fraction b)
{
    return Fraction(a.num*b.den+b.num*a.den,a.den*b.den);
}

Fraction operator-(Fraction a,Fraction b)
{
    return Fraction(a.num*b.den-b.num*a.den,a.den*b.den);
}

Fraction operator*(Fraction a,Fraction b)
{
    return Fraction(a.num*b.num,a.den*b.den);
}

Fraction operator/(Fraction a,Fraction b)
{
    return Fraction(a.num*b.den,a.den*b.num);
}

bool operator<(Fraction a,Fraction b)
{
    return a.num*b.den < b.num*a.den;
}

bool operator>(Fraction a,Fraction b)
{
    return a.num*b.den > b.num*a.den;
}

bool operator==(Fraction a,Fraction b)
{
    return a.num==b.num && a.den==b.den;
}

ostream& operator<<(ostream& out,Fraction f)
{
    out<<f.num<<"/"<<f.den;
    return out;
}

istream& operator>>(istream& in,Fraction& f)
{
    char ch;
    in>>f.num>>ch>>f.den;
    f.reduce();
    return in;
}

int main()
{
    Fraction f1(1,2),f2(3,4);

    cout<<f1+f2<<endl;
    cout<<f1-f2<<endl;
    cout<<f1*f2<<endl;
    cout<<f1/f2<<endl;

    return 0;
}