#include <iostream>
using namespace std;

void displaySeats(int seats[], int total) {
    cout << "\nSeat Status" << endl;
    for (int i = 0; i < total; i++) {
        cout << "Seat " << i + 1 << ": ";
        if (seats[i] == 0)
            cout << "Available" << endl;
        else
            cout << "Booked" << endl;
    }
    cout << endl;
}

void bookSeat(int seats[], int total) {
    int seatNum;
    cout << "Enter seat number to book (1-" << total << "): ";
    cin >> seatNum;

    if (seatNum < 1 || seatNum > total) {
        cout << "Invalid seat number!" << endl;
    } else if (seats[seatNum - 1] == 1) {
        cout << "Seat " << seatNum << " is already booked!" << endl;
    } else {
        seats[seatNum - 1] = 1;
        cout << "Seat " << seatNum << " successfully booked!" << endl;
    }
}

int main() {
    int seats[10] = {0};
    int choice;

    do {
        cout << "1. Display Seats" << endl;
        cout << "2. Book a Seat" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats(seats, 10);
                break;
            case 2:
                bookSeat(seats, 10);
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}
