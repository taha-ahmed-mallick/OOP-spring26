#include <iostream>
using namespace std;

class A {
    int a;
public:
    A(int a) : a(a) {cout << "INT";}
};

class A {
    float a;
public:
    A(float a) : a(a) {cout << "FLOAT";}
};

int main() {
    A(1);A(2.5);
    return 0;
}