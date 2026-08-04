/*
Question 2:
Store information of at least 5 products in a file and display them.
Also calculate total number of records using get pointer value / sizeof(object).
*/

#include <iostream>
#include <fstream>
using namespace std;

class Product {
private:
    int code;
    char name[30];
    float price;
    int quantity;

public:
    void input() {
        cout << "Enter product code: ";
        cin >> code;

        cout << "Enter product name: ";
        cin.ignore();
        cin.getline(name, 30);

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter quantity: ";
        cin >> quantity;
    }

    void display() const {
        cout << "Code: " << code
             << ", Name: " << name
             << ", Price: " << price
             << ", Quantity: " << quantity << endl;
    }
};

int main() {
    Product p;

    ofstream outFile("products.dat", ios::binary);

    cout << "Enter details of 5 products:" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\nProduct " << i + 1 << ":" << endl;
        p.input();
        outFile.write((char*)&p, sizeof(p));
    }

    outFile.close();

    ifstream inFile("products.dat", ios::binary);

    cout << "\nProduct Records:" << endl;

    while (inFile.read((char*)&p, sizeof(p))) {
        p.display();
    }

    inFile.clear();
    inFile.seekg(0, ios::end);

    int totalRecords = inFile.tellg() / sizeof(Product);

    cout << "\nTotal Records: " << totalRecords << endl;

    inFile.close();

    return 0;
}