#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    vector<int> w(11);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    w.push_back(1);
    w.push_back(2);
    w.push_back(3);
    cout << "Size of v: " << v.size() << endl;
    cout << "Size of w: " << w.size() << endl;
}