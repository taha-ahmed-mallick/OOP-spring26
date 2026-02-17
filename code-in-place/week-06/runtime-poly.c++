#include <iostream>
using namespace std;

class Shape {
public:
    void print() {
        cout << "This is a shape" << endl;
    }
};

class Circle : public Shape {
public:
    void print() {
        cout << "This is a circle" << endl;
    }
    void area() {
        cout << "Area of circle: " << 3.14 * 7 * 7 << endl;
    }
};

int main() {
    Shape* s;
    Circle c;

    s = &c;
    s->print(); // Calls Circle's print() 
    (&c)->area(); // Calls Circle's area() can't do s->area() because s is a pointer to Shape, which doesn't have area() method
}