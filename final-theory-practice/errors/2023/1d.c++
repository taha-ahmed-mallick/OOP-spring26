#include <iostream>
using namespace std;

class Point
{
public:
    int xCoord;
    int yCoord;
    Point(int x = 0, int y = 0)
    {
        xCoord = x;
        yCoord = y;
    }
    Point operator+(const Point &right)
    {
        xCoord += right.xCoord;
        yCoord += right.yCoord;
        return Point(xCoord, yCoord);
    }
};
int main()
{
    Point p1(5, 6), p2(1, 1), p3;
    p3 = p1 + p2;
    cout << p1.xCoord << "\t" << p1.yCoord << endl;
    cout << p3.xCoord << "\t" << p3.yCoord << endl;
}