# include <iostream>
#include <string>
using namespace std;
class LibraryBook{
    string title;
    string author;
    bool isavailable;
    bool isreturned;

public:
    LibraryBook(){}
    LibraryBook(string t, string a, bool c): title(t),author(a),isavailable(c){}
    void getinput(){
        cout<<"Enter the title of the book: ";
        cin>>title;
        cout<<"Enter the name of the author of the book: ";
        cin>>author;
    }

    string gettitle() const{
        return title;
    }
    string getauthor()const {
        return author;
    }
    void display()const {
        cout<<"Title: "<<title;
        cout<<"Author: "<<author;
    }
    void checkout(bool condit){
        if(condit == true){
            cout<<"We have this book"<<endl;
        }
        else{
            cout<<"We dont have this book"<<endl;
        }
    }
    void returnbook(bool returned){
        if(returned == true){
            cout<<"Returned"<<endl;
        }
        else{
            cout<<"Not Returned"<<endl;
        }
    }
};
int main(){
    LibraryBook book;
    
    book.getinput();
    book.display();
    cout << endl;
    book.checkout(book.gettitle() != "");
    
    char resp;
    cout<<"Is the book returned? (y/n): ";
    cin>>resp;
    book.returnbook(resp=='y' || resp=='Y');
    return 0;
}