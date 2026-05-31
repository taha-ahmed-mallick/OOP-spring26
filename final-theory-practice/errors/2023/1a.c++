#include <iostream>
using namespace std;

template <typename T>
void test(const T &x)
{
    static int count = 0;
    cout << "x = " << x << " count = " << count << endl;
    ++count;
    return;
}
int main()
{
    test<int>(2);
    test<int>(2);
    test<double>(2.2);
}