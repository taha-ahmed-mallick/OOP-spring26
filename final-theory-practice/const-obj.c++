#include <iostream>
using namespace std;

class A {
    public:
    int a;
    A(int a) : a(a) {}
    void setA(int a) {this->a = a;}
};

int main() {
    const A a(5);
    cout << a.a;
    // a.a= 6;
    return 0;
}