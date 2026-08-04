#include <iostream>
#include <string>
using namespace std;

struct Expense {
    string description;
    float amount;
    string category;
};

void addExpense(Expense expenses[], int &count) {
    if (count >= 100) {
        cout << "Expense limit reached!" << endl;
        return;
    }
    cout << "Enter description: ";
    cin >> expenses[count].description;
    cout << "Enter amount     : ";
    cin >> expenses[count].amount;
    cout << "Enter category   : ";
    cin >> expenses[count].category;
    count++;
    cout << "Expense added successfully!" << endl;
}

float totalByCategory(Expense expenses[], int count, string category) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        if (expenses[i].category == category)
            total += expenses[i].amount;
    }
    return total;
}

void displayExpenses(Expense expenses[], int count) {
    if (count == 0) {
        cout << "No expenses recorded." << endl;
        return;
    }
    cout << "\n--- All Expenses ---" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Description: " << expenses[i].description << endl;
        cout << "Amount     : " << expenses[i].amount << endl;
        cout << "Category   : " << expenses[i].category << endl;
        cout << endl;
    }
}

int main() {
    Expense expenses[100];
    int count = 0;
    int choice;
    string category;

    do {
        cout << "1. Add Expense" << endl;
        cout << "2. Display All Expenses" << endl;
        cout << "3. Total by Category" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                addExpense(expenses, count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                cout << "Enter category: ";
                cin >> category;
                cout << "Total for " << category << ": $" << totalByCategory(expenses, count, category) << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
        cout << endl;
    } while (choice != 4);

    return 0;
}
