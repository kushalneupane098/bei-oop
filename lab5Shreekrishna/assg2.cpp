#include <iostream>
#include <cmath>
using namespace std;

class Fraction
{
    int numerator, denominator;

    void reduce()
    {
        int a=abs(numerator);
        int b=abs(denominator);

        while(b!=0)
        {
            int t=b;
            b=a%b;
            a=t;
        }

        numerator/=a;
        denominator/=a;
    }

public:
    Fraction(int n=0,int d=1)
    {
        numerator=n;
        denominator=d;
        reduce();
    }

    Fraction(double x)
    {
        denominator=1000;
        numerator=round(x*1000);
        reduce();
    }

    operator double() const
    {
        return (double)numerator/denominator;
    }

    friend Fraction operator+(Fraction a,Fraction b)
    {
        return Fraction(a.numerator*b.denominator+b.numerator*a.denominator,
                        a.denominator*b.denominator);
    }

    friend Fraction operator-(Fraction a,Fraction b)
    {
        return Fraction(a.numerator*b.denominator-b.numerator*a.denominator,
                        a.denominator*b.denominator);
    }

    friend Fraction operator*(Fraction a,Fraction b)
    {
        return Fraction(a.numerator*b.numerator,
                        a.denominator*b.denominator);
    }

    friend Fraction operator/(Fraction a,Fraction b)
    {
        return Fraction(a.numerator*b.denominator,
                        a.denominator*b.numerator);
    }

    friend bool operator<(Fraction a,Fraction b)
    {
        return a.numerator*b.denominator<b.numerator*a.denominator;
    }

    friend bool operator>(Fraction a,Fraction b)
    {
        return a.numerator*b.denominator>b.numerator*a.denominator;
    }

    friend bool operator==(Fraction a,Fraction b)
    {
        return a.numerator==b.numerator &&
               a.denominator==b.denominator;
    }

    friend istream& operator>>(istream &in,Fraction &f)
    {
        char ch;
        in>>f.numerator>>ch>>f.denominator;
        f.reduce();
        return in;
    }

    friend ostream& operator<<(ostream &out,const Fraction &f)
    {
        out<<f.numerator<<"/"<<f.denominator;
        return out;
    }
};

int main()
{
    Fraction f1,f2;

    cout<<"Enter first fraction: ";
    cin>>f1;

    cout<<"Enter second fraction: ";
    cin>>f2;

    cout<<"\nAddition = "<<f1+f2;
    cout<<"\nSubtraction = "<<f1-f2;
    cout<<"\nMultiplication = "<<f1*f2;
    cout<<"\nDivision = "<<f1/f2;

    cout<<"\nf1 < f2 = "<<(f1<f2);
    cout<<"\nf1 > f2 = "<<(f1>f2);
    cout<<"\nf1 == f2 = "<<(f1==f2);

    double d=f1;
    cout<<"\nDecimal value = "<<d;

    Fraction f3=3.14;
    cout<<"\nFraction from double = "<<f3;

    return 0;
}