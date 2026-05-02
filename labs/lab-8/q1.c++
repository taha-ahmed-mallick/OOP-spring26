#include <iostream>
using namespace std;

class Vehicle
{
    string type, make, color, model;
    int year, miles;

public:
    Vehicle(string type, string make, string color, string model, int year, int miles) : type(type), make(make), color(color), model(model), year(year), miles(miles) {}

    void displayVehicle()
    {
        cout << "INFO:-" << endl
             << "Type: " << type << endl
             << "Make: " << make << endl
             << "Model: " << model << endl
             << "Color: " << color << endl
             << "Year: " << year << endl
             << "Miles: " << miles << endl;
    }
};

class GasVehicle : virtual public Vehicle
{
    float tankSize;

public:
    GasVehicle(string type, string make, string color, string model, int year, int miles, float tankSize) : Vehicle(type, make, color, model, year, miles), tankSize(tankSize) {}

    void displayGasVehicle()
    {
        cout << "Fuel Tank capacity: " << tankSize << "ltr" << endl;
    }
};

class ElectricVehicle : virtual public Vehicle
{
    float energyStorage;

public:
    ElectricVehicle(string type, string make, string color, string model, int year, int miles, float energy) : Vehicle(type, make, color, model, year, miles), energyStorage(energy) {}

    void displayElectricVehicle()
    {
        cout << "Energy storage: " << energyStorage << "kWh" << endl;
    }
};

class HighPerformace : public GasVehicle
{
    int hp, topSpeed;

public:
    HighPerformace(string type, string make, string color, string model, int year, int miles, float tankSize, int hp, int topSpeed) : Vehicle(type, make, color, model, year, miles), GasVehicle(type, make, color, model, year, miles, tankSize), hp(hp), topSpeed(topSpeed) {}

    void displayHighPerformance()
    {
        displayVehicle();
        displayGasVehicle();
        cout << "Engine Power: " << hp << "hp" << endl
             << "Top speed: " << topSpeed << endl;
    }
};

class SportsCar : public HighPerformace
{
public:
    string gearBox, driveSys;

    SportsCar(string type, string make, string color, string model, int year, int miles, float tankSize, int hp, int topSpeed, string gearBox, string driveSys) : Vehicle(type, make, color, model, year, miles), HighPerformace(type, make, color, model, year, miles, tankSize, hp, topSpeed), gearBox(gearBox), driveSys(driveSys) {}

    void dislplaySportsCar()
    {
        displayHighPerformance();
        cout << "Gear Box: " << gearBox << endl
             << "Drive System: " << driveSys << endl;
    }
};

class HeavyVehicle : public GasVehicle, public ElectricVehicle
{
    int maxWeight, wheels, length;

public:
    HeavyVehicle(string type, string make, string color, string model, int year, int miles, float tankSize, float energy, int maxWeight, int wheels, int length) : Vehicle(type, make, color, model, year, miles), GasVehicle(type, make, color, model, year, miles, tankSize), ElectricVehicle(type, make, color, model, year, miles, energy), maxWeight(maxWeight), wheels(wheels), length(length) {}

    void displayHeavyVehicle()
    {
        displayVehicle();
        displayGasVehicle();
        displayElectricVehicle();
        cout << "Max Weight: " << maxWeight << "kgs" << endl
             << "Number of wheels: " << wheels << endl
             << "Length: " << length << "m" << endl;
    }
};

class ConstructionTruck : public HeavyVehicle
{
public:
    string cargo;

    ConstructionTruck(string type, string make, string color, string model, int year, int miles, float tankSize, float energy, int maxWeight, int wheels, int length, string cargo) : Vehicle(type, make, color, model, year, miles), HeavyVehicle(type, make, color, model, year, miles, tankSize, energy, maxWeight, wheels, length), cargo(cargo) {}

    void displayConstructionTruck()
    {
        displayHeavyVehicle();
        cout << "Cargo: " << cargo << endl;
    }
};

class Bus : public HeavyVehicle
{
    int numSeats;

public:
    Bus(string type, string make, string color, string model, int year, int miles, float tankSize, float energy, int maxWeight, int wheels, int length, int numSeats) : Vehicle(type, make, color, model, year, miles), HeavyVehicle(type, make, color, model, year, miles, tankSize, energy, maxWeight, wheels, length), numSeats(numSeats) {}

    void displayBus()
    {
        displayHeavyVehicle();
        cout << "Number of seats: " << numSeats << endl;
    }
};

int main()
{
    Bus bus("Coach", "HINO", "White", "Hino Melpha", 2022, 25000, 500, 150, 500, 4, 60, 80);
    bus.displayBus();
    return 0;
}