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

  
    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    void display() const {
        cout << "Title      : " << title << endl;
        cout << "Author     : " << author << endl;
        cout << "Availability: "
             << (isAvailable ? "Available" : "Checked Out")
             << endl;
    }

   
    void checkout() {
        if (isAvailable) {
            isAvailable = false;
            cout << "\"" << title << "\" has been checked out.\n";
        } else {
            cout << "\"" << title << "\" is already checked out.\n";
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "\"" << title << "\" has been returned.\n";
        } else {
            cout << "\"" << title << "\" is already available.\n";
        }
    }
};


void printBookInfo(const LibraryBook& book) {
    cout << "\n--- Book Information ---\n";
    cout << "Title  : " << book.getTitle() << endl;
    cout << "Author : " << book.getAuthor() << endl;

   
    book.display();

    
}

int main() {
    LibraryBook book1("The Great Gatsby", "F. Scott Fitzgerald");

    cout << "Initial Book Status:\n";
    book1.display();

    cout << "\nChecking out the book:\n";
    book1.checkout();
    book1.display();

    cout << "\nPrinting book info using const reference:\n";
    printBookInfo(book1);

    cout << "\nReturning the book:\n";
    book1.returnBook();
    book1.display();

    return 0;
}