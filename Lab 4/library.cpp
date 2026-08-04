#include <iostream>
using namespace std;

class LibraryBook
{
private:
    string title;
    string author;
    bool available;

public:
    LibraryBook(string t, string a)
    {
        title = t;
        author = a;
        available = true;
    }

    void display()
    {
        cout << "Book Title : " << title << endl;
        cout << "Author     : " << author << endl;

        if (available)
            cout << "Status     : Available" << endl;
        else
            cout << "Status     : Not Available" << endl;

        cout << endl;
    }

    void borrowBook()
    {
        available = false;
    }

    void returnBook()
    {
        available = true;
    }
};

void printBook(LibraryBook &book)
{
    book.display();
}

int main()
{
    LibraryBook book1("C++", "Bjarne Stroustrup");

    cout << "Initial Book Information:" << endl;
    printBook(book1);

    cout << "After Borrowing:" << endl;
    book1.borrowBook();
    printBook(book1);

    cout << "After Returning:" << endl;
    book1.returnBook();
    printBook(book1);

    return 0;
}