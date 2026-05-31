#include <iostream>
using namespace std;

int main()
{
    int x = 10, y = 20;
    int *ptr = &x;
    y = 5;
    cout << *ptr;
    int const a = 5;
    return 0;
}