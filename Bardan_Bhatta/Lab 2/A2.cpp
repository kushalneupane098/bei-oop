#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    int code;
    float price;
    char quantity;
};

void inputProducts(Product products[], int total) {
    for (int i = 0; i < total; i++) {
        cout << "Enter details for Product " << i + 1 << ":" << endl;
        cout << "  Name    : ";
        cin >> products[i].name;
        cout << "  Code    : ";
        cin >> products[i].code;
        cout << "  Price   : ";
        cin >> products[i].price;
        cout << "  Quantity: ";
        cin >> products[i].quantity;
        cout << endl;
    }
}

void displayLowStock(Product products[], int total) {
    cout << "--- Products with Quantity Less Than 10 ---" << endl;
    bool found = false;
    for (int i = 0; i < total; i++) {
        if (products[i].quantity < 10) {
            cout << "Name    : " << products[i].name << endl;
            cout << "Code    : " << products[i].code << endl;
            cout << "Price   : " << products[i].price << endl;
            cout << "Quantity: " << products[i].quantity <<"kg"<< endl;
            cout << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No products with low stock." << endl;
}

int main() {
    Product products[5];

    inputProducts(products, 5);
    displayLowStock(products, 5);

    return 0;
}
