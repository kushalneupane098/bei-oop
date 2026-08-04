#include <iostream>
#include <cmath>
using namespace std;

class Vector3D {
private:
    float x, y, z;

public:
    Vector3D(float a=0,float b=0,float c=0){
        x=a;y=b;z=c;
    }

    Vector3D operator+(Vector3D v){
        return Vector3D(x+v.x,y+v.y,z+v.z);
    }

    Vector3D operator-(Vector3D v){
        return Vector3D(x-v.x,y-v.y,z-v.z);
    }

    float operator*(Vector3D v){
        return x*v.x + y*v.y + z*v.z;
    }

    friend Vector3D operator*(float s, Vector3D v){
        return Vector3D(v.x*s, v.y*s, v.z*s);
    }

    friend ostream& operator<<(ostream &out, Vector3D v){
        out<<"("<<v.x<<","<<v.y<<","<<v.z<<")";
        return out;
    }

    float magnitude(){
        return sqrt(x*x+y*y+z*z);
    }
};

int main(){
    Vector3D v1(1,2,3), v2(4,5,6);

    cout << v1 + v2 << endl;
    cout << v1 - v2 << endl;
    cout << v1 * v2 << endl;
    cout << 2 * v1 << endl;
    cout << v1.magnitude() << endl;
}