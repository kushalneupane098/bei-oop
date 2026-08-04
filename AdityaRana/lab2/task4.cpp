#include <iostream>
using namespace std;

struct Item {
    string name;
    float price;
};

float calculateBill(Item a) {
    float tax = a.price * 0.10;
    return a.price + tax;
}

int main() {
    Item a;

    cout << "Enter item name: ";
    cin >> a.name;

    cout << "Enter price: ";
    cin >> a.price;

    float total = calculateBill(a);

    cout << "\nItem: " << a.name;
    cout << "\nPrice: " << a.price;
    cout << "\nTotal with 10% tax = " << total;

    return 0;
}