#include <iostream>
using namespace std;

class Abc
{
    int x;
    char a;

public:
    Abc(int x, char a) : x(x), a(a) {}
};

int main()
{
    Abc a(1, 'A');
    cout << sizeof(Abc) << " " << &a << " " << sizeof(int) << " " << sizeof(char);
    return 0;
}