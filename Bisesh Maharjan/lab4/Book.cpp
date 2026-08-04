#include<iostream>
#include<string>
using namespace std;
class Book {
    private:
        string title;
        string author;
        bool avail;
    public:
        Book(string t, string a) {
            title  = t;
            author = a;
            avail  = true;
        }
        string getTitle() const {
            return title;
        }
        string getAuthor() const {
            return author;
        }
        void show() const {
            cout<<"Title:"<<title<<endl;
            cout<<"Author:"<<author<<endl;
            cout<<"Available:"<<(avail?"Yes":"No")<<endl;
        }
        void checkout() {
            avail = false;
        }
        void ret() {
            avail = true;
        }
};
void printInfo(const Book& b) {
    b.show();
}
int main() {
    Book b1("The invisible man", "Yunjin");
    cout<<"Book Info"<<endl;
    printInfo(b1);
    cout<<"\nAfter Checkout"<<endl;
    b1.checkout();
    b1.show();
    cout<<"\nAfter Return"<<endl;
    b1.ret();
    b1.show();
    return 0;
}
