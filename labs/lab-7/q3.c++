#include <iostream>
using namespace std;

class Employee {
private:
    string name, desg;
    double salary;
    const int id;
public:
    Employee() : name("N/A"), desg("N/A"), id(0), salary(0) {}
    Employee(string name, string desg, int id, double salary) : id(id) {
        this->name = name;
        this->desg = desg;
        this->salary = salary;
    }
    void details() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Designation: " << desg << endl;
        cout << "Salary: " << salary << endl<<endl;
    }

    friend class Payroll;
};

class Payroll {
public:
    void setSalary(Employee &emp, double salary) {
        emp.salary = salary;
    }
    void incSalary(Employee &emp, double percent) {
        emp.salary += emp.salary*percent/100;
    }
};

int main() {
    Employee emp("ABC", "Data Scientist", 5248, 500000);
    emp.details();

    Payroll p;
    p.setSalary(emp, 600000);

    cout << "Setting Salary:"<< endl;
    emp.details();

    p.incSalary(emp, 10);
    cout << "Increasing salary by 10%:"<<endl;
    emp.details();
    return 0;
}