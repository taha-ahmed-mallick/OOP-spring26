#include <iostream>
using namespace std;

template<typename T>
class cont{
private:
    T data;
public:
    cont(T arg) : data(arg) {}
    void increase(){data++;}
    void display() {cout << data << endl;}
};

template <>
class cont<char> {
    char c;
    public:
    cont(char c) : c(c) {}
    void upper() {
        if (c >= 'a' && c <= 'z')
            c = c + 'A' - 'a';
    }
    void display() {cout << c << endl;}
};

int main() {
    cont<int> a(5);
    a.display();
    a.increase();
    a.display();
    cont<char> b('e');
    b.display();
    b.upper();
    b.display();
    return 0;
}