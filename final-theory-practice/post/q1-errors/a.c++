#include <iostream>
using namespace std;

int divide(int a, int b)
{
    if (b == 0)
        throw runtime_error("division by zero.");
    if (b < 0)
        throw invalid_argument("negative divisor.");
    return a / b;
}

int main()
{
    try {cout << divide(10, -2) << endl;}
    catch(exception& e) {
        cout << "generic: " << e.what() << endl;
    } catch(invalid_argument& e) {
        cout << "invalid: " << e.what() << endl;
    } catch(runtime_error& e) {
        cout << "runtime: " << e.what() << endl;
    }
    return 0;
}
// does give warning tho but runs invalid_arg block