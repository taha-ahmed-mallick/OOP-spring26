#include <iostream>
using namespace std;

class Person {
    public:
    virtual void draw() {
        cout << "Drawing Person" << endl;
    }
};

class Artist : public Person {
    public:
    void draw() override {
        cout << "Drawing Art" << endl;
    }
};

class Gunman : public Person {
    public:
    void draw() override {
        cout << "Shoot" << endl;
    }
};

int main()
{
    Person *arr[2];
    arr[0] = new Artist();
    arr[1] = new Gunman();
    arr[0]->draw();
    arr[1]->draw();
    return 0;
}