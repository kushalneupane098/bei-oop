#include <iostream>
using namespace std;

float convert(float amount, float rate) {
    return amount * rate;
}

int main() {
    float amount, rate;

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Enter conversion rate: ";
    cin >> rate;

    float result = convert(amount, rate);

    cout << "Converted Amount = " << result;

    return 0;
}