#include <iostream>
using namespace std;

class Base
{
public:
    static int count;

    Base()
    {
        count++;
        cout << "BC" << endl;
    }
    virtual ~Base()
    {
        count--;
        cout << "BD" << endl;
    }

    static void printCount()
    {
        cout << "Count: " << count << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        count++;
        cout << "DC" << endl;
    }
    ~Derived()
    {
        count--;
        cout << "DD" << endl;
    }
};

int Base::count = 0;

int main()
{
    Base::printCount();
    Base obj1;
    Derived *obj2 = new Derived;

    obj2->printCount();

    delete obj2;

    obj1.printCount();
}