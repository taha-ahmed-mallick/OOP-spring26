#include <iostream>
using namespace std;

class MyClass
{
private:
    const int id;
    string name;

public:
    static int count;
    MyClass(int id, string str) : id(id)
    {
        name = str;
        count++;
    }
    void display() const
    {
        cout << "ID: " << id << " Name: " << name << endl;
    }
};
int MyClass::count = 0;

int main()
{
    MyClass obj(1, "abc");
    obj.display();
    cout << MyClass::count << endl;
    MyClass obj1(2, "def");
    obj1.display();
    cout << MyClass::count << endl;
    return 0;
}