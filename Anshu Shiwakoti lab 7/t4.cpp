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
    int printSpeed;

public:
    Printer(float p, int s) : Device(p)
    {
        printSpeed = s;
    }

    void operate()
    {
        cout << "Printer Operating" << endl;
        cout << "Print Speed = " << printSpeed << " ppm" << endl;
    }
};

class Scanner : virtual public Device
{
protected:
    int scanResolution;

public:
    Scanner(float p, int r) : Device(p)
    {
        scanResolution = r;
    }

    void operate()
    {
        cout << "Scanner Operating" << endl;
        cout << "Scan Resolution = " << scanResolution << " dpi" << endl;
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
        cout << "Photocopier Operating" << endl;

        Printer::operate();
        Scanner::operate();
    }
};

int main()
{
    Photocopier pc(250.5, 30, 1200);

    Device *ptr = &pc;

    ptr->operate();

    cout << "\nPower Consumption = "
         << ptr->powerConsumption << " Watts" << endl;

    return 0;
}