#include<iostream>
using namespace std;
int main() {
    int seats[10] = {0}; 
    int seatNumber;

    cout << "Current Seat Status:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Seat " << i + 1 << ": " << (seats[i] == 0 ? "Available" : "Booked") << endl;
    }

    cout << "\nEnter seat number to book (1-10): ";
    cin >> seatNumber;

    if (seatNumber >= 1 && seatNumber <= 10) {
        if (seats[seatNumber - 1] == 0) {
            seats[seatNumber - 1] = 1;
            cout << "Seat booked successfully!\n";
        } else {
            cout << "Seat already booked.\n";
        }
    } else {
        cout << "Invalid seat number.\n";
    }

    cout << "\nUpdated Seat Status:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Seat " << i + 1 << ": "
             << (seats[i] == 0 ? "Available" : "Booked") << endl;
    }

    return 0;
}