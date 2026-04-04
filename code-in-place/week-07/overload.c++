#include <iostream>
using namespace std;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
    int add(int a, int b, int c)
    {
        return a + b + c;
    }
    int add(double a, double b)
    {
        return a + b;
    }
    int multiply(int a, int b)
    {
        return a * b;
    }
    int multiply(int a, int b, int c)
    {
        return a * b * c;
    }
    int subtract(int a, int b)
    {
        return a - b;
    }
    double divide(double a, double b)
    {
        if (b == 0)
        {
            cout << "err" << endl;
            return 0;
        }
        return a / b;
    }
};

int main() {
    Calculator calc;
    cout << "Addition of 2 numbers: " << calc.add(5, 10) << endl;
    cout << "Addition of 3 numbers: " << calc.add(5, 10, 15) << endl;
    cout << "Addition of 2 doubles: " << calc.add(5.5, 10.5) << endl;
    cout << "Multiplication of 2 numbers: " << calc.multiply(5, 10) << endl;
    cout << "Multiplication of 3 numbers: " << calc.multiply(5, 10, 15) << endl;
    cout << "Subtraction of 2 numbers: " << calc.subtract(10, 5) << endl;
    cout << "Division of 2 numbers: " << calc.divide(10, 5) << endl;
    cout << "Division by zero: " << calc.divide(10, 0) << endl;
    return 0;
}