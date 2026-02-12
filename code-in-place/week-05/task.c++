#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
};

class Student : public virtual Person {
protected:
    int rollNumber;
};

class Employee : public virtual Person {
protected:
    int employeeId;
};

class TA : public Student, public Employee {
public:
    TA(string n, int a, int r, int e) {
        name = n;
        age = a;
        rollNumber = r;
        employeeId = e;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Employee ID: " << employeeId << endl;
    }
};

int main() {
    TA ta("Taha", 18, 25183, 1515);
    ta.display();
    return 0;
}