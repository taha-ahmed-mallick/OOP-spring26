#include <iostream>
using namespace std;
class Complex
{
private:
    float real, imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}
    Complex Add(Complex const &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void display() { cout << real << imag << endl; }
};
int main()
{
    Complex c1(3, 2), c2(1, 7);
    //   Complex result = c1 + c2;
    //   result.display();
}