#include <iostream>
using namespace std;

class Student
{
public:
    string *name;

    Student()
    {
        name = new string("Unknown");
    }
    Student(const string str)
    {
        name = new string(str);
    }
    Student(const Student &obj)
    {
        name = new string(*(obj.name));
    }

    ~Student()
    {
        delete[] name;
    }
};

int main()
{
    Student student1;
    Student student2("Taha");
    Student student3 = student2;

    cout << "====Students====" << endl;
    cout << "1." << *(student1.name) << endl;
    cout << "2." << *(student2.name) << endl;
    cout << "3." << *(student3.name) << endl;

    *(student3.name) = "Danial";
    cout << "After Modifying the Student 3 name" << endl;
    cout << "2." << *(student2.name) << endl;
    cout << "3." << *(student3.name) << endl;

    // Order of Constrcutor and Detrcutor calls
    // 1. student1 Default Constructor Called.
    // 2. student2 Paramaterized Constructor Called.
    // 3. student3 Copy Constructor Called.
    // 4. student3 Destructor Called.
    // 5. student2 Destructor Called.
    // 6. student1 Destructor Called.
}