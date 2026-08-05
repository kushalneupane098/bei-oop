#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;
    int quantity;

public:
    Product() {}
    Product(int i, string n, float p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Price: Rs." << price
             << " | Quantity: " << quantity << endl;
    }

    void writeToFile(ofstream &fout) {
        fout.write((char*)this, sizeof(Product));
    }

    void readFromFile(ifstream &fin) {
        fin.read((char*)this, sizeof(Product));
    }
};

class Client {
private:
    int id;
    string name;
    double balance;

public:
    Client() {}
    Client(int i, string n, double b) {
        id = i;
        name = n;
        balance = b;
    }

    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Balance: Rs." << balance << endl;
    }

    void writeToFile(ofstream &fout) {
        fout.write((char*)this, sizeof(Client));
    }

    void readFromFile(ifstream &fin) {
        fin.read((char*)this, sizeof(Client));
    }
};

int main() {
    Product products[5] = {
        Product(1, "Laptop", 75000.50, 10),
        Product(2, "Smartphone", 35000.00, 25),
        Product(3, "Headphones", 2500.75, 50),
        Product(4, "Keyboard", 1500.00, 40),
        Product(5, "Monitor", 12000.00, 15)
    };

    ofstream fout("products.dat", ios::binary);
    for (int i = 0; i < 5; i++) {
        products[i].writeToFile(fout);
    }
    fout.close();

    ifstream fin("products.dat", ios::binary);
    Product p;
    cout << "=== Department Store Products ===\n";
    while (fin.read((char*)&p, sizeof(Product))) {
        p.display();
    }
    fin.close();

    Client clients[3] = {
        Client(101, "Ram", 50000.00),
        Client(102, "Sita", 75000.50),
        Client(103, "Hari", 30000.25)
    };

    ofstream fout2("clients.dat", ios::binary);
    for (int i = 0; i < 3; i++) {
        clients[i].writeToFile(fout2);
    }
    fout2.close();

    ifstream fin2("clients.dat", ios::binary);
    fin2.seekg(0, ios::end);
    int fileSize = fin2.tellg();
    int totalClients = fileSize / sizeof(Client);
    fin2.close();

    cout << "\n=== Bank Info ===\n";
    cout << "Total number of clients: " << totalClients << endl;

    return 0;
}
