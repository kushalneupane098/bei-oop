#include <iostream>
#include <fstream>
using namespace std;
class product{
    public:
    int productID;
    char productname[20];
    float price;
};
int main(){
    product p;
    ofstream fout("products.dat",ios::binary);
    ifstream fin("products.dat",ios::binary);
    cout<<"Enter the details of 5 products: "<<endl;
    for(int i = 0;i<5;i++){
        cout<<"Product "<<i+1<<endl;
        cout<<"Id: ";
        cin>>p.productID;
        cout<<"Name: ";
        cin>>p.productname;
        cout<<"Price: ";
        cin>>p.price;
        fout.write((char*)&p, sizeof(p));
    }
    fout.close();
    while(fin.read((char*)&p, sizeof(p))){
        cout<<"Id: "<<p.productID<<endl;
        cout<<"Name: "<<p.productname<<endl;
        cout<<"Price: "<<p.price<<endl;
    }
    fin.clear();
    fin.seekg(0,ios::end);
    int totalproducts = fin.tellg()/sizeof(product);
    cout<<"Total Products: "<<totalproducts<<endl;
    fin.close();
    return 0;
}