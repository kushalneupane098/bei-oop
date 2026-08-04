#include <iostream>
#include <fstream>
using namespace std;

class Account {
public:
    int accountNo;
    char lastName[20];
    char firstName[20];
    double balance;
};

int main() {
    fstream file("accounts.dat",ios::binary | ios::in | ios::out | ios::trunc);

    Account acc;

    int choice;

    do {
        cout << "\n1.Add Account";
        cout << "\n2.Display Accounts";
        cout << "\n3.Exit";
        cout << "\nChoice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Account No: ";
            cin >> acc.accountNo;

            cout << "First Name: ";
            cin >> acc.firstName;

            cout << "Last Name: ";
            cin >> acc.lastName;

            cout << "Balance: ";
            cin >> acc.balance;

            file.seekp((acc.accountNo - 1)
                       * sizeof(Account));

            file.write((char*)&acc,
                       sizeof(Account));
            break;

        case 2:
            file.clear();
            file.seekg(0);

            while(file.read((char*)&acc,
                            sizeof(Account))) {

                if(acc.accountNo != 0) {
                    cout << "\nAccount No: "
                         << acc.accountNo
                         << "\nName: "
                         << acc.firstName
                         << " "
                         << acc.lastName
                         << "\nBalance: "
                         << acc.balance << endl;
                }
            }
            break;
        }

    } while(choice != 3);

    file.close();

    return 0;
}