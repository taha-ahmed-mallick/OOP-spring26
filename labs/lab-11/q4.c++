#include <iostream>
#include <map>
using namespace std;

class StudentManage
{
private:
    map<string, string> studentRecord;

public:
    StudentManage() {}

    bool checkGrade(const string &grade)
    {
        string grades[] = {"A+", "A", "B", "C", "D", "F"};
        for (string select : grades)
        {
            if (grade == select)
                return true;
        }
        return false;
    }

    void addStudents()
    {
        string grade, name;
        do
        {
            cout << "Enter name of student or blank to stop: ";
            getline(cin, name);
            if (name == "")
                break;
            do
            {
                cout << "Enter the grade(A+/A/B/C/D/F): ";
                getline(cin, grade);
            } while (!checkGrade(grade));
            studentRecord[name] = grade;
        } while (true);
    }

    void viewRecords()
    {
        if (studentRecord.empty())
        {
            cout << "----------No Records Found------------\n";
            return;
        }
        cout << "----------Total Records------------\n";
        cout << "S#\tStudents\tGrade\n";
        map<string, string>::iterator itr = studentRecord.begin();
        for (int i = 1; itr != studentRecord.end(); i++, itr++)
            cout << i << "\t" << itr->first << "\t\t" << itr->second << endl;
        cout << "-----------End of Records----------\n";
    }

    void getGrade()
    {
        string name;
        cout << "Enter the name of the student: ";
        getline(cin, name);
        if (studentRecord.find(name) != studentRecord.end())
            cout << "\e[1;32mGrade is: " << studentRecord[name] << "\e[0m\n";
        else
            cout << "\e[1;31mThis student doesn't exists.\e[0m\n";
    }

    void deleteRecord()
    {
        string name;
        cout << "Enter the name of the student: ";
        getline(cin, name);
        if (studentRecord.erase(name))
            cout << "\e[1;32mRecord of " << name << " successfully deleted.\e[0m\n";
        else
            cout << "\e[1;31mThis student wasn't in the records.\e[0m\n";
    }

    void updateRecords()
    {
        string name, grade;
        cout << "Enter the name of the student: ";
        getline(cin, name);
        if (studentRecord.find(name) != studentRecord.end())
        {
            cout << "Enter the grade(A+/A/B/C/D/F): ";
            getline(cin, grade);
            studentRecord[name] = grade;
        }
        else
            cout << "\e[1;31mThis student doesn't exists.\e[0m\n";
    }
};

int main()
{
    StudentManage students;
    do
    {
        int choice;
        cout << "Select from the options below:" << endl
             << "1. Add students" << endl
             << "2. View records" << endl
             << "3. Get grade of a student" << endl
             << "4. Update record" << endl
             << "5. Delete record" << endl
             << "6. EXIT" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            students.addStudents();
            break;
        case 2:
            students.viewRecords();
            break;
        case 3:
            students.getGrade();
            break;
        case 4:
            students.updateRecords();
            break;
        case 5:
            students.deleteRecord();
            break;
        case 6:
            cout << "EXITING..." << endl;
            return 0;
            break;

        default:
            cout << "\e[1;31mINVALID CHOICE\e[0m\n";
            break;
        }
    } while (true);
    return 0;
}