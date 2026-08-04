#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream fin("source.txt");
    ofstream fout("destination.txt");
    if (!fin || !fout) return 1;

    char ch;
    while (fin.get(ch)) {
        fout.put(toupper(ch));
    }
    fin.close();
    fout.close();
    return 0;
}