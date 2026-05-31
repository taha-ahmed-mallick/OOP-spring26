#include <iostream>
using namespace std;

class Base
{
    virtual void display() = 0;
};
class Child : public Base
{
public:
    void display() { cout << "Never Give up!!!" << endl; }
};
int main()
{
    Child obj;
    obj.display();
    // Base obj2;
    // obj2.display();
}