#include <iostream>
using namespace std;

class Number {
    public:
    int x;
    Number() : x(0) {}
    Number(int x) : x(x) {}
    void operator-() {
        x = -x;
    }
};

int main() {
    Number a(5);
    -a;
    cout << a.x << endl;
    return 0;
}