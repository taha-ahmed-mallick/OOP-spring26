#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
private:
    int numSides;
    float area;

public:
    Shape(int sides, float a) : numSides(sides), area(a) {}
    void setSides(int sides) { numSides = sides; }
    void setArea(float a) { area = a; }
    int getSides() { return numSides; }
    float getArea() { return area; }
    void display() {
        cout << "Number of sides: " << numSides << endl;
        cout << "Area: " << area << endl;
    }
};

class Rectangle : public Shape
{
private:
    float len, width;

public:
    Rectangle(float l, float w) : Shape(4, 0), len(l), width(w) {}
    void generateArea() { setArea(len * width); }
    float getLength() { return len; }
    float getWidth() { return width; }
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r) : Shape(0, 0), radius(r) {}
    void generateArea() { setArea(M_PI * radius * radius); }
};

class Triangle : public Shape
{
private:
    float base, height;

public:
    Triangle(float b, float h) : Shape(3, 0), base(b), height(h) {}
    void generateArea() { setArea(base * height / 2); }
};

class Square : public Rectangle
{
public:
    Square(float s) : Rectangle(s, s) {}
    void generateArea() { setArea(getLength() * getWidth()); }
    bool checkSide() {
        if (getLength() == getWidth())
            return true;
        return false;
    }
};

int main()
{
    cout << "Rectangle:" << endl;
    Rectangle rect(5, 3);
    rect.generateArea();
    rect.display();

    cout << "\nCircle:" << endl;
    Circle circ(4);
    circ.generateArea();
    circ.display();

    cout << "\nTriangle:" << endl;
    Triangle tri(6, 4);
    tri.generateArea();
    tri.display();

    cout << "\nSquare:" << endl;
    Square sq(4);
    sq.generateArea();
    sq.display();
    cout << (sq.checkSide() ? "Sides are equal." : "Sides are not equal.") << endl;
    return 0;
}