#include <iostream>
using namespace std;

string processString(string msg)
{
    cout << "Original Message: " << msg;
    int index = 0;
    while (msg[index] != '\0')
    {
        msg[index] += 2;
        index++;
    }
    return msg;
}
int main()
{
    string line = processString("OOPEXAM");
    cout << "Encrypted Message: " << line << endl;
}