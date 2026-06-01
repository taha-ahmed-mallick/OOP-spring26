#include <iostream>
using namespace std;

class BaseError {
    public:
    virtual string what()const {return "Base Error";}
};

class DerivedError : public BaseError {
    string what() const {return "Derived Error";}
};

void risky() {throw DerivedError();}

int main() {
    try
    {
        risky();
    }
    catch(BaseError e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
// obj slicing