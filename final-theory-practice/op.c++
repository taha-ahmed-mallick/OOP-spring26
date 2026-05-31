#include <iostream>
using namespace std;

class A
{
    int x;

public:
    A(int v) : x(v) {}

    friend int operator+(int lhs, const A &rhs);

    int operator+(int val)
    {
        return val + this->x;
    }

    int operator++(int)
    {
        return ++this->x;
    }
    friend int operator+(const A &lhs, const A &rhs);
    int operator+(const A &other)
    {
        return this->x + other.x;
    }
};

int operator+(int lhs, const A &rhs)
{
    return lhs + rhs.x;
}

int operator+(const A &lhs, const A &rhs)
{
    return lhs.x + rhs.x;
}

int main()
{
    A a(10), b(3);
    cout << 5 + a << " " << a + 5 << endl
         << a++ << endl
         << a + b;
    return 0;
}