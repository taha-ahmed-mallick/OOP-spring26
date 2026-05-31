#include <iostream>
using namespace std;

class Shape
{
protected:
    int ID;

public:
    Shape(int id) : ID(id) {}
    virtual void draw() const = 0;
};

class ColoredShape : virtual public Shape
{
protected:
    string color;

public:
    ColoredShape(int id, string color) : Shape(id), color(color) {}
    virtual void draw() const override
    {
        cout << "Drawing a colored shape.\n";
    }
};

class TexturedShape : virtual public Shape
{
protected:
    string texture;

public:
    TexturedShape(int id, string texture) : Shape(id), texture(texture) {}
    virtual void draw() const override
    {
        cout << "Drawing a textured Shape.\n";
    }
};

class ColoredTexturedShape : public ColoredShape, public TexturedShape
{
public:
    ColoredTexturedShape(int id, string color, string texture, int dum) : Shape(id), ColoredShape(dum, color), TexturedShape(dum, texture) {}
    virtual void draw() const
    {
        cout << "Drawing a colored and a textured shape.\n"
             << ID << color << texture << endl
             << ColoredShape::ID;
    }
};

int main()
{
    ColoredTexturedShape a(1, "red", "rough", 2);
    a.draw();
}