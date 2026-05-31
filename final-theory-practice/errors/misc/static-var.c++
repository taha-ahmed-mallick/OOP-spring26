#include <iostream>
using namespace std;

class MyClass
{
public:
    static int count;
    MyClass() { count++; }
    ~MyClass() { count--; }
};
int MyClass::count = 0;
int main()
{
    MyClass obj1;
    MyClass *ptr = new MyClass;
    cout << MyClass::count;
    delete ptr;
    cout << MyClass::count;
}