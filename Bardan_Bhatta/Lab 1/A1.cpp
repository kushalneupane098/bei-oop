#include<iostream>
using namespace std;
void swap(int &a, int &b){
	a = a + b;
	b = a - b;
	a = a - b;
}
int main()
{
	int a, b;
	cout<<"Enter the first number: ";
	cin>>a;
	cout<<"Enter the second number: ";
	cin>>b;
	cout<<"Before swap: a = "<<a<<", b = "<<b<< endl;
	swap(a, b);
	cout<<"After swap: a = "<<a<< ", b = "<<b<< endl;	
	return 0;
	 
	
}
