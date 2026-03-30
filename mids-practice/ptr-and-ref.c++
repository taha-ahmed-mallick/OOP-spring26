#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* b = &a;
    int const *p1;
    p1 = &a;
    //*p1 = 10; // This will cause a compile-time error because p1
    p1 = b; // This is allowed because p1 is a pointer to a constant integer, not a constant pointer
    int* const p2 = b, p3 = a;
    // p2 = &a; // This will cause a compile-time error because p2 is a constant pointer and cannot point to another address
    void *ptr = &a;
    cout << "void ptr: " << *(static_cast<int*>(ptr)) << endl;

    int f = 5;
    int& g = f;
    int h = g;
    cout << "Value of f: " << f << endl;
    cout << "Value of g: " << g << endl;
    cout << "Value of h: " << h << endl;
    f = 10;
    cout << "Value of f: " << f << endl;
    cout << "Value of g: " << g << endl;
    cout << "Value of h: " << h << endl;
    return 0;
}