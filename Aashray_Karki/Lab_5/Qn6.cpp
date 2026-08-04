/*
Assignment 3:
Write a program with a class Vector3D having private float members x, y,
and z. Overload the binary + and - operators as member functions. Use the
dot product using operator * as a friend function returning float, and
scalar multiplication as friend functions for both Vector3D * float and
float * Vector3D. Overload the unary - as a member function. Overload <<
and >>. Add a conversion operator operator float() const that returns the
magnitude of the vector using sqrt(x*x + y*y + z*z), and a conversion
constructor Vector3D(float) that initializes all three components to the
given value. Demonstrate all operations in main.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Vector3D {
private:
    float x;
    float y;
    float z;

public:
    Vector3D(float value = 0) {
        x = value;
        y = value;
        z = value;
    }

    Vector3D(float xValue, float yValue, float zValue) {
        x = xValue;
        y = yValue;
        z = zValue;
    }

    Vector3D operator+(const Vector3D& v) const {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    Vector3D operator-(const Vector3D& v) const {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }

    Vector3D operator-() const {
        return Vector3D(-x, -y, -z);
    }

    operator float() const {
        return sqrt(x * x + y * y + z * z);
    }

    friend float operator*(const Vector3D& v1, const Vector3D& v2);

    friend Vector3D operator*(const Vector3D& v, float scalar);
    friend Vector3D operator*(float scalar, const Vector3D& v);

    friend istream& operator>>(istream& input, Vector3D& v);
    friend ostream& operator<<(ostream& output, const Vector3D& v);
};

float operator*(const Vector3D& v1, const Vector3D& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3D operator*(const Vector3D& v, float scalar) {
    return Vector3D(
        v.x * scalar,
        v.y * scalar,
        v.z * scalar
    );
}

Vector3D operator*(float scalar, const Vector3D& v) {
    return v * scalar;
}

istream& operator>>(istream& input, Vector3D& v) {
    input >> v.x >> v.y >> v.z;
    return input;
}

ostream& operator<<(ostream& output, const Vector3D& v) {
    output << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return output;
}

int main() {
    Vector3D v1, v2;

    cout << "Enter x, y and z components of Vector 1: ";
    cin >> v1;

    cout << "Enter x, y and z components of Vector 2: ";
    cin >> v2;

    cout << "\nVector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;

    cout << "Vector Addition: " << v1 + v2 << endl;
    cout << "Vector Subtraction: " << v1 - v2 << endl;
    cout << "Negative of Vector 1: " << -v1 << endl;

    float dotProduct = v1 * v2;
    cout << "Dot Product: " << dotProduct << endl;

    cout << "Vector 1 * 2: " << v1 * 2.0f << endl;
    cout << "3 * Vector 2: " << 3.0f * v2 << endl;

    float magnitude = static_cast<float>(v1);
    cout << "Magnitude of Vector 1: " << magnitude << endl;

    Vector3D equalComponents = 5.0f;
    cout << "Vector Created from Float 5: "
         << equalComponents << endl;

    return 0;
}