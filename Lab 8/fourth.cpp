#include <iostream>
#include <fstream>
using namespace std;

class Account
{
public:
    int accNo;
    char lastName[20];
    char firstName[20];
    float balance;

    void input()
    {
        cout << "Account No: ";
        cin >> accNo;

        cout << "First Name: ";
        cin >> firstName;

        cout << "Last Name: ";
        cin >> lastName;

        cout << "Balance: ";
        cin >> balance;
    }

    void display()
    {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << firstName << " " << lastName;
        cout << "\nBalance: " << balance << endl;
    }
};

int main()
{
    Account a;
    fstream file;
    int choice;

    file.open("account.dat", ios::in | ios::out | ios::binary | ios::app);

    do
    {
        cout << "\n1. Add Account";
        cout << "\n2. Display Account";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            a.input();

            file.clear();
            file.seekp((a.accNo - 1) * sizeof(a));
            file.write((char*)&a, sizeof(a));
        }

        else if(choice == 2)
        {
            int no;
            cout << "Enter account number: ";
            cin >> no;

            file.clear();
            file.seekg((no - 1) * sizeof(a));

            file.read((char*)&a, sizeof(a));

            a.display();
        }

    } while(choice != 3);

    file.close();

    return 0;
}