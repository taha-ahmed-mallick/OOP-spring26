#include <iostream>
using namespace std;

template <typename T>
void swapping(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T1, typename T2>
void swapping(T1 &a, T2 &b)
{
    T1 tempA = a;
    T2 tempB = b;
    a = static_cast<T1>(tempB);
    b = static_cast<T2>(tempA);
}

int main()
{
    // Test Case 1: Swapping same type (int, int)
    int x = 10, y = 20;
    cout << "Before swapping (int, int): x = " << x << ", y = " << y << endl;
    swapping<int, int>(x, y); // Calls Version 1 automatically via compiler deduction
    cout << "After swapping  (int, int): x = " << x << ", y = " << y << endl;
    cout << "---------------------------------------------------" << endl;

    // Test Case 2: Combination of Different Types (int, double)
    int totalItems = 5;
    double averagePrice = 99.75;
    cout << "Before swapping (int, double): Items = " << totalItems << ", Price = " << averagePrice << endl;
    swapping<int, double>(totalItems, averagePrice); // Calls Version 2 automatically due to mismatching types
    cout << "After swapping  (int, double): Items = " << totalItems << ", Price = " << averagePrice << endl;
    cout << "---------------------------------------------------" << endl;

    // Test Case 3: Combination of Different Types (char, int)
    char letter = 'A'; // ASCII 65
    int num = 90;      // ASCII 'Z'
    cout << "Before swapping (char, int): letter = " << letter << ", num = " << num << endl;
    swapping<char, int>(letter, num); // Calls Version 2
    cout << "After swapping  (char, int): letter = " << letter << ", num = " << num << endl;
    return 0;
}