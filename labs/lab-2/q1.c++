#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int roll_no, sem;
    char sec;
};

int main()
{
    Student students[4];
    cout << "Enter Student Records:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "Student " << (i + 1) << ":\n";
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Roll No: ";
        cin >> students[i].roll_no;
        cout << "Semester: ";
        cin >> students[i].sem;
        cout << "Section: ";
        cin >> students[i].sec;
    }

    cout << "\n====Students of Section A====\n";
    for (int i = 0; i < 4; i++)
        if (students[i].sec == 'A' || students[i].sec == 'a')
            cout << "Name: " << students[i].name << ", Roll No: " << students[i].roll_no << ", Semester: " << students[i].sem << endl;

    return 0;
}