#include <iostream>
using namespace std;

class Teacher
{
private:
    string name;
    int age;
    string institute;

public:
    Teacher()
    {
        name = institute = "N/A";
        age = 0;
    }
    Teacher(string name, int age, string institute) : name(name), age(age), institute(institute) {}

    int getAge() { return age; }
    string getName() { return name; }
    string getInstitute() { return institute; }

    void setAge(int age) { this->age = age; }
    void setName(string name) { this->name = name; }
    void setInstitute(string institute) { this->institute = institute; }

    void displayBaseInfo()
    {
        cout << "Name: " << name << " | Age: " << age << " | Institute: " << institute << endl;
    }
};

class HumanitiesTeacher : public Teacher
{
private:
    string department;
    string courseName;
    string designation;

public:
    HumanitiesTeacher()
    {
        Teacher();
        department = courseName = designation = "N/A";
    }
    HumanitiesTeacher(string name, int age, string institute, string department, string courseName, string designation) : Teacher(name, age, institute), department(department), courseName(courseName), designation(designation) {}

    string getDepartment() { return department; }
    string getCourseName() { return courseName; }
    string getDesignation() { return designation; }

    void setDepartment(string department) { this->department = department; }
    void setCourseName(string courseName) { this->courseName = courseName; }
    void setDesignation(string designation) { this->designation = designation; }

    void displayDetails()
    {
        displayBaseInfo();
        cout << "Dept: " << department << " | Course: " << courseName << " | Rank: " << designation << endl;
        cout << "----------------------------------------------------------" << endl;
    }
};

class ScienceTeacher : public Teacher
{
private:
    string department;
    string courseName;
    string designation;

public:
    ScienceTeacher()
    {
        Teacher();
        department = courseName = designation = "N/A";
    }
    ScienceTeacher(string name, int age, string institute, string department, string courseName, string designation) : Teacher(name, age, institute), department(department), courseName(courseName), designation(designation) {}

    string getDepartment() { return department; }
    string getCourseName() { return courseName; }
    string getDesignation() { return designation; }

    void setDepartment(string department) { this->department = department; }
    void setCourseName(string courseName) { this->courseName = courseName; }
    void setDesignation(string designation) { this->designation = designation; }

    void displayDetails()
    {
        displayBaseInfo();
        cout << "Dept: " << department << " | Course: " << courseName << " | Rank: " << designation << endl;
        cout << "----------------------------------------------------------" << endl;
    }
};

class MathTeacher : public Teacher
{
private:
    string department;
    string courseName;
    string designation;

public:
    MathTeacher()
    {
        Teacher();
        department = courseName = designation = "N/A";
    }
    MathTeacher(string name, int age, string institute, string department, string courseName, string designation) : Teacher(name, age, institute), department(department), courseName(courseName), designation(designation) {}

    string getDepartment() { return department; }
    string getCourseName() { return courseName; }
    string getDesignation() { return designation; }

    void setDepartment(string department) { this->department = department; }
    void setCourseName(string courseName) { this->courseName = courseName; }
    void setDesignation(string designation) { this->designation = designation; }

    void displayDetails()
    {
        displayBaseInfo();
        cout << "Dept: " << department << " | Course: " << courseName << " | Rank: " << designation << endl;
        cout << "----------------------------------------------------------" << endl;
    }
};

int main()
{
    HumanitiesTeacher h("XYZ", 40, "HABIB", "History", "World History", "Professor");
    ScienceTeacher s("ABC", 35, "NEDUET", "Physics", "Quantum Mechanics", "Lecturer");
    MathTeacher m("PQR", 45, "FAST", "Mathematics", "Calculus", "Associate Professor");

    cout << "Humanities Teacher Details:" << endl;
    h.displayDetails();
    cout << "Science Teacher Details:" << endl;
    s.displayDetails();
    cout << "Math Teacher Details:" << endl;
    m.displayDetails();
    return 0;
}