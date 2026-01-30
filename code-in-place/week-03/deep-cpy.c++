#include <iostream>
using namespace std;

class Example {
    int *x;
    public:
    Example(int a) {
        x = new int(a);
    }
    Example(Example &eg) {
        x = new int();
        *x = *(eg.x);
    }
    int getX() {
        return *x;
    }
    void setX(int a) {
        *x = a;
    }
};

int main() {
    Example eg1(10);
    Example eg2 = eg1;
    cout << eg1.getX() << endl;
    cout << eg2.getX() << endl;
    eg1.setX(5);
    cout << eg1.getX() << endl;
    cout << eg2.getX() << endl;
    return 0;
}