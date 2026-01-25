#include <iostream>
using namespace std;

class BankAccount {
    public:
        BankAccount(double initialBalance) : balance(initialBalance) {}

        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
            }
        }

        void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
            }
        }

        double getBalance() {
            return balance;
        }
    private:
        double balance;
};

int main() {
    cout << "Hello, Bank Account!" << endl;
    BankAccount myAccount(0.0);
    bool run = true;
    do {
        cout << "Select options from below:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Current balance: ";
            cout << myAccount.getBalance() << endl;
            cout << "Enter amount to deposit: ";
            double depositAmount;
            cin >> depositAmount;
            myAccount.deposit(depositAmount);
            cout << "New balance: ";
            cout << myAccount.getBalance() << endl;
            break;
        case 2:
            cout << "Current balance: ";
            cout << myAccount.getBalance() << endl;
            cout << "Enter amount to withdraw: ";
            double withdrawAmount;
            cin >> withdrawAmount;
            myAccount.withdraw(withdrawAmount);
            cout << "New balance: ";
            cout << myAccount.getBalance() << endl;
            break;
        case 3:
            cout << "Current balance: ";
            cout << myAccount.getBalance() << endl;
            break;
        case 4:
            cout << "Exiting..." << endl;
            run = false;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    } while (run);
    return 0;
}