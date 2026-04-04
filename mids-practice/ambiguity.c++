#include <iostream>
class Base1
{
public:
    void display()
    {
        std::cout << "Base1 display" << std::endl;
    }
};
class Base2
{
public:
    void display()
    {
        std::cout << "Base2 display" << std::endl;
    }
};
class Derived : virtual public Base1, virtual public Base2
{
};
int main()
{
    Derived obj;
    // obj.display(); // Error: request for member 'display' is ambiguous
    obj.Base1::display(); // Calls Base1's display
    obj.Base2::display(); // Calls Base2's display
    return 0;
}
