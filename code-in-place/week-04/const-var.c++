#include <iostream>
using namespace std;

class MyClass {
private:
    static int count;
    const int id;
    string name;
public:
    MyClass(int id, string str) : id(id) {
        name = str;
    }
    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    MyClass obj(1, "abc");
    obj.display();
    return 0;
}