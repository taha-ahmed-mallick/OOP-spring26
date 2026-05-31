#include <iostream>
using namespace std;

class Base
{
protected:
    int protectedVar;

public:
    Base() : protectedVar(0) {}
    void setProtectedVar(int value) { protectedVar = value; }
    int getProtectedVar() { return protectedVar; }
};
class Derived : protected Base
{
public:
    void printProtectedVar() { cout << protectedVar; }
};
int main()
{
    Derived derivedObj;
    // derivedObj.setProtectedVar(10);
    // cout << derivedObj.getProtectedVar();
    derivedObj.printProtectedVar();
}