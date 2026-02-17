#include <iostream>
using namespace std;

class Number {
public:
    int value;
    // Constructor
    Number(int v) {
        value = v;
    }
    // Overload + operator
    Number operator + (Number n) {
        return Number(value + n.value);
    }
    // Overload * operator
    Number operator * (Number n) {
        return Number(value * n.value);
    }
/// Display function
 void show() {
 cout << value << endl;
 }
};
int main() {
 Number a(5), b(3);
 Number sum = a + b; // a.operator+(b)
 Number product = a * b; // a.operator*(b)
 cout << "Sum: ";
 sum.show();
 cout << "Product: ";
product.show();
 return 0;
}