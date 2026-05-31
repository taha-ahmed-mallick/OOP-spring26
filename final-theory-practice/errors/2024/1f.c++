#include <iostream>
using namespace std;

class SquareArea
{
    float sideLength;

public:
    SquareArea(float sideLength = 0) : sideLength(sideLength) {}
    // SquareArea() : sideLength(0) {}
    void setLength(float l) { sideLength = l; }
    float calculateArea() { return sideLength * sideLength; }
};
int main()
{
    SquareArea ob;
    ob.setLength(12);
    cout << "Area is " << ob.calculateArea();
}