#include <iostream>
using namespace std;

class Device
{
public:
    float powerConsumption;

    Device(float p)
    {
        powerConsumption = p;
    }

    virtual void operate() = 0;
};

class Printer : virtual public Device
{
protected:
    int pages;

public:
    Printer(float p, int pg) : Device(p)
    {
        pages = pg;
    }

    void operate()
    {
        cout << "Printing " << pages << " pages" << endl;
    }
};

class Scanner : virtual public Device
{
protected:
    int resolution;

public:
    Scanner(float p, int r) : Device(p)
    {
        resolution = r;
    }

    void operate()
    {
        cout << "Scanning at " << resolution << " dpi" << endl;
    }
};

class Photocopier : public Printer, public Scanner
{
public:
    Photocopier(float p, int pg, int r)
        : Device(p), Printer(p, pg), Scanner(p, r)
    {
    }

    void operate()
    {
        Printer::operate();
        Scanner::operate();
    }
};

int main()
{
    Photocopier obj(150.5, 20, 600);

    Device *ptr = &obj;

    ptr->operate();

    cout << "Power Consumption: " << ptr->powerConsumption << endl;

    return 0;
}