/*
Assignment 1:
Demonstrate virtual base class to solve diamond problem using Device,
Printer, Scanner, and Photocopier.
*/

#include <iostream>
using namespace std;

class Device {
private:
    float power;

public:
    Device(float p) {
        power = p;
    }

    float powerConsumption() const {
        return power;
    }

    virtual void operate() = 0;

    virtual ~Device() {}
};

class Printer : virtual public Device {
private:
    int speed;

public:
    Printer(float p, int s) : Device(p) {
        speed = s;
    }

    void operate() override {
        cout << "Printer is printing at " << speed << " pages per minute." << endl;
    }
};

class Scanner : virtual public Device {
private:
    int resolution;

public:
    Scanner(float p, int r) : Device(p) {
        resolution = r;
    }

    void operate() override {
        cout << "Scanner is scanning at " << resolution << " DPI." << endl;
    }
};

class Photocopier : public Printer, public Scanner {
public:
    Photocopier(float p, int s, int r)
        : Device(p), Printer(p, s), Scanner(p, r) {
    }

    void operate() override {
        cout << "Photocopier operation:" << endl;
        Printer::operate();
        Scanner::operate();
    }
};

int main() {
    Photocopier pc(500, 30, 1200);

    Device *ptr = &pc;

    ptr->operate();
    cout << "Power Consumption: " << ptr->powerConsumption() << " W" << endl;

    /*
    Virtual inheritance is needed because Printer and Scanner both inherit Device.
    It ensures Photocopier has only one shared copy of Device.
    */

    return 0;
}