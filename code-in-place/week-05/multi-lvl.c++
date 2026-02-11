#include <iostream>
using namespace std;

class A
{
public:
    int a;
    void fetch_a()
    {
        cin >> a;
    }
};

class B : public A
{
public:
    int b;
    void fetch_b()
    {
        cin >> b;
    }
};

class C : public B
{
private:
    int c;

public:
    void fetch_c()
    {
        cin >> c;
    }

    void calculate_product()
    {
        cout << "Product = " << a * b * c;
    }
};

int main()
{
    C obj;

    obj.fetch_a();
    obj.fetch_b();
    obj.fetch_c();
    obj.calculate_product();

    return 0;
}