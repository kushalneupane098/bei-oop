#include <iostream>
#include <fstream>
using namespace std;

class Product {
public:
    int id;
    char name[30];
    float price;
};

int main() {
    Product p[5] = {
        {101, "Rice", 1200},
        {102, "Sugar", 150},
        {103, "Oil", 350},
        {104, "Soap", 80},
        {105, "Milk", 110}
    };

    ofstream out("products.dat", ios::binary);

    for(int i = 0; i < 5; i++)
        out.write((char*)&p[i], sizeof(Product));

    out.close();

    ifstream in("products.dat", ios::binary);

    Product temp;

    cout << "Product Information\n";
    cout << "-------------------\n";

    while(in.read((char*)&temp, sizeof(Product))) {
        cout << "ID: " << temp.id
             << " Name: " << temp.name
             << " Price: " << temp.price << endl;
    }

    long size = in.tellg();

    in.clear();
    in.seekg(0, ios::end);
    size = in.tellg();

    cout << "\nTotal Products = "
         << size / sizeof(Product) << endl;

    in.close();

    return 0;
}