#include <iostream>
using namespace std;

int main() {
    int a = 5;
    cout << typeid(a).name() << endl;
    return 0;
}