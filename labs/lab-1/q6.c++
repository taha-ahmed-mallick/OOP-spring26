#include <iostream>
using namespace std;

void withdrawal_Logic(long long *accountNumber, int *amount, int *balance, int tax, float fee, char accountType)
{
    cout << "Enter your Account Number: ";
    cin >> *accountNumber;
    cout << "Enter Amount to Withdraw: ";
    cin >> *amount;
    if (*amount <= *balance)
    {
        if (*amount > 100000)
        {
            cout << "You Exceed Maximum Range of Withdrawal " << endl;
        }
        else
        {
            *balance -= *amount;
            *balance -= (accountType == 's' || accountType == 'S') ? *amount *
                                                                         fee
                                                                   : 100;
            if (*amount > 50000)
            {
                *balance -= *balance * (tax * 1.0 / 100);
            }
            cout << endl
                 << "Account Number: " << *accountNumber << endl;
            cout << "Withdrawal Amount: " << *amount << endl;
            cout << "Balance: " << *balance << endl;
        }
    }
    else
    {
        cout << "Insufficient Balance" << endl;
    }
}

int main()
{
    char accountType;
    int balance = 200000, amount = 0;
    long long accountNumber = 0;
    cout << "Bank Withdrawal System" << endl;
    cout << "Enter Account Type(S for Saving and C for Current): ";
    cin >> accountType;
    if (accountType == 'S' || accountType == 's')
    {
        withdrawal_Logic(&accountNumber, &amount, &balance, 5, 0.02, accountType);
    }
    else if (accountType == 'C' || accountType == 'c')
    {
        withdrawal_Logic(&accountNumber, &amount, &balance, 5, 100, accountType);
    }
    else
    {
        cout << "Please Enter Valid Account Type" << endl;
    }
    cout << endl;
    return 0;
}