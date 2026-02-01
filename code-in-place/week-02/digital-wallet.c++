#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
    string type; // "add" or "pay"
    double amount;
} transaction;

class DigitWallet
{
private:
    double balance;
    int transactionCount;
    vector<transaction> transactionHistory;

public:
    DigitWallet(double bal) : balance(bal), transactionCount(0) {}

    void addMoney(double amount)
    {
        if (amount <= 0)
            cout << "Invalid amount" << endl;
        else
        {
            balance += amount;
            transactionCount++;
            transactionHistory.push_back({"add", amount});
        }
    }

    void pay(double amount)
    {
        if (amount <= 0)
            cout << "Invalid amount" << endl;
        else if (amount > balance)
            cout << "Insufficient balance" << endl;
        else
        {
            balance -= amount;
            transactionCount++;
            transactionHistory.push_back({"pay", amount});
        }
    }

    double getBalance()
    {
        return balance;
    }

    int getTransactionCount()
    {
        return transactionCount;
    }

    void printTransactionHistory()
    {
        cout << "No.\tType\tAmount" << endl;
        for (int i = 0; i < transactionHistory.size(); i++)
            cout << i + 1 << ".\t" << transactionHistory[i].type << "\t" << transactionHistory[i].amount << endl;
    }
};

int main()
{
    DigitWallet wallet(100.0); // Initialize wallet with a balance of 100
    wallet.addMoney(50.0);
    wallet.pay(30.0);
    cout << "Balance: " << wallet.getBalance() << endl;
    cout << "Transaction Count: " << wallet.getTransactionCount() << endl;
    wallet.printTransactionHistory();
    return 0;
}