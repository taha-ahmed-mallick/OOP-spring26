#include <iostream>
using namespace std;

// Base Class
class Account
{
protected:
    double balance;

public:
    Account()
    {
        cout << "initial balance: ";
        cin >> balance;
    }

    Account(double balance)
    {
        this->balance = balance;
    }

    virtual void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance!\n";
        }
    }

    void checkBalance()
    {
        cout << "Balance: " << balance << endl;
    }

    double getBalance()
    {
        return balance;
    }

    void setBalance(double b)
    {
        balance = b;
    }
};

// Derived Class: InterestAccount
class InterestAccount : public Account
{
protected:
    double interest;

public:
    InterestAccount() : Account() {}

    InterestAccount(double b) : Account(b) {}

    void deposit(double amount)
    {
        interest = amount * 0.30;
        balance += amount + interest;
        cout << "Deposited with interest (30%): " << amount + interest << endl;
    }
};

// Derived Class: ChargingAccount
class ChargingAccount : public Account
{
protected:
    double fee = 25;

public:
    ChargingAccount() : Account() {}

    ChargingAccount(double b) : Account(b) {}

    void withdraw(double amount)
    {
        double total = amount + fee;

        if (total <= balance)
        {
            balance -= total;
            cout << "Withdrawn: " << amount << " with fee Rs.25\n";
        }
        else
        {
            cout << "Insufficient balance including fee!\n";
        }
    }
};

class ACI
{
public:
    void transfer(double amount, Account &acc)
    {
        acc.deposit(amount);
        cout << "Transferred " << amount << " to Account\n";
    }

    void transfer(double amount, InterestAccount &acc)
    {
        acc.deposit(amount);
        cout << "Transferred " << amount << " to InterestAccount\n";
    }

    void transfer(double amount, ChargingAccount &acc)
    {
        acc.deposit(amount);
        cout << "Transferred " << amount << " to ChargingAccount\n";
    }
};

int main()
{
    cout << "Enter Account 1 ";
    Account acc1;
    cout << "Enter Account 2 ";
    InterestAccount acc2;
    cout << "Enter Account 3 ";
    ChargingAccount acc3;

    cout << endl;
    acc1.deposit(1000);
    acc2.deposit(1000);
    cout << endl;
    acc1.withdraw(500);
    acc3.withdraw(200);
    cout<<endl;

    cout << "Account 1:- " << endl;
    acc1.checkBalance();
    cout << "Account 2:- " << endl;
    acc2.checkBalance();
    cout << "Account 3:- " << endl;
    acc3.checkBalance();

    ACI obj;
    cout<<endl;
    obj.transfer(300, acc1);
    obj.transfer(300, acc2);
    obj.transfer(300, acc3);
    cout<<endl;

    cout << "Account 1:- " << endl;
    acc1.checkBalance();
    cout << "Account 2:- " << endl;
    acc2.checkBalance();
    cout << "Account 3:- " << endl;
    acc3.checkBalance();

    return 0;
}