#include <iostream>
using namespace std;

void abc(const char * ch) {
    cout << ch << endl;
}

int main() {
    abc(nullptr);
    return 0;
}