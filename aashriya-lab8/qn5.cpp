#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Account {
public:
    int accountNo;
    char firstName[20];
    char lastName[20];
    double balance;
};

int main() {

    fstream file("accounts.dat", ios::binary |ios::in | ios::out);

    if(!file) {
        ofstream create("accounts.dat", ios::binary);
        create.close();

        file.open("accounts.dat", ios::binary | ios::in |ios::out);
    }

    Account acc;
    int choice;

    do {
        cout << "\n1.Add";
        cout << "\n2.Display";
        cout << "\n3.Update";
        cout << "\n4.Delete";
        cout << "\n5.Exit";
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
                         << acc.balance
                         << endl;
                }
            }
            break;

        case 3: {
            int accNo;

            cout << "Enter Account No: ";
            cin >> accNo;

            file.seekg((accNo - 1)
                       * sizeof(Account));

            file.read((char*)&acc,
                      sizeof(Account));

            if(acc.accountNo != 0) {

                cout << "New Balance: ";
                cin >> acc.balance;

                file.seekp((accNo - 1)
                           * sizeof(Account));

                file.write((char*)&acc,
                           sizeof(Account));

                cout << "Updated Successfully.\n";
            }
            break;
        }

        case 4: {
            int accNo;

            cout << "Enter Account No: ";
            cin >> accNo;

            Account blank = {0, "", "", 0};

            file.seekp((accNo - 1)
                       * sizeof(Account));

            file.write((char*)&blank,
                       sizeof(Account));

            cout << "Deleted Successfully.\n";
            break;
        }
        }

    } while(choice != 5);

    file.close();

    return 0;
}