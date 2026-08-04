#include <iostream>
using namespace std;

class LibraryBook {
private:
    string title;
    string author;
    bool isAvailable;

public:
    LibraryBook(string t, string a, bool av) {
        title = t;
        author = a;
        isAvailable = av;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Available: "
             << (isAvailable ? "Yes" : "No") << endl;
    }

    friend void printBookInfo(const LibraryBook& book);
};

void printBookInfo(const LibraryBook& book) {
    book.display();
}

int main() {
    LibraryBook b1("C++ Programming", "Bjarne", true);

    printBookInfo(b1);

    return 0;
}