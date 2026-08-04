#include <iostream>
using namespace std;

struct Expense {
    string description;
    float amount;
    string category;
};

void addExpense(Expense expenses[], int &count) {
    cout << "\nEnter Expense Description: ";
    cin >> expenses[count].description;

    cout << "Enter Amount: ";
    cin >> expenses[count].amount;

    cout << "Enter Category: ";
    cin >> expenses[count].category;

    count++;
}

float totalByCategory(Expense expenses[], int count, string category) {
    float total = 0;

    for (int i = 0; i < count; i++) {
        if (expenses[i].category == category) {
            total += expenses[i].amount;
        }
    }

    return total;
}

int main() {
    Expense expenses[100];
    int count = 0, n;
    string category;

    cout << "How many expenses do you want to add? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        addExpense(expenses, count);
    }

    cout << "\nEnter category to calculate total expenses: ";
    cin >> category;

    cout << "Total expenses in category " << category << " = " << totalByCategory(expenses, count, category);

    return 0;
}