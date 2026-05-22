#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file("./STORY.txt", ios::in);
    if (!file)
    {
        cout << "\e[1;31mFile not found.\e[0m\n";
        return 1;
    }
    string line;
    uint count = 0;
    while (getline(file, line))
        if (line[0] != 'A')
            count++;
    cout << "\e[1;32mTotal: " << count << "\e[0m\n";
    return 0;
}