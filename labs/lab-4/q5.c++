#include <iostream>
using namespace std;

class Room
{
    int days;
    string customerName;
    static const double dailyRent;

public:
    Room(int days, const string customerName) : days(days), customerName(customerName) {}
    double calculateRent() const
    {
        if (days > 7)
            return dailyRent * (days - 1);
        else
            return dailyRent * days;
    }
    void displayBill() const
    {
        cout << "\n--- Hotel Mercato Receipt ---" << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Days of Stay : " << days << endl;
        cout << "Total Rent   : Rs. " << calculateRent() << endl;
        if (days > 7)
        {
            cout << "Status       : Discount Applied (1 Day Free!)" << endl;
        }
    }
};

const double Room::dailyRent = 1000.85;

int main()
{
    Room room1(10, "John Doe");
    room1.displayBill();
    return 0;
}