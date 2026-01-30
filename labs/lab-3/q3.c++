#include <iostream>
using namespace std;

class TollBooth
{
public:
    int totalCars;
    double totalMoney;

    void payingCart(int cars)
    {
        totalCars += cars;
        totalMoney += 0.50 * cars;
    }
    void displayCart()
    {
        cout << "Total Cars: " << totalCars << endl
             << "Total Money: " << totalMoney << "Rs" << endl
             << endl;
    }
    TollBooth()
    {
        totalCars = 0;
        totalMoney = 0;
    }
};

int main()
{

    TollBooth firstStation;

    cout << "Morning Shift:-" << endl;
    firstStation.payingCart(50);
    firstStation.displayCart();

    cout << "Evening Shift:-" << endl;
    firstStation.payingCart(100);
    firstStation.displayCart();

    cout << "Night Shift:-" << endl;
    firstStation.payingCart(10);
    firstStation.displayCart();
    return 0;
}