#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Person
{
private:
    char name[25];
    int age;

public:
    Person() {}
    Person(char *name, int age) : age(age)
    {
        strncpy(this->name, name, 24);
        this->name[24] = '\0';
    }
    void print()
    {
        cout << name << endl
             << age << endl;
    }
};

int main()
{
    char name[25];
    int age;
    cout << "Enter your name: ";
    cin.getline(name, 24);
    cout << "Enter your age: ";
    cin >> age;
    Person person1(name, age);
    fstream file("./person.bin", ios::binary | ios::out | ios::trunc);
    if (!file)
    {
        cout << "\e[1;31mFile can't be generated.\e[0m\n";
        return 1;
    }
    file.write((char *)&person1, sizeof(person1));
    file.close();

    file.open("./person.bin", ios::binary | ios::in);
    if (!file)
    {
        cout << "\e[1;31mFile not available.\e[0m\n";
        return 1;
    }
    Person person2;
    if (file.read((char *)&person2, sizeof(person2)))
    {
        cout << "------\e[1;32mInfo retrived from the file\e[0m------\n";
        person2.print();
    }
    else
        cout << "\e[1;31mAn error occured while reading the file.\e[0m\n";
    return 0;
}