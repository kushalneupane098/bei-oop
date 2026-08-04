#include <iostream>
using namespace std;

class LibraryBook
{
private:
    string title;
    string author;
    bool isAvailable;

public:
    LibraryBook(string t, string a)
    {
        title = t;
        author = a;
        isAvailable = true;
    }

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    void display() const
    {
        cout << "Title : " << title << endl;
        cout << "Author : " << author << endl;

        if (isAvailable)
            cout << "Available\n";
        else
            cout << "Checked Out\n";
    }

    void checkout()
    {
        isAvailable = false;
    }

    void returnBook()
    {
        isAvailable = true;
    }
};

void printBookInfo(const LibraryBook &book)
{
    book.display();
}

int main()
{
    LibraryBook b("C++ Programming", "Bjarne");

    printBookInfo(b);

    b.checkout();

    cout << "\nAfter Checkout\n";
    b.display();

    b.returnBook();

    cout << "\nAfter Return\n";
    b.display();

    return 0;
}