#include <iostream>
using namespace std;

template <class T, class U, class V = double>
class A
{
public:
    T x;
    U y;
    V z;
    static const int count;
    void trying()
    {
        cout << count << endl;
    }
};
int main()
{
    A<int, int> a;
    A<double, double> b;
    cout << sizeof(a.x) << endl;
    cout << sizeof(b.z) << endl;
    return 0;
}