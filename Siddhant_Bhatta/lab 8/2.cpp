#include <iostream>
#include <fstream>
using namespace std;

struct Product {
    int id;
    char name[20];
    float price;
};

struct Client {
    int accNo;
    char name[20];
};

int main() {
    Product p[5] = {
        {1, "Pen", 20}, {2, "Book", 100}, {3, "Bag", 1200}, 
        {4, "Scale", 30}, {5, "Box", 150}
    };

    ofstream fout("prod.dat", ios::binary);
    fout.write(reinterpret_cast<char*>(p), sizeof(p));
    fout.close();

    Product temp;
    ifstream fin("prod.dat", ios::binary);
    while (fin.read(reinterpret_cast<char*>(&temp), sizeof(Product))) {
        cout << temp.id << " " << temp.name << " " << temp.price << endl;
    }
    fin.close();

    Client c[3];
    ofstream fout2("bank.dat", ios::binary);
    fout2.write(reinterpret_cast<char*>(c), sizeof(c));
    fout2.close();

    ifstream fin2("bank.dat", ios::binary | ios::ate);
    if (fin2) {
        int total = fin2.tellg() / sizeof(Client);
        cout << "\nTotal Clients: " << total << endl;
    }
    fin2.close();
    return 0;
}