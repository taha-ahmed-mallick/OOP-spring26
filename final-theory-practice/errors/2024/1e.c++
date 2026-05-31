#include <iostream>
using namespace std;

class Vehicle
{
public:
    Vehicle() { cout << "Vehicle constructor called." << endl; }
    virtual ~Vehicle() { cout << "Vehicle destructor called." << endl; }
    virtual void display() const { cout << "Displaying Vehicle." << endl; }
};
class Car : public Vehicle
{
public:
    Car() { cout << "Car constructor called." << endl; }
    ~Car() { cout << "Car destructor called." << endl; }
    void display() const { cout << "Displaying Car." << endl; }
};
int main()
{
    Vehicle *vehiclePtr = new Car();
    vehiclePtr->display();
    delete vehiclePtr;
}