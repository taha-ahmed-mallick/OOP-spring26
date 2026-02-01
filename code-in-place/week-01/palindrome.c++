#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    long y = 0;
    int temp = x;
    while (x != 0) {
        y = y * 10 + (x % 10);
        x /= 10;
    }
    if (temp == y)
        return true;
    else
        return false;
}

int main() {
    cout << "Enter an integer: ";
    int num;
    cin >> num;
    if (isPalindrome(num))
        cout << num << " is a palindrome." << endl;
    else
        cout << num << " is not a palindrome." << endl;
    return 0;
}