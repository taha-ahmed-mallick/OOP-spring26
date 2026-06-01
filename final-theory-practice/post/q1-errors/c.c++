#include <iostream>
using namespace std;

class Base {
    friend class Helper;
private: int data = 10;
};

class Derived: public Base {
    private: int extra = 20;
};

class Helper {
    public:
    void show(Base &b) {cout << b.data << endl;}
    void show(Derived& d) {cout << d.data << " " /*<< d.extra*/ << endl;}
};

// the commented part throws an error.

int main() {
    Derived d;
    Helper h;
    h.show(d);
    return 0;
}