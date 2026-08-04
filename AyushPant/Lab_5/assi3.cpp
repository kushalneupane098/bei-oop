#include<iostream>
#include<cmath>
using namespace std;

class Vector3D {
    float x, y, z;
public:
    Vector3D(float a=0, float b=0, float c=0): x(a), y(b), z(c) {}
    Vector3D operator+(const Vector3D& v) { return Vector3D(x+v.x, y+v.y, z+v.z); }
    Vector3D operator-(const Vector3D& v) { return Vector3D(x-v.x, y-v.y, z-v.z); }
    Vector3D operator-() { return Vector3D(-x, -y, -z); }
    operator float() const { return sqrt(x*x + y*y + z*z); }
    friend float operator*(const Vector3D& a, const Vector3D& b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
    friend Vector3D operator*(const Vector3D& v, float s) { return Vector3D(v.x*s, v.y*s, v.z*s); }
    friend Vector3D operator*(float s, const Vector3D& v) { return Vector3D(v.x*s, v.y*s, v.z*s); }
    friend ostream& operator<<(ostream& os, const Vector3D& v) { os << "(" << v.x << ", " << v.y << ", " << v.z << ")"; return os; }
    friend istream& operator>>(istream& is, Vector3D& v) { is >> v.x >> v.y >> v.z; return is; }
};

int main() {
    Vector3D a(1,2,3), b(4,5,6);
    cout << "a=" << a << " b=" << b << endl;
    cout << "a+b=" << a+b << endl;
    cout << "a-b=" << a-b << endl;
    cout << "-a=" << -a << endl;
    cout << "dot(a,b)=" << (a*b) << endl;
    cout << "a*2=" << a*2.0f << endl;
    cout << "3*b=" << 3.0f*b << endl;
    cout << "|a|=" << float(a) << endl;
    Vector3D c(5.0f, 5.0f, 5.0f);
    cout << "Vector3D(5.0f)=" << c << endl;
    return 0;
}
