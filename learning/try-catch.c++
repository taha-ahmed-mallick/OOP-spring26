#include <iostream>
using namespace std;
int main()
{
    int a = 10, b = 0;
    try
    {
        if (b == 0)
            throw "Division by zero error";
        cout << "Result: " << a / b;
    }
    catch (const char *msg)
    {
        cout << "Error: " << msg;
    }
    return 0;
}