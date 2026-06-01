#include <iostream>
using namespace std;

template<class T, class U>
class Pair {
    public:
        T first;
        U second;
        Pair(T a, U b) : first(a), second(b) {}
};

template<class T = int, class U>
class Pair;

int main() {
    Pair<> p(1, 2);
    cout << p.first << " " << p.second << endl;
    return 0;
}