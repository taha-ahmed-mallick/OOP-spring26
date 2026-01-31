#include <iostream>
using namespace std;

class Cmplx
{
public:
    // variables
    float *real, *img;

    // display functions
    void getComplex()
    {
        cout << "\tComplex Number: " << *real << " + " << *img << "i " << endl;
    }

    // constructors
    Cmplx(float a, float b)
    {
        real = new float(a);
        img = new float(b);
    }

    Cmplx(const Cmplx &obj)
    {
        real = new float(*(obj.real));
        img = new float(*(obj.img));
    }
};

int main()
{
    Cmplx num1(2, 5);
    Cmplx num2 = num1;
    cout << "====Copying the Complex Number====" << endl << endl;
    num1.getComplex();
    num2.getComplex();

    *(num1.real) = 8;
    *(num1.img) = 10;

    cout << endl << "====Changing the FIRST Complex Number====" << endl << endl;
    num1.getComplex();
    num2.getComplex();

    return 0;
}