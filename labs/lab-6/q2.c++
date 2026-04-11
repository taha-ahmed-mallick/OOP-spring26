#include <iostream>
using namespace std;

class Calculator
{
private:
    float num1, num2, num3;

public:
    Calculator()
    {
        cout << "Enter three numbers: ";
        cin >> num1 >> num2 >> num3;
    }
    float add(float a, float b)
    {
        return a + b;
    }
    float add(float a, float b, float c)
    {
        return a + b + c;
    }
    float multiply(float a, float b)
    {
        return a * b;
    }
    float multiply(float a, float b, float c)
    {
        return a * b * c;
    }
    float subtract(float a, float b)
    {
        return a - b;
    }
    float divide(float a, float b)
    {
        if (b != 0)
        {
            return a / b;
        }
        else
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }

    void display()
    {
        cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
        cout << num1 << " + " << num2 << " + " << num3 << " = " << add(num1, num2, num3) << endl;
        cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
        cout << num1 << " * " << num2 << " * " << num3 << " = " << multiply(num1, num2, num3) << endl;
        cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
        cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
    }
};

int main()
{
    Calculator calc;
    calc.display();
    return 0;
}