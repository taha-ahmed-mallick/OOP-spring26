#include <iostream>
using namespace std;

int main() {
    cout << "Enter an integer: ";
    int num;
    cin >> num;
    if (num % 2)
        cout << num << " is odd." << endl;
    else
        cout << num << " is even." << endl;
    return 0;
}