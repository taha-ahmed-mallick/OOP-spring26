#include <iostream>
using namespace std;

class Cmplx {
private:
    int r, i;
public:
    Cmplx(int r = 0, int i = 0) : r(r), i(i) {}

    Cmplx operator+(const Cmplx& c) {
        return Cmplx(r + c.r, i + c.i);
    }

    Cmplx operator-(const Cmplx& c) {
        return Cmplx(r - c.r, i - c.i);
    }

    void display() {
        cout << r << " + " << i << "i" << endl;
    }
};

int main() {
    Cmplx c1(3, 4);
    Cmplx c2(1, 2);
    Cmplx c3 = c1 + c2;
    // c1 calls it and c2 is in the parameter list, so c1 is the left operand and c2 is the right operand
    c1.display();
    c2.display();
    c3.display();

    return 0;
}