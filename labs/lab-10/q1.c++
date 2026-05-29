#include <iostream>
using namespace std;

template <typename T1, typename T2>

class Calc
{
private:
    T1 a;
    T2 b;

public:
    Calc(T1 a, T1 b) : a(a), b(b) { this->display(); }
    auto add() const { return a + b; }
    auto sub() const { return a - b; }
    auto mul() const { return a * b; }
    auto div() const
    {
        if (b == 0)
            throw runtime_error("Can't divide by zero.");
        return static_cast<double>(a) / b;
    }
    void display()
    {
        cout << "Addition:\t" << add() << endl;
        cout << "Subtraction:\t" << sub() << endl;
        cout << "Multiplication:\t" << mul() << endl;
        try
        {
            double res = div();
            cout << "Division:\t" << res << endl;
        }
        catch (runtime_error &e)
        {
            cout << e.what() << endl;
        }
    }
};

int main()
{
    int num1 = 3, num2 = 7;
    cout << "Calculation of same type <int, int>"<< endl;
    cout << "Numbers are: " << num1 << ", " << num2 << endl;
    Calc<int, int> calc1(num1, num2);

    double dbl = 2.78;
    cout << "Calculation of diff data type <int, double>" << endl;
    cout << "Numbers are: " << num1 << ", " << dbl << endl;
    Calc<int, double> calc2(num1, dbl);
    return 0;
}