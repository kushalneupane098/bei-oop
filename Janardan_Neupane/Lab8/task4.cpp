#include <iostream>
#include <fstream>
#include <string>
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
    fstream file("accounts.dat", ios::in | ios::out | ios::binary | ios::app);

    int choice;
    Account a;

    do {
        cout << "\n1. Add Account\n2. Display Accounts\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            a.input();
            file.clear();
            file.seekp(0, ios::end);
            a.writeToFile(file);
        } else if (choice == 2) {
            file.clear();
            file.seekg(0, ios::beg);
            while (file.read((char*)&a, sizeof(Account))) {
                a.display();
            }
        }
    } while (choice != 3);

    file.close();
    return 0;
}
