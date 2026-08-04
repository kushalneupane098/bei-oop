#include <iostream>
#include <string>
using namespace std;

class LibraryBook {
private:
    string title;
    string author;
    bool isAvailable;

public:
    LibraryBook(string t, string a) {
        title = t;
        author = a;
        isAvailable = true;
    }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getAvailability() const { return isAvailable; }

    void display() const {
        cout << "Title: " << title << " | Author: " << author 
             << " | Status: " << (isAvailable ? "Available" : "Checked Out") << endl;
    }

    void checkout() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Successfully checked out: " << title << endl;
        } else {
            cout << "Sorry, " << title << " is already checked out." << endl;
        }
    }

    void returnBook() {
        isAvailable = true;
        cout << "Successfully returned: " << title << endl;
    }
};

void printBookInfo(const LibraryBook& book) {
    cout << "\n[Standalone Function Log]" << endl;
    cout << "Book Title: " << book.getTitle() << endl;
    cout << "Author: " << book.getAuthor() << endl;
    cout << "Availability Status: " << (book.getAvailability() ? "In Library" : "Issued") << endl;
}

int main() {
    LibraryBook book1("Object Oriented Programming in C++", "Sushant Pandey");

    book1.display();
    book1.checkout();
    
    printBookInfo(book1);

    book1.returnBook();
    book1.display();

    return 0;
}