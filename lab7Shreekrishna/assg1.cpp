#include <iostream>
using namespace std;

class Device
{
protected:
    float powerConsumption;

public:
    Device(float p)
    {
        powerConsumption = p;
    }

    virtual void operate() = 0;
};

class Printer : virtual public Device
{
    int printSpeed;

public:
    Printer(float p, int ps) : Device(p)
    {
        printSpeed = ps;
    }

    void operate()
    {
        cout << "Printer is operating" << endl;
        cout << "Print Speed: " << printSpeed << " ppm" << endl;
    }
};

class Scanner : virtual public Device
{
    int scanResolution;

public:
    Scanner(float p, int sr) : Device(p)
    {
        scanResolution = sr;
    }

    void operate()
    {
        cout << "Scanner is operating" << endl;
        cout << "Scan Resolution: " << scanResolution << " dpi" << endl;
    }
};

class Photocopier : public Printer, public Scanner
{
public:
    Photocopier(float p, int ps, int sr)
        : Device(p), Printer(p, ps), Scanner(p, sr)
    {
    }

    void operate()
    {
        cout << "Photocopier is operating" << endl;
        Printer::operate();
        Scanner::operate();
    }

    void show()
    {
        cout << "Power Consumption: " << powerConsumption << " W" << endl;
    }
};

int main()
{
    Photocopier p(500, 25, 1200);

    Device *d = &p;

    d->operate();
    p.show();

    return 0;
}