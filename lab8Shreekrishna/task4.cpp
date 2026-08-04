#include<iostream>
#include<fstream>
using namespace std;

class Account
{
public:
    int accNo;
    char lname[20];
    char fname[20];
    float balance;
};

int main()
{
    fstream file("account.dat",ios::binary|ios::out|ios::in|ios::trunc);

    Account a;
    int n;

    cout<<"Enter number of accounts: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter Account No LastName FirstName Balance: ";
        cin>>a.accNo>>a.lname>>a.fname>>a.balance;

        file.seekp((a.accNo-1)*sizeof(a));
        file.write((char*)&a,sizeof(a));
    }

    file.clear();
    file.seekg(0);

    cout<<"\nAccount Details\n";

    while(file.read((char*)&a,sizeof(a)))
    {
        if(a.accNo!=0)
            cout<<a.accNo<<" "<<a.lname<<" "<<a.fname<<" "<<a.balance<<endl;
    }

    file.close();

    return 0;
}