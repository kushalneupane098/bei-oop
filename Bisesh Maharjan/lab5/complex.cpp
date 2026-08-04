#include<iostream>
using namespace std;

class Complex 
{
    float real,imag;
    public:
        Complex(float r=0, float i=0) 
		{
            real=r;
            imag=i;
        }

        Complex operator+(Complex c2) 
		{
            Complex temp;
            temp.real=real+c2.real;
            temp.imag=imag+c2.imag;
            return temp;
        }

        Complex operator-(Complex c2) 
		{
            Complex temp;
            temp.real=real-c2.real;
            temp.imag=imag-c2.imag;
            return temp;
        }

        friend bool operator==(Complex c1, Complex c2);
        friend ostream& operator<<(ostream& out, Complex c);
        friend istream& operator>>(istream& in, Complex& c);
};
bool operator==(Complex c1, Complex c2) 
{	
    if(c1.real==c2.real && c1.imag==c2.imag)
    return true;
    else
    return false;
}
 


ostream& operator<<(ostream& out, Complex c) 
{
    out<<c.real<<"+"<<c.imag<<"i";
    return out;
}

istream& operator>>(istream& in, Complex& c) 
{
    cout<<"Enter real part:";
    in>>c.real;
    cout<<"Enter imag part:";
    in>>c.imag;
    return in;
}

int main() {
    Complex c1, c2;
    cin>>c1;
    cin>>c2;
    cout<<"C1="<<c1<<endl;
    cout<<"C2="<<c2<<endl;
    cout<<"C1+C2="<<c1+c2<<endl;
    cout<<"C1-C2="<<c1-c2<<endl;
    if(c1==c2)
        cout<<"C1 and C2 are equal"<<endl;
    else
        cout<<"C1 and C2 are not equal"<<endl;
    return 0;
}
