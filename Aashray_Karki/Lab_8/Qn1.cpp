/*
Question 1:
Write a program that copies the content of one file into another file,
changing any lowercase letters to uppercase in the process.
*/

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ofstream sample("source.txt");
    sample << "This is a sample file.\n";
    sample << "lowercase letters will become uppercase.\n";
    sample.close();

    ifstream input("source.txt");
    ofstream output("destination.txt");

    if (!input || !output) {
        cout << "File opening error!" << endl;
        return 1;
    }

    char ch;

    while (input.get(ch)) {
        output.put(toupper(ch));
    }

    input.close();
    output.close();

    cout << "File copied successfully with lowercase converted to uppercase." << endl;

    return 0;
}