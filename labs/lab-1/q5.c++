#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float rad, vol, sa, PI = acos(-1);
    cout<< "Enter Radius of the Sphere: ";
    cin >> rad;
    vol = (4.0/3.0) * PI * pow(rad, 3);
    sa = 4 * PI * pow(rad, 2);
    cout<< "Volume of Sphere: " << vol << endl;
    cout<< "Surface Area of Sphere: " << sa << endl;
    return 0;
}