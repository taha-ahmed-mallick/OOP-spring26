#include <iostream>
using namespace std;

class BankAcc {
private:
    double balance;
public:
    BankAcc(double b) {
        balance = b;
    }
};

int main() {
    BankAcc acc(5000);
    // cout << acc.balance;
    return 0;
}