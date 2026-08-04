#include <iostream>
using namespace std;

int main() {
    float sales[7];
    float total = 0;
    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    cout << "Enter daily sales for the week:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << days[i] << ": Rs";
        cin >> sales[i];
        total += sales[i];
    }

    float average = total / 7;

    cout << "\nWeekly Sales Report" << endl;
    for (int i = 0; i < 7; i++) {
        cout << days[i] << ": Rs" << sales[i] << endl;
    }

    cout << "\nTotal Sales  : Rs" << total << endl;
    cout << "Average Sales: Rs" << average << endl;

    return 0;
}
