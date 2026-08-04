#include <iostream>
using namespace std;


class Device {
public:
    float powerConsumption;

    Device(float p) : powerConsumption(p) {}

    virtual void operate() = 0; 
};


class Printer : virtual public Device {
protected:
    int pagesPerMinute;

public:
    Printer(float p, int ppm)
        : Device(p), pagesPerMinute(ppm) {}

    void operate() override {
        cout << "Printer operating at "
             << pagesPerMinute << " pages/min" << endl;
    }
};

class Scanner : virtual public Device {
protected:
    int scanResolution;

public:
    Scanner(float p, int res)
        : Device(p), scanResolution(res) {}

    void operate() override {
        cout << "Scanner operating at "
             << scanResolution << " DPI" << endl;
    }
};


class Photocopier : public Printer, public Scanner {
public:
    Photocopier(float p, int ppm, int res)
        : Device(p), Printer(p, ppm), Scanner(p, res) {}

    void operate() override {
        cout << "Photocopier operating:" << endl;
        Printer::operate();
        Scanner::operate();
    }
};

int main() {
    Photocopier pc(150.5f, 30, 1200);

    Device* dptr = &pc;

    dptr->operate();

    cout << "Power Consumption: "
         << dptr->powerConsumption
         << " Watts" << endl;

    return 0;
}