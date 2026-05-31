#include <iostream>
using namespace std;

class Shape
{
public:
    void draw() { cout << "Drawing shape" << endl; }
};
class Circle : public Shape
{
public:
    void draw() { cout << "Drawing circle" << endl; }
};
void render(Shape *s) { s->draw(); }
int main()
{
    Circle *obj = new Circle;
    obj->draw();
    render(dynamic_cast<Shape*>(obj));
}