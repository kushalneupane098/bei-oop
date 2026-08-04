#include <iostream>
using namespace std;

struct Product {
    string name;
    int code;
    float price;
    int quantity;
};

int main() {
    Product products[5];
     cout << "Enter details of 5 products:\n";

    for (int i = 0; i < 5; i++) {
        cout << "\nProduct " << i + 1 << endl;

        cout << "Name: ";
        cin >> products[i].name;

        cout << "Code: ";
        cin >> products[i].code;

        cout << "Price: ";
        cin >> products[i].price;

        cout << "Quantity: ";
        cin >> products[i].quantity;
    }

    cout << "\nProducts with quantity less than 10:\n";

    for (int i = 0; i < 5; i++) {
        if (products[i].quantity < 10) {
            cout << "\nName: " << products[i].name
                 << "\nCode: " << products[i].code
                 << "\nPrice: " << products[i].price
                 << "\nQuantity: " << products[i].quantity
                 << endl;
        }
    }

    return 0;
}