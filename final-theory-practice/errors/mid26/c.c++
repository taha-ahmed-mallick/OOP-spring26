#include <iostream>
using namespace std;

class Fan {
public:
    virtual void on() = 0;
    virtual void off() = 0;
};

class SmartFan : public Fan {
public:
    void on() {
        cout << "TV is ON.";
    }
};

int main() {
    // SmartFan myFan;
    return 0;
}