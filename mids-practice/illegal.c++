#include <iostream>
using namespace std;

class Test {
    int x;
    const int y;
public:
    Test(int a, int b) : y(b), x(a) {}
    void display() {
        cout << "x: " << x << ", y: " << y << endl;
    }
    void func(int &x) const {
        // can't access x
        x++;
        // y++; // This will cause a compilation error because y is const
        cout << "Inside const function. y: " << y << endl;
    }

    int& getX() {
        return x;
    }
};

int main() {
    Test obj(5, 10);
    obj.display();
    obj.func(obj.getX()); // This will modify x in a const function
    obj.display();
    return 0;
}