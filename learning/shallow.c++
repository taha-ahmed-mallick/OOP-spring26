#include <iostream>
using namespace std;

class Shallow
{
public:
    int *data;
    Shallow(int d)
    {
        data = new int;
        *data = d;
    }
    Shallow(const Shallow &source)
    {
        data = source.data;
    }
    // ~Shallow()
    // {
    //     delete data;
    // }
    ~Shallow() {
        if (data != nullptr) {
            cout << "Deleting address: " << data << endl;
            delete data;
            data = nullptr; // Defensive: prevents further accidental deletes
        } else {
            // This would be your "Formal Error" log
            cerr << "ERROR: Attempted to delete an already freed pointer!" << endl;
        }
    }
};

void func() {
    Shallow obj1(100);
    Shallow obj2(obj1);
    cout << "obj1 data: " << *obj1.data << " at " << obj1.data << endl;
    cout << "obj2 data: " << *obj2.data << " at " << obj2.data << endl;
}

int main(){
    func();
    return 0;
}