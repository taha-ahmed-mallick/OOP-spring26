#include <iostream>
using namespace std;

class SmartDevice
{
    const int id;
    int batteryLevel;

public:
    SmartDevice(int id, int batteryLevel) : id(id), batteryLevel(batteryLevel) {}
    void setBatteryLevel(int level)
    {
        if (level >= 0 && level <= 100)
            batteryLevel = level;
        else
            cout << "Battery level must be between 0 and 100." << endl;
    }
    // Const getter methods which do not modify the state of the object
    int getId() const { return id; }
    int getBatteryLevel() const { return batteryLevel; }
};

int main()
{
    SmartDevice device1(1, 75);
    cout << "Device ID: " << device1.getId() << endl;
    cout << "Battery Level: " << device1.getBatteryLevel() << "%" << endl;
    device1.setBatteryLevel(85);
    cout << "Updated Battery Level: " << device1.getBatteryLevel() << "%" << endl;
    return 0;
}