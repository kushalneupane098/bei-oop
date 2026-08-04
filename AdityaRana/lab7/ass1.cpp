#include <iostream>

using namespace std;

class Device {
public:
    float powerConsumption;
    Device(float pc) : powerConsumption(pc) {}
    virtual void operate() = 0;
    virtual ~Device() {}
};

class Printer : virtual public Device {
public:
    Printer(float pc) : Device(pc) {}
    void operate() override {
        cout << "Printing" << endl;
    }
};

class Scanner : virtual public Device {
public:
    Scanner(float pc) : Device(pc) {}
    void operate() override {
        cout << "Scanning" << endl;
    }
};

class Photocopier : public Printer, public Scanner {
public:
    Photocopier(float pc) : Device(pc), Printer(pc), Scanner(pc) {}

    void operate() override {
        Printer::operate();
        Scanner::operate();
    }
};

int main() {
    Photocopier copyMachine(120.5f);
    Device* devPtr = &copyMachine;
    devPtr->operate();
    cout << "Power: " << devPtr->powerConsumption << endl;
    return 0;
}