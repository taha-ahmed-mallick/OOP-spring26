#include <iostream>
// #include <exception> it runs even without it
using namespace std;
int main()
{
    try
    {
        throw runtime_error("Runtime error occurred");
    }
    catch (exception &e)
    {
        cout << e.what();
    }
}