#include <iostream>
using namespace std;
class Complex{
    float real;
    float imag;
public:
    
    Complex(int r=0, int i=0):real(r),imag(i){}
    friend istream& operator>>(istream& in, Complex& obj){
        in >> obj.real >> obj.imag;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Complex& obj){
        out << "(" << obj.real << " + " << obj.imag << "i)";
        return out;
    }
    friend bool operator==(const Complex& a, const Complex& b){
        return a.real == b.real && a.imag == b.imag;
    }
    Complex operator +(Complex obj){
        Complex temp;
        temp.real = real+obj.real;
        temp.imag = imag+obj.imag;
        return temp;
    }
    Complex operator -(Complex obj){
        Complex temp;
        temp.real = real-obj.real;
        temp.imag = imag-obj.imag;
        return temp;
    }
    void display(){
        cout << *this << endl;
    }
};
int main(){
    Complex c1(3,4);
    Complex c2(4,5);
    Complex c3 = c1+c2;
    Complex c4 = c1-c2;
    Complex c5;
    cout << "Enter a complex number (real imag): ";
    cin >> c5;
    char choice;
    cout<<"Do you wanna add or subtract?(+,-) ";
    cin>>choice;
    if(choice=='+'){
        cout << c3 << endl;
    }
    else if(choice == '-'){
        cout << c4 << endl;
    }
    else{
        cout<<"Enter a valid choice"<<endl;
    }
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c5 = " << c5 << endl;
    if(c1 == c2){
        cout << "c1 and c2 are equal" << endl;
    }
    else{
        cout << "c1 and c2 are not equal" << endl;
    }
    

    return 0;
}