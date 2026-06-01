#include <iostream>
using namespace std;

template<class T>
T maxOf(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << maxOf(3, 7) << endl;
    // cout << maxOf(3, 7.5) << endl;
    return 0;
}