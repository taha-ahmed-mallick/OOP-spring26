#include <iostream>
using namespace std;

template<typename T>

class Storage {
private:
    T data;
public:
    Storage(T data) : data(data) {}
    void display() {
        cout << "The data is: " << data << endl;
    }
};

template <typename T1, typename T2>

class Same {
public:
    T1 first;
    T2 second;
    Same(T1 a) : first(a), second(a) {}
    void display() {
        cout << first << endl;
        cout << second << endl;
    }
};

template <typename T1, typename T2>

class Pair {
public:
    T1 first;
    T2 second;
    Pair(T1 a, T2 b) : first(a), second(b) {}
    void display() {
        cout << first << endl;
        cout << second << endl;
    }
};

template <typename T1, typename T2>

class Last {
public:
    T1 first;
    T2 second;
    Last(T2 b) : first(b), second(b) {}
    void display() {
        cout << first << endl;
        cout << second << endl;
    }
};

template <typename T1, typename T2>

class Reversed {
public:
    T1 first;
    T2 second;
    Reversed(T2 b, T1 a) : first(a), second(b) {}
    void display() {
        cout << first << endl;
        cout << second << endl;
    }
};

int main() {
    Storage<int> a(5);
    Storage<string> b("Hellow");
    a.display();
    b.display();

    Same<string, string> c("Taha");
    Same<int, int> d(80);
    c.display();
    d.display();

    Pair<string, int> e("Taha", 18);
    Pair<int, float> f(80, 3.8f);
    e.display();
    f.display();

    Last<string, string> g("Taha");
    Last<int, int> h(80);
    g.display();
    h.display();

    Reversed<string, int> i(18, "Taha");
    Reversed<int, float> j(3.8f, 80);
    i.display();
    j.display();
    return 0;
}