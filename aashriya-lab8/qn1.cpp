#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    ifstream sourceFile("input.txt");
    ofstream destinationFile("output.txt");

    if (!sourceFile) {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    if (!destinationFile) {
        cout << "Error creating output file!" << endl;
        return 1;
    }

    char ch;

    while (sourceFile.get(ch)) {
        destinationFile.put(toupper(ch));
    }

    cout << "File copied successfully with lowercase letters converted to uppercase." << endl;

    sourceFile.close();
    destinationFile.close();

    return 0;
}