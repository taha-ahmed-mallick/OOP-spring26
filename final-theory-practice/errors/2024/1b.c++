#include <iostream>
using namespace std;

class MathUtility
{
public:
    static int divide(int a, int b)
    {
        if (b == 0)
        {
            cout << "Division by zero error";
            exit(1);
        }
        return a / b;
    }
};
int main()
{
    int result;
    cout << MathUtility::divide(10, 2) << endl;
    cout << MathUtility::divide(8, 0) << endl;
}