#include <iostream>
using namespace std;

class B;
class A
{
    int x;

public:
    A() : x(0) {}
    void setData(int a) { x = a; }
    friend void add(A, B);
};
class B
{
    int y;

public:
    B() : y(0) {}
    void setData(int b) { y = b; }
    friend void add(A objA, B objB)
    {
        cout << objA.x + objB.y;
    }
};

int main() { return 0; }