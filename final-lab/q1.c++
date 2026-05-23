#include <iostream>
using namespace std;

template <typename T1, typename T2>
void swapFunc(T1 &a, T2 &b)
{
    auto temp = a;
    a = static_cast<T1>(b);
    b = static_cast<T2>(temp);
}

int main()
{
    int x = 5, y = 6;
    cout << "Before Swap: x = " << x << ", y = " << y << endl;
    swapFunc(x, y);
    cout << "After Swap: x = " << x << ", y = " << y << endl;
    int a = 10;
    float b = 3.14;
    cout << "Before Swap: a = " << a << ", b = " << b << endl;
    swapFunc(a, b);
    cout << "After Swap: a = " << a << ", b = " << b << endl;
    cout << "LOST PRECISION due to type conversion" << endl;
    char c = 'A';
    int d = 97;
    cout << "Before Swap: c = " << c << ", d = " << d << endl;
    swapFunc(c, d);
    cout << "After Swap: c = " << c << ", d = " << d << endl;
    cout << "SWAPING between char and int." << endl;
    return 0;
}