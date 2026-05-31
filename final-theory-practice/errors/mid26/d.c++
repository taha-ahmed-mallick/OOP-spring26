#include <iostream>
using namespace std;

class CountDown {
public:
    static int count;
    CountDown() {count--;}
};

int CountDown::count = 10;

int main() {
    CountDown c1, c2, c3;
    cout << CountDown::count;
    return 0;
}