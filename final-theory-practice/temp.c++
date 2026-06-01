#include <iostream>
using namespace std;
template <typename T>
void add(T a, T b) {
    cout << "template";
}

void add(int a, int b) {
    cout << "normal";
}

int main() {
    add(1, 2);
    add<>(1, 2);
    add<int>(1, 2);
    return 0;
}