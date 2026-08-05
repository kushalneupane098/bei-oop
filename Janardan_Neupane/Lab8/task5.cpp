#include <iostream>
#include <fstream>
using namespace std;

class Account {
    int accNo;
    char lastName[20];
    char firstName[20];
    double balance;

public:
    void input() {
        cout << "Enter Account No: ";
        cin >> accNo;
        cout << "Enter First Name: ";
        cin.ignore();
        cin.getline(firstName, 20);
        cout << "Enter Last Name: ";
        cin.getline(lastName, 20);
        cout << "Enter Balance: ";
        cin >> balance;
    }

    void display() const {
        cout << "AccNo: " << accNo << " | Name: " << firstName << " " << lastName
             << " | Balance: Rs." << balance << endl;
    }

    int getAccNo() const { return accNo; }

    void writeToFile(fstream &file) {
        file.write((char*)this, sizeof(Account));
    }

    void readFromFile(fstream &file) {
        file.read((char*)this, sizeof(Account));
    }
};

int main() {
    fstream file("accounts.dat", ios::in | ios::out | ios::binary);

    int choice;
    Account a;

    do {
        cout << "\n1. Add Account\n2. Display Accounts\n3. Update Account\n4. Delete Account\n5. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            file.clear();
            file.seekp(0, ios::end);
            a.input();
            a.writeToFile(file);
        } else if (choice == 2) {
            file.clear();
            file.seekg(0, ios::beg);
            while (file.read((char*)&a, sizeof(Account))) {
                a.display();
            }
        } else if (choice == 3) {
            int acc;
            cout << "Enter account number to update: ";
            cin >> acc;
            file.clear();
            file.seekg(0, ios::beg);
            while (file.read((char*)&a, sizeof(Account))) {
                if (a.getAccNo() == acc) {
                    cout << "Enter new details:\n";
                    a.input();
                    file.seekp(-sizeof(Account), ios::cur);
                    a.writeToFile(file);
                    cout << "Account updated!\n";
                    break;
                }
            }
        } else if (choice == 4) {
            int acc;
            cout << "Enter account number to delete: ";
            cin >> acc;

            fstream temp("temp.dat", ios::out | ios::binary);
            file.clear();
            file.seekg(0, ios::beg);
            while (file.read((char*)&a, sizeof(Account))) {
                if (a.getAccNo() != acc) {
                    temp.write((char*)&a, sizeof(Account));
                }
            }
            file.close();
            temp.close();
            remove("accounts.dat");
            rename("temp.dat", "accounts.dat");
            file.open("accounts.dat", ios::in | ios::out | ios::binary);
            cout << "Account deleted!\n";
        }
    } while (choice != 5);

    file.close();
    return 0;
}