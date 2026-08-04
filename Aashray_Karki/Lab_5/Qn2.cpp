/*
Question 2:
Write a program with a class Distance having private members feet (int)
and inches (float). Overload the unary negation operator (-) as a member
function that returns a Distance with both components negated. Overload
the prefix and postfix ++ operators as member functions that add one inch
to the distance, converting to feet when inches reaches 12. Overload the
binary * operator as a friend function that multiplies a Distance by a
scalar integer for both Distance * int and int * Distance. Demonstrate all
operators in main with clear output.
*/

#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

    void normalize() {
        float totalInches = feet * 12 + inches;
        feet = static_cast<int>(totalInches / 12);
        inches = totalInches - feet * 12;
    }

public:
    Distance(int f = 0, float i = 0) {
        feet = f;
        inches = i;
        normalize();
    }

    Distance operator-() const {
        return Distance(-feet, -inches);
    }

    // Prefix increment
    Distance& operator++() {
        inches++;
        normalize();
        return *this;
    }

    // Postfix increment
    Distance operator++(int) {
        Distance oldValue = *this;
        inches++;
        normalize();
        return oldValue;
    }

    friend Distance operator*(const Distance& d, int scalar);
    friend Distance operator*(int scalar, const Distance& d);

    void display() const {
        cout << feet << " feet " << inches << " inches";
    }
};

Distance operator*(const Distance& d, int scalar) {
    float totalInches = (d.feet * 12 + d.inches) * scalar;
    return Distance(0, totalInches);
}

Distance operator*(int scalar, const Distance& d) {
    return d * scalar;
}

int main() {
    Distance d1(5, 11);

    cout << "Original Distance: ";
    d1.display();

    Distance negative = -d1;
    cout << "\nNegated Distance: ";
    negative.display();

    cout << "\n\nAfter Prefix Increment: ";
    (++d1).display();

    cout << "\nValue Returned by Postfix Increment: ";
    (d1++).display();

    cout << "\nDistance After Postfix Increment: ";
    d1.display();

    Distance d2 = d1 * 2;
    cout << "\n\nDistance * 2: ";
    d2.display();

    Distance d3 = 3 * d1;
    cout << "\n3 * Distance: ";
    d3.display();

    cout << endl;
    return 0;
}