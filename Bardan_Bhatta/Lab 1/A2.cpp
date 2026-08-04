#include<iostream>
using namespace std;
int is_prime(int n)
{
 
    if (n==1)
    {
        return 0;
    }
    for (int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
          
            return 1;
        }

        
    } 
    
            return 0;       
    
}
int main()
{
    int n,i,prime=0;
cout<<"Enter the nth term: ";
cin>>n;
for(i=1;i<=n;i++)
{
  prime+=  is_prime(i);

}
cout<< "The number of primes are: "<< prime<<endl;
}
