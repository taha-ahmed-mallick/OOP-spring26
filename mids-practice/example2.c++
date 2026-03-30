#include <iostream>
using namespace std;
class A
{ // single base class
public:
    int x, y;
    A(int val1, int val2) : x(val1), y(val2)
    {
        cout << "A class constructor called with values: " << val1 << ", " << val2 << endl;
    }
    void getdata()
    {
        cout << "\n Enter value of x and y:\n";
        cin >> x >> y;
    }
};
class B : public A
{ // B is derived from class base
public:
    int z;
    B(int val1, int val2, int val3) : A(val1, val2), z(val3)
    {
        cout << "B class constructor called with value: " << val3 << endl;
    }
    void product()
    {
        cout << "\n Product= " << x * y * z;
    }
};
class C : public A
{ // C is also derived from class base
public:
    void sum()
    {
        cout << "\n Sum= " << x + y;
    }
    C(): A(0, 0) {
        cout << "C class default constructor called." << endl;
    }
    C(int v1, int v2) : A(v1, v2) {}
};
int main()
{
    B obj1(2, 3, 4); // object of derived class B
    C obj2;          // object of derived class C
    obj1.product();
    obj2.getdata();
    obj2.sum();
    return 0;
} // end of program
