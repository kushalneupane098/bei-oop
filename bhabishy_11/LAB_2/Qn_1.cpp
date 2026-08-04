 #include <iostream>
using namespace std;

void displaySeats(int seats[], int size)
{
    cout << "\nSeat Status:\n";

    for(int i = 0; i < size; i++)
    {
        cout << "Seat " << i + 1 << " : ";

        if(seats[i] == 1)
            cout << "Booked";
        else
            cout << "Available";

        cout << endl;
    }
}

int main()
{
    int seats[10] = {0};

    int seatNumber;

    displaySeats(seats, 10);

    cout << "\nEnter seat number to book (1-10): ";
    cin >> seatNumber;

    if(seatNumber >= 1 && seatNumber <= 10)
    {
        if(seats[seatNumber - 1] == 0)
        {
            seats[seatNumber - 1] = 1;
            cout << "Seat booked successfully.\n";
        }
        else
        {
            cout << "Seat already booked.\n";
        }
    }
    else
    {
        cout << "Invalid seat number.\n";
    }

    displaySeats(seats, 10);

    system("pause");
    return 0;
}