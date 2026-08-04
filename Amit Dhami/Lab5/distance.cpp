
#include<iostream>
using namespace std;
class Distance{
private:
    int feet;
    float inches;

    void normal(){
     while (inches >= 12)
        {
            feet++;
            inches -= 12;

        }}
public:
    Distance(float f=0,float i=0){
    feet =f;
    inches =i;
    normal();
    }

   Distance operator-()
   {

       return Distance(-feet,-inches);
       }
Distance operator++(){
inches ++;
normal();
return *this;
}

    Distance operator++(int)
    {
        Distance temp = *this;
        inches++;
        normal();
        return temp;
    }
        friend Distance operator*(const Distance &d, int n);

    friend Distance operator*(int n, const Distance &d);

    friend ostream &operator<<(ostream &out, const Distance &d);
};

   Distance operator*(const Distance &d, int n)
{

    float total = (d.feet * 12 + d.inches) * n;
    int f = total / 12;
    float i = total - f * 12;
    return Distance(f, i);

}

Distance operator*(int n, const Distance &d)
{
    return d * n;
}

ostream &operator<<(ostream &out, const Distance &d)
{
    out << d.feet << " ft " << d.inches << " in";

    return out;
}

int main()
{
    Distance d1(5, 8), d2;

    cout << "Original: " << d1 << endl;

    d2 = -d1;
    cout << "Negation: " << d2 << endl;

    cout << "Prefix ++ : " << ++d1 << endl;

    cout << "Postfix ++ : " << d1++ << endl;
    cout << "After Postfix: " << d1 << endl;

    cout << "Distance * 3 = " << d1 * 3 << endl;
    cout << "3 * Distance = " << 3 * d1 << endl;

    return 0;
}

