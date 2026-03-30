#include <iostream>
#include <cmath>
using namespace std;

class Coordinate {
int x, y;
public:
    Coordinate() : x(0), y(0) {}
    void setX(int val) {
        x = val;
    }
    void setY(int val) {
        y = val;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }

    int operator > (Coordinate& c) {
        float p1 = sqrt(x*x + y*y);
        float p2 = sqrt(c.x*c.x + c.y*c.y);
        if (p1 > p2) {
            return 1;
        }
        else if (p1 == p2) {
            return 0;
        } else {
            return -1;
        }
    }
};

int main() {
    Coordinate c;
    c > c;
    return 0;
}