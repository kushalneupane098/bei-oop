#include <iostream>
#include <cmath>
using namespace std;

class Vector3D
{
    float x,y,z;

public:
    Vector3D(float a=0)
    {
        x=y=z=a;
    }

    Vector3D operator+(Vector3D v)
    {
        Vector3D t;
        t.x=x+v.x;
        t.y=y+v.y;
        t.z=z+v.z;
        return t;
    }

    Vector3D operator-(Vector3D v)
    {
        Vector3D t;
        t.x=x-v.x;
        t.y=y-v.y;
        t.z=z-v.z;
        return t;
    }

    Vector3D operator-()
    {
        Vector3D t;
        t.x=-x;
        t.y=-y;
        t.z=-z;
        return t;
    }

    friend float operator*(Vector3D a,Vector3D b)
    {
        return a.x*b.x+a.y*b.y+a.z*b.z;
    }

    friend Vector3D operator*(Vector3D v,float s)
    {
        Vector3D t;
        t.x=v.x*s;
        t.y=v.y*s;
        t.z=v.z*s;
        return t;
    }

    friend Vector3D operator*(float s,Vector3D v)
    {
        return v*s;
    }

    operator float() const
    {
        return sqrt(x*x+y*y+z*z);
    }

    friend istream& operator>>(istream &in,Vector3D &v)
    {
        in>>v.x>>v.y>>v.z;
        return in;
    }

    friend ostream& operator<<(ostream &out,const Vector3D &v)
    {
        out<<"("<<v.x<<","<<v.y<<","<<v.z<<")";
        return out;
    }
};

int main()
{
    Vector3D v1,v2;

    cout<<"Enter v1: ";
    cin>>v1;

    cout<<"Enter v2: ";
    cin>>v2;

    cout<<"\nv1 + v2 = "<<v1+v2;
    cout<<"\nv1 - v2 = "<<v1-v2;

    cout<<"\nDot Product = "<<v1*v2;

    cout<<"\nv1 * 2 = "<<v1*2.0f;
    cout<<"\n3 * v2 = "<<3.0f*v2;

    cout<<"\n-v1 = "<<-v1;

    float m=v1;
    cout<<"\nMagnitude = "<<m;

    Vector3D v3=5;
    cout<<"\nVector from float = "<<v3;

    return 0;
}