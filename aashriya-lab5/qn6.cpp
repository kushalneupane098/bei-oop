#include <iostream>
#include <cmath>
using namespace std;

class Vector3D
{
private:
    float x,y,z;

public:
    Vector3D(float v=0)
    {
        x=y=z=v;
    }

    Vector3D(float a,float b,float c)
    {
        x=a;
        y=b;
        z=c;
    }

    Vector3D operator+(Vector3D v)
    {
        return Vector3D(x+v.x,y+v.y,z+v.z);
    }

    Vector3D operator-(Vector3D v)
    {
        return Vector3D(x-v.x,y-v.y,z-v.z);
    }

    Vector3D operator-()
    {
        return Vector3D(-x,-y,-z);
    }

    operator float() const
    {
        return sqrt(x*x+y*y+z*z);
    }

    friend float operator*(Vector3D,Vector3D);

    friend Vector3D operator*(Vector3D,float);
    friend Vector3D operator*(float,Vector3D);

    friend ostream& operator<<(ostream&,Vector3D);
    friend istream& operator>>(istream&,Vector3D&);
};

float operator*(Vector3D a,Vector3D b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

Vector3D operator*(Vector3D v,float s)
{
    return Vector3D(v.x*s,v.y*s,v.z*s);
}

Vector3D operator*(float s,Vector3D v)
{
    return v*s;
}

ostream& operator<<(ostream& out,Vector3D v)
{
    out<<"("<<v.x<<","<<v.y<<","<<v.z<<")";
    return out;
}

istream& operator>>(istream& in,Vector3D& v)
{
    in>>v.x>>v.y>>v.z;
    return in;
}

int main()
{
    Vector3D v1(1,2,3), v2(4,5,6);

    cout<<"Sum = "<<v1+v2<<endl;
    cout<<"Difference = "<<v1-v2<<endl;
    cout<<"Dot Product = "<<v1*v2<<endl;
    cout<<"Scalar Multiply = "<<v1*2<<endl;

    float mag=v1;
    cout<<"Magnitude = "<<mag<<endl;

    return 0;
}