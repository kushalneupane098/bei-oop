#include<iostream>
using namespace std;
int perimeter(int length, int breadth)
{
	float P;
	P = 2 * ( length + breadth );
	return P;
}
int area(int length, int breadth)
{
	float A;
	A = length * breadth;
	return A;
}
int main()
{
	int length, breadth;
	cout<<"Enter the length of rectangle: ";
	cin>>length;
	cout<<"Enter the breadth of rectangle: ";
	cin>>breadth;
	cout<<" Perimeter = "<<perimeter(length, breadth)<<endl;
	cout<<" Area = "<<area(length, breadth)<<endl;
	return 0;

}
