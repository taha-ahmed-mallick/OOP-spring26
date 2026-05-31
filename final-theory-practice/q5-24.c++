#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char *str;
    int length;

public:
    String(const char *msg)
    {
        length = strlen(msg);
        str = new char[length + 1];
        strcpy(str, msg);
    }
    String(const String &other)
    {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    ~String()
    {
        delete[] str;
    }
    char getCharAt(int index)
    {
        if (index < 0 || index >= length)
        {
            throw runtime_error("Invalid index.");
        }
        return str[index];
    }
    String operator+(const String &other)
    {
        int con_length = this->length + other.length;
        char *con_string = new char[con_length + 1];
        strcpy(con_string, this->str);
        strcat(con_string, other.str);
        String concatenate(con_string);
        delete[] con_string;
        return concatenate;
    }
    bool operator==(const String &other) {
        return memcmp(str, other.str, length)==0;
    }
    void display() {
        cout << str << endl;
    }
};

int main()
{
    try
    {
        String s1("Hello");
        String s2("World");

        cout << "s1: ";
        s1.display();

        cout << "s2: ";
        s2.display();

        // Test concatenation
        String s3 = s1 + s2;
        cout << "s3 (s1 + s2): ";
        s3.display();

        // Test copy constructor
        String s4 = s3;
        cout << "s4 (copy of s3): ";
        s4.display();

        // Test equality
        cout << "s1 == s2: " << (s1 == s2) << endl;
        cout << "s3 == s4: " << (s3 == s4) << endl;

        // Test getCharAt
        cout << "s1[1]: " << s1.getCharAt(1) << endl;
        cout << "s2[0]: " << s2.getCharAt(0) << endl;

        // Test out of bounds (should throw)
        cout << "Trying invalid index...\n";
        cout << s1.getCharAt(10) << endl;
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}