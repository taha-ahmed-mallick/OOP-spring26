#include <iostream>
using namespace std;

class A
{
public:
    void square(int *x)
    {
        (*x)++;
        *x = (*x) * (*x);
    }
    void square(int *x, int *y)
    {
        --(*y);
        *x = (*x) * (*y);
    }
};
int main()
{
    A obj;
    int number = 10;
    obj.square(&number, &number);
    cout << number;
}