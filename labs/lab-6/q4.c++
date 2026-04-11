#include <iostream>
using namespace std;

class Person {
private:
    string name;
    string occupation;
public:
    Person(string name, string occupation) : name(name), occupation(occupation) {}

    virtual void draw() {
        cout << "A person can draw in many ways" << endl;
    }
};

class Artist : public Person {
public:
    Artist(string name) : Person(name, "Artist") {}

    void draw() override {
        cout << "An artist can draw with a paint brush" << endl;
    }
};

class Gunman : public Person {
public:
    Gunman(string name) : Person(name, "Gunman") {}

    void draw() override {
        cout << "A gunman draws a gun to shoot" << endl;
    }
};

int main() {
    Person *arr[3];
    arr[0] = new Person("ABC", "CS Grad");
    arr[1] = new Artist("XYZ");
    arr[2] = new Gunman("PQR");
    for (int i = 0; i < 3; i++) {
        arr[i]->draw();
    }
    return 0;
}