#include<iostream>
#include<fstream>
using namespace std;

class Product
{
public:
    int id;
    char name[20];
    float price;
};

int main()
{
    Product p;

    ofstream fout("product.dat",ios::binary);

    for(int i=0;i<5;i++)
    {
        cout<<"Enter ID Name Price: ";
        cin>>p.id>>p.name>>p.price;

        fout.write((char*)&p,sizeof(p));
    }

    fout.close();

    ifstream fin("product.dat",ios::binary);

    cout<<"\nProduct List\n";

    while(fin.read((char*)&p,sizeof(p)))
    {
        cout<<p.id<<" "<<p.name<<" "<<p.price<<endl;
    }

    fin.clear();
    fin.seekg(0,ios::end);

    cout<<"\nTotal Products = "<<fin.tellg()/sizeof(Product);

    fin.close();

    return 0;
}