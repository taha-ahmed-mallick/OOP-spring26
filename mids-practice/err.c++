#include <iostream>
#include <cstring>
using namespace std;

class String {
private: char *str;
public:
    String(const char *s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    void display() {
        cout << str << endl;
    }
    void change(const char *s) {
        strcpy(str, s);
    }
    ~String() { delete[] str; }
};

// it does frees the mem two time tho

int main() {
    String s1("Hello");
    String s2 = s1;
    s1.display(); s2.display();
    s1.change("World");
    s1.display(); s2.display();
}