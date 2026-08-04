#include <iostream>
using namespace std;
class Distance{
    int feet;
    float inches;
public:
    Distance():feet(0), inches(0.0f){}
    Distance(int f, float i):feet(f),inches(i){}
    Distance operator --(){
        feet --;
        inches --;
        return *this;
    }
    Distance operator ++(){
        feet ++;
        inches ++;
        return *this;
    }
    void display(){
        cout<<feet<<" feet "<<inches<<" inches"<<endl;
    }
    
    
    friend Distance operator*(const Distance &d, int scalar);
    friend Distance operator*(int scalar, const Distance &d);
};

Distance operator*(const Distance &d, int scalar){
    
    float totalInches = d.feet * 12 + d.inches;
    totalInches *= scalar;
    int f = static_cast<int>(totalInches) / 12;
    float i = totalInches - f * 12;
    return Distance(f, i);
}

Distance operator*(int scalar, const Distance &d){
    return d * scalar;
}
int main(){
    Distance d(20,10.5f);
    cout<<"Original distance: "; d.display();

    Distance d1 = --d; 
    cout<<"After prefix -- (decrease): "; d1.display();

        Distance d2 = ++d; 
    cout<<"After prefix ++ (increase): "; d2.display();

    
    Distance d3 = d * 2; 
    cout<<"After multiplying by 2 (Distance * int): "; d3.display();

    Distance d4 = 3 * d; 
    cout<<"After multiplying by 3 (int * Distance): "; d4.display();

    
    string choice;
    cout<<"Enter your choice (increase or decrease): ";
    cin>>choice;
    if(choice == "increase"){
        d2.display();
    }
    else if(choice == "decrease"){
        d1.display();
    }
    return 0;
}