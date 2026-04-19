#include <iostream>
using namespace std;

class Cmplx
{
private:
    int r, i;

public:
    Cmplx() : r(0), i(0) {}
    Cmplx(int r, int i) : r(r), i(i) {}

    Cmplx operator+(const Cmplx &c)
    {
        return Cmplx(r + c.r, i + c.i);
    }
    Cmplx operator-(const Cmplx &c)
    {
        return Cmplx(r - c.r, i - c.i);
    }

    void display()
    {
        cout << r << " + " << i << "i" << endl;
    }
};

int main() {
    Cmplx a(1, 2), b(3, 4);
    Cmplx c = a + b;
    c.display();
    c = a - b;
    c.display();
    return 0;
}