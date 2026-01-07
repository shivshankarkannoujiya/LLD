#include <iostream>
using namespace std;

class Car
{
protected:
    string name;
    string model;
    int enginecc;

public:
    Car(string n, string m, int e) : name(n), model(m), enginecc(e) {};

    void displayBasicInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Model: " << model << endl;
        cout << "Engine: " << enginecc << " cc" << endl;
    }
};

class ManualCar : public Car
{
private:
    int gears;

public:
    ManualCar(string n, string m, int e, int gears) : Car(n, m, e)
    {
        this->gears = gears;
    }

    void displayManualInfo()
    {
        cout << "--- Manual Car Details ---" << endl;
        displayBasicInfo();
        cout << "Gears: " << gears << endl;
        cout << "--------------------------" << endl;
    }
};

class ElectricCar : public Car
{
private:
    int batteryCapacity;

public:
    ElectricCar(string n, string m, int e, int batteryCapacity) : Car(n, m, e)
    {
        this->batteryCapacity = batteryCapacity;
    }

    void displayElectricInfo()
    {
        cout << "--- Electric Car Details ---" << endl;
        displayBasicInfo();
        cout << "Battery: " << batteryCapacity << " kWh" << endl;
        cout << "----------------------------" << endl;
    }
};

int main()
{
    ManualCar mCar("Toyota", "Fortuner", 2800, 6);
    mCar.displayManualInfo();

    ElectricCar eCar("Tesla", "Model S", 0, 100);
    eCar.displayElectricInfo();
}