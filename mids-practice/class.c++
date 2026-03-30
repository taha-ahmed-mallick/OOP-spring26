#include <iostream>
using namespace std;

class Abc {
    // by default, members of a class are private
public:
    int x;
    static int count; // static member variable
    Abc(int val) : x(val) {}
    int getX() {return x;}
};

int Abc::count = 0; // initialize static member variable

class Def{
public:
    int y;
};

int main() {
    Abc obj(10), obj1(20);
    Abc::count++; // increment static member variable
    cout << "Value of x: " << obj.getX() << endl;
    Def obj2;
    cout << "Value of y: " << obj2.y << endl;
    obj2.y = 20;
    cout << "Value of y: " << obj2.y << endl;
    obj = obj1; // assignment operator
    cout << "Value of x after assignment: " << obj.getX() << endl;
    return 0;
}