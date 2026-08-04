#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    float price;
};

float calculateBill(Item i) {
    float tax = i.price * 0.10;
    return i.price + tax;
}

int main() {
    Item item;

    cout << "Enter item name: ";
    cin >> item.name;
    cout << "Enter item price: ";
    cin >> item.price;

    float total = calculateBill(item);

    cout << "Item    : " << item.name << endl;
    cout << "Price   : " << item.price << endl;
    cout << "Tax(10%): " << item.price * 0.10 << endl;
    cout << "Total   : " << total << endl;

    return 0;
}
