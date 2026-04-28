#include <iostream>
using namespace std;

template <typename T>

T add(T a, T b)
{
    return a + b;
}

template <typename T>

T maxima(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    cout << add<int>(2, 3) << endl;
    cout << add<string>("Hello", ", world!") << endl;
    cout << add<float>(2.3, 3.14) << endl;
    cout << add<bool>(true, false) << endl;
    cout << maxima<int>(2, 3) << endl;
    cout << maxima<string>("Hello", ", world!") << endl;
    cout << maxima<float>(2.3, 3.14) << endl;
    cout << maxima<bool>(true, false) << endl;
    return 0;
}