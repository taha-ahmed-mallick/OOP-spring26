#include <iostream>
using namespace std;

class A {
public:
    int x;
    A(): x(0) {
        cout << "Constructor of class A" << endl;
    }
};

int main() {
    A obj;
    cout << "Value of x: " << obj.x << endl;
    obj.x = 10;
    cout << "Value of x: " << obj.x << endl;
    obj = A(); // Re-initializing obj using the default constructor of class A
    cout << "Value of x after re-initialization: " << obj.x << endl;
    return 0;
}