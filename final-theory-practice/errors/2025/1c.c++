#include <iostream>
using namespace std;

class Base
{
public:
    static int count;
    Base() { count++; }
    ~Base() { count--; }
    static void printCount() { cout << "Count: " << count << endl; }
};
class Derived : public Base
{
public:
    Derived() { count++; }
    ~Derived() { count--; }
};
int Base::count = 0;
int main()
{
    Base::printCount();
    Base obj1;
    Base *obj2 = new Derived;
    obj2->printCount();
    delete obj2;
    obj1.printCount();
}