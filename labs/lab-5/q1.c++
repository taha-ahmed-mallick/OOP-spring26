#include <iostream>
using namespace std;

class Base
{
private:
    int privateInt;

protected:
    int protectedInt;

public:
    int publicInt;
    Base() : privateInt(0), protectedInt(1), publicInt(2) {}
    void setPrivateInt(int val) { privateInt = val; }
    void setProtectedInt(int val) { protectedInt = val; }
    void setPublicInt(int val) { publicInt = val; }

    int getPrivateInt() { return privateInt; }
    int getProtectedInt() { return protectedInt; }
    int getPublicInt() { return publicInt; }
};

class PublicChild : public Base
{
public:
    void accessBaseMembers()
    {
        // privateInt is not accessible
        // protectedInt is accessible
        setProtectedInt(20);
        // publicInt is accessible
        setPublicInt(30);
    }
};

class ProtectedChild : protected Base
{
public:
    void accessBaseMembers()
    {
        // private attribute is not accessible, but can be accessed through a public member function of the base class
        // because the method is actually protected
        setPrivateInt(-10);
        // prtotected and public attributes are accessible, as they are now protected in the derived class
        protectedInt = 20;
        publicInt = 30;
    }
    void printMembers()
    {
        // all methods are also protected so only accessible through public member functions of the derived class
        cout << "PrivateInt value: " << getPrivateInt() << endl;
        cout << "ProtectedInt value: " << getProtectedInt() << endl;
        cout << "PublicInt value: " << getPublicInt() << endl;
    }
};

class PrivateChild : private Base
{
    // all member variables and member functions of the base class are private in this class
    // so they are accessible only here through public member functions of the derived class
public:
    void accessBaseMembers()
    {
        // private attribute is not accessible, but can be accessed through a public member function of the base class
        // because the method is actually protected
        setPrivateInt(-10);
        // protected and public attributes are accessible, as they are now private in the derived class
        protectedInt = 20;
        publicInt = 30;
    }
    
    void printMembers()
    {
        // all methods are also private so only accessible through public member functions of the derived class
        cout << "PrivateInt value: " << getPrivateInt() << endl;
        cout << "ProtectedInt value: " << getProtectedInt() << endl;
        cout << "PublicInt value: " << getPublicInt() << endl;
    }
};

int main()
{
    PublicChild publicChild;
    cout << "---- PublicChild values ----\n";
    // can be done using setters and getters of base class
    publicChild.setPrivateInt(-10);
    cout << "PrivateInt value: " << publicChild.getPrivateInt() << endl;
    // still public in the derived class
    publicChild.publicInt = 5;
    cout << "PublicInt value: " << publicChild.publicInt << endl;
    // protectedInt is not accessible directly, but can be accessed through a public member function of the derived class as well
    publicChild.accessBaseMembers();
    cout << "ProtectedInt value: " << publicChild.getProtectedInt() << endl << endl;
    // all of these members can be accessed through getters and setters of the base class
    
    ProtectedChild protectedChild;
    cout << "---- ProtectedChild values ----\n";
    // all attrib. and methods are protected in the derived class
    protectedChild.accessBaseMembers();
    cout << "ProtectedChild values:\n";
    protectedChild.printMembers();

    PrivateChild privateChild;
    cout << endl << "---- PrivateChild values ----\n";
    // all attrib. and methods are private in the derived class
    privateChild.accessBaseMembers(); 
    cout << "PrivateChild values:\n";
    privateChild.printMembers();
    return 0;
}