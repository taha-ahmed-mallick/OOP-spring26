#include <iostream>
using namespace std;

class Account
{
    int acc_no = 0, acc_bal = 0, security_code = 0;
    static int acc_count;

public:
    Account() { acc_count++; }

    void setAccNo(int acc_no) { this->acc_no = acc_no; }
    void setAccBal(int acc_bal) { this->acc_bal = acc_bal; }
    void setSecurityCode(int security_code) { this->security_code = security_code; }

    int getAccNo() const { return acc_no; }
    int getAccBal() const { return acc_bal; }
    int getSecurityCode() const { return security_code; }

    static int getAccCount() { return acc_count; }

    ~Account() { acc_count--; }
};

int Account::acc_count = 0;

int main()
{

    cout << "Initial Account Count: " << Account::getAccCount() << endl;


    Account acc1, acc2;
    acc1.setAccNo(1001);
    acc1.setAccBal(5000);
    acc1.setSecurityCode(1234);
    acc2.setAccNo(1002);
    acc2.setAccBal(7500);

    cout << "\n=== Static Feature ===" << endl;
    cout << "Total Accounts Created: " << Account::getAccCount() << endl;
    
    cout << "\n=== Encapsulation Feature ===" << endl;
    cout << "Acc 1 [No: " << acc1.getAccNo() << " | Bal: " << acc1.getAccBal() << "]" << endl;
    cout << "Acc 2 [No: " << acc2.getAccNo() << " | Bal: " << acc2.getAccBal() << "]" << endl;

    cout << "\nAcc 1-> Security Code (via getter): " << acc1.getSecurityCode() << endl;

    return 0;
}