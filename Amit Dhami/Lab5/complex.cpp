#include<iostream>
using namespace std;
class Complex{
private:
    float real,img;
public:
    Complex(float r=0,float i=0){
    real=r;
    img =i;
    }
    Complex operator+(const Complex &c){
   return Complex(real+c.real, img+c.img); }

   Complex operator-(const Complex &c)
   {
       return Complex(real-c.real, img-c.img);
       }

    friend bool operator==(const Complex &c1,const Complex &c2);
    friend istream &operator>>(istream &in, Complex &c);

friend ostream &operator<<(ostream &out, const Complex &c);
    };


   bool operator==( const Complex &c1,const Complex &c2){
   return c1.real==c2.real && c1.img==c2.img;
   }

   istream &operator>>(istream &in,Complex &c){
   in>>c.real>>c.img;
   return in;
   }

    ostream &operator<<(ostream &out,const Complex &c){
   out << "(" << c.real << " + " << c.img << "i)";
   return out;
   }

   int main(){
   Complex c1,c2, sum,diff;

cout<<"1st complex(real img):";
cin>>c1;

cout<<"2nd complex(real img):";
cin>>c2;

sum=c1+c2;

diff=c1-c2;

cout<<"sum="<<sum<<endl;

cout<<"difference="<<diff<<endl;

return 0;
}

