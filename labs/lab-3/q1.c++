#include <iostream>
using namespace std;

class Complex
{
public:
    float *real;
    float *img;

    void getComplex()
    {
        cout << "Complex Number: " << *real << "+" << *img << "i " << endl;
    }

    Complex(Complex &obj)
    {
        real = new float(*(obj.real));
        img = new float(*(obj.img));
    }

    Complex(float x, float y)
    {
        real = new float(x);
        img = new float(y);
    }
};

int main()
{
    Complex num1(2, 5);
    Complex num2 = num1;
    num1.getComplex();
    num2.getComplex();

    *(num1.real) = 8;
    *(num1.img) = 7;

    num1.getComplex();
    num2.getComplex();

    return 0;
}