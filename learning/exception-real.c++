#include <iostream>
#include <math.h>
using namespace std;

class Vector
{
    float x, y;

public:
    Vector(float x, float y) : x(x), y(y) {}

    Vector operator+(const Vector &other)
    {
        return Vector(x + other.x, y + other.y);
    }

    Vector operator-(const Vector &other)
    {
        return Vector(x - other.x, y - other.y);
    }

    Vector operator*(const float val)
    {
        return Vector(x * val, y * val);
    }

    Vector operator/(const float val)
    {
        if (val == 0)
        {
            throw "Error: Division by zero!\n";
        } else if (val == 100) {
            throw 505;
        }
        return Vector(x / val, y / val);
    }

    float magnitude()
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    void display()
    {
        cout << "Vector(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Vector v1(1, 2), v2(3, 4);
    cout << "v1: ";
    v1.display();
    cout << "v2: ";
    v2.display();

    Vector addition = v1 + v2;
    Vector subtraction = v1 - v2;
    Vector multiplication = v1 * 2;
    Vector division = v1 / 2;
    float mag = v1.magnitude();
    cout << "v1 + v2: ";
    addition.display();
    cout << "v1 - v2: ";
    subtraction.display();
    cout << "v1 * 2: ";
    multiplication.display();
    cout << "v1 / 2: ";
    division.display();
    cout << "Magnitude of v1: " << mag << endl;
    Vector unitVector = v1 / mag;
    cout << "Unit vector of v1: ";
    unitVector.display();
    cout << "Magnitude of unit vector: " << unitVector.magnitude() << endl;
    try
    {
        Vector zeroVector = v2 / 0;
        cout << "v2 / 0: ";
        zeroVector.display();
        zeroVector = v2/5;
        cout << "v2 / 5: ";
        zeroVector.display();
    }
    catch (const char* err)
    {
        cout << err;
    } catch (int err) {
        cout << err;
    }
    try
    {
        Vector zeroVector = v2/100;
        cout << "v2 / 5: ";
        zeroVector.display();
    }
    catch (const char* err)
    {
        cout << err;
    } catch (int err) {
        cout << "Error: " << err;
    } catch(...) {
        cout << "some different err";
    }
    return 0;
}