#include<iostream>
using namespace std;
class Box{
  private:
      float l,h,b;
  public:
    Box(){
      l=0;b=0;h=0;
      cout<<"Default argument called \n";
    }
    
   Box(float x,float y=2.0,float z=9.0){
    l=x;
    b=y;
    h=z;
    cout<<"Default argument constructor called \n";
   }
   Box(const Box& obj){
    l=obj.l;
    b=obj.b;
    h=obj.h;
    cout<<"Copy constructor called\n";
   }
  ~Box(){
    cout<<"Destructor called\n";
  }

};
int main() {
    Box b1;                   
    Box b2(1.0, 2.0, 3.0);  
    Box b3(5.0);             
    Box b4(b2);             
    return 0;
}

