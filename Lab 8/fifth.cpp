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

void addAccount()
{
    Account a;
    ofstream file("account.dat", ios::binary | ios::app);

    a.input();
    file.write((char *)&a, sizeof(a));

    file.close();
}

void displayAccount()
{
    Account a;
    ifstream file("account.dat", ios::binary);

    while (file.read((char *)&a, sizeof(a)))
    {
        a.display();
    }

    file.close();
}

void updateAccount()
{
    Account a;
    int no;

    cout << "Enter account number to update: ";
    cin >> no;

    fstream file("account.dat", ios::in | ios::out | ios::binary);

    while (file.read((char *)&a, sizeof(a)))
    {
        if (a.accNo == no)
        {
            cout << "Enter new details:\n";
            a.input();

            file.seekp(-sizeof(a), ios::cur);
            file.write((char *)&a, sizeof(a));
            break;
        }
    }

    file.close();
}

void deleteAccount()
{
    Account a;
    int no;

    cout << "Enter account number to delete: ";
    cin >> no;

    ifstream file("account.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while (file.read((char *)&a, sizeof(a)))
    {
        if (a.accNo != no)
        {
            temp.write((char *)&a, sizeof(a));
        }
    }

    file.close();
    temp.close();

    remove("account.dat");
    rename("temp.dat", "account.dat");
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add";
        cout << "\n2. Display";
        cout << "\n3. Update";
        cout << "\n4. Delete";
        cout << "\n5. Exit";
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addAccount();
            break;

        case 2:
            displayAccount();
            break;

        case 3:
            updateAccount();
            break;

        case 4:
            deleteAccount();
            break;
        }

    } while (choice != 5);

    return 0;
}