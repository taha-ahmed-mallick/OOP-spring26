#include <iostream>
#include <math.h>
using namespace std;

class Vector {
    float x, y;
public:
    Vector(float x, float y) : x(x), y(y) {}

    Vector operator+(const Vector& other) {
        return Vector(x + other.x, y + other.y);
    }

    Vector operator-(const Vector& other) {
        return Vector(x - other.x, y - other.y);
    }

    Vector operator*(const float val) {
        return Vector(x * val, y * val);
    }

    Vector operator/(const float val) {
        if (val == 0) {
            cout << "Error: Division by zero!" << endl;
            return Vector(0, 0);
        }
        return Vector(x / val, y / val);
    }

    float magnitude() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    void display() {
        cout << "Vector(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vector v1(1, 2), v2(3, 4);
    cout << "v1: "; v1.display();
    cout << "v2: "; v2.display();

    Vector addition = v1 + v2;
    Vector subtraction = v1 - v2;
    Vector multiplication = v1 * 2;
    Vector division = v1 / 2;
    float mag = v1.magnitude();
    cout << "v1 + v2: "; addition.display();
    cout << "v1 - v2: "; subtraction.display();
    cout << "v1 * 2: "; multiplication.display();
    cout << "v1 / 2: "; division.display();
    cout << "Magnitude of v1: " << mag << endl;
    Vector unitVector = v1 / mag;
    cout << "Unit vector of v1: "; unitVector.display();
    cout << "Magnitude of unit vector: " << unitVector.magnitude() << endl;
    Vector zeroVector = v2 / 0;
    cout << "v2 / 0: "; zeroVector.display();
    return 0;
}