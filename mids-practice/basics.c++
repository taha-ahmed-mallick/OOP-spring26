#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* b = &a;
    int c = *b;
    cout << "Value of a: " << a << endl;
    cout << "Value of b (address of a): " << b << endl;
    cout << "Value of c (dereferenced pointer): " << c << endl;
    int *p = new int;
    *p = 5;
    cout << "Value of p (address of dynamically allocated int): " << p << endl;
    cout << "Value at p (dereferenced pointer): " << *p << endl;
    NULL;
    cout << "Value of NULL: " << NULL << endl;
    nullptr;
    int *nil = nullptr;
    cout << "Value of nil (nullptr): " << nil << endl;
    // cout << "Value of nullptr: " << **nullptr << endl;
    *nil = 5; // This will cause a runtime error (segmentation fault) because nil is a null pointer
    return 0;
}