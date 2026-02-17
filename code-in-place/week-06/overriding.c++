#include <iostream>
using namespace std;

// Parent class
class Shape
{
public:
    virtual float area()
    {
        return 0;
    }
};
// Child class: Triangle
class Triangle : public Shape
{
public:
    float base = 10, height = 5;

    float area()
    {
        return 0.5 * base * height;
    }
};
// Child class: Circle
class Circle : public Shape
{
public:
    float radius = 7;

    float area()
    {
        return 3.14 * radius * radius;
    }
};
// Child class: Rectangle
class Rectangle : public Shape
{
public:
    float length = 8, width = 4;

    float area()
    {
        return length * width;
    }
};
int main()
{
    Shape *s;

    Triangle t;
    Circle c;
    Rectangle r;

    s = &t;
    cout << "Triangle Area: " << t.area() << endl;
    s = &c;
    cout << "Circle Area: " << s->area() << endl;
    s = &r;
    cout << "Rectangle Area: " << s->area() << endl;
    return 0;
}