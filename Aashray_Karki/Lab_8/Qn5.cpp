/*
Question 5:
Extend the account transaction processing program to support update and delete operations.
*/

#include <iostream>
#include <fstream>
using namespace std;

class Account {
private:
    int accountNumber;
    char lastName[20];
    char firstName[20];
    float totalBalance;
    bool active;

public:
    Account() {
        active = true;
    }

    void input() {
        cout << "Enter account number: ";
        cin >> accountNumber;

        cout << "Enter first name: ";
        cin >> firstName;

        cout << "Enter last name: ";
        cin >> lastName;

        cout << "Enter total balance: ";
        cin >> totalBalance;

        active = true;
    }

    void display() const {
        if (active) {
            cout << "Account No: " << accountNumber
                 << ", Name: " << firstName << " " << lastName
                 << ", Balance: " << totalBalance << endl;
        }
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    bool isActive() const {
        return active;
    }

    void remove() {
        active = false;
    }
};

void addAccount() {
    Account acc;

    ofstream outFile("accounts.dat", ios::binary | ios::app);

    acc.input();
    outFile.write((char*)&acc, sizeof(acc));

    outFile.close();

    cout << "Account added successfully." << endl;
}

void displayAccounts() {
    Account acc;

    ifstream inFile("accounts.dat", ios::binary);

    cout << "\nActive Account Records:" << endl;

    while (inFile.read((char*)&acc, sizeof(acc))) {
        acc.display();
    }

    inFile.close();
}

void updateAccount() {
    Account acc;
    int accNo;
    bool found = false;

    cout << "Enter account number to update: ";
    cin >> accNo;

    fstream file("accounts.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&acc, sizeof(acc))) {
        if (acc.getAccountNumber() == accNo && acc.isActive()) {
            cout << "Enter new details:" << endl;
            acc.input();

            file.seekp(-static_cast<int>(sizeof(acc)), ios::cur);
            file.write((char*)&acc, sizeof(acc));

            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Account updated successfully." << endl;
    else
        cout << "Account not found." << endl;
}

void deleteAccount() {
    Account acc;
    int accNo;
    bool found = false;

    cout << "Enter account number to delete: ";
    cin >> accNo;

    fstream file("accounts.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&acc, sizeof(acc))) {
        if (acc.getAccountNumber() == accNo && acc.isActive()) {
            acc.remove();

            file.seekp(-static_cast<int>(sizeof(acc)), ios::cur);
            file.write((char*)&acc, sizeof(acc));

            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Account deleted successfully." << endl;
    else
        cout << "Account not found." << endl;
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Account";
        cout << "\n2. Display Accounts";
        cout << "\n3. Update Account";
        cout << "\n4. Delete Account";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            addAccount();
        else if (choice == 2)
            displayAccounts();
        else if (choice == 3)
            updateAccount();
        else if (choice == 4)
            deleteAccount();
        else if (choice == 5)
            cout << "Program ended." << endl;
        else
            cout << "Invalid choice." << endl;

    } while (choice != 5);

    return 0;
}