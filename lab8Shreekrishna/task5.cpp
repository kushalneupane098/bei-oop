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
    fstream file("account.dat",ios::binary|ios::in|ios::out);

    if(!file)
    {
        ofstream create("account.dat",ios::binary);
        Account blank={0,"","",0};

        for(int i=0;i<100;i++)
            create.write((char*)&blank,sizeof(blank));

        create.close();

        file.open("account.dat",ios::binary|ios::in|ios::out);
    }

    int ch;
    Account a;

    do
    {
        cout<<"\n1.Add\n2.Display\n3.Update\n4.Delete\n5.Exit\n";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter AccountNo LastName FirstName Balance: ";
                cin>>a.accNo>>a.lname>>a.fname>>a.balance;

                file.seekp((a.accNo-1)*sizeof(a));
                file.write((char*)&a,sizeof(a));
                break;

            case 2:
                file.clear();
                file.seekg(0);

                while(file.read((char*)&a,sizeof(a)))
                {
                    if(a.accNo!=0)
                        cout<<a.accNo<<" "<<a.lname<<" "<<a.fname<<" "<<a.balance<<endl;
                }
                break;

            case 3:
            {
                int no;
                cout<<"Enter Account Number: ";
                cin>>no;

                file.seekg((no-1)*sizeof(a));
                file.read((char*)&a,sizeof(a));

                if(a.accNo!=0)
                {
                    cout<<"Enter New LastName FirstName Balance: ";
                    cin>>a.lname>>a.fname>>a.balance;

                    file.seekp((no-1)*sizeof(a));
                    file.write((char*)&a,sizeof(a));
                }
                break;
            }

            case 4:
            {
                int no;
                cout<<"Enter Account Number: ";
                cin>>no;

                Account blank={0,"","",0};

                file.seekp((no-1)*sizeof(a));
                file.write((char*)&blank,sizeof(blank));
                break;
            }

        }

        file.clear();

    }while(ch!=5);

    file.close();

    return 0;
}