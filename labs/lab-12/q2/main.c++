#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream sourceFile("input.txt", ios::in);
    if (!sourceFile)
    {
        cout << "Error: Cannot open the source file 'input.txt'!" << endl;
        return 1;
    }

    ofstream destFile("copy_of_input.txt", ios::out);
    if (!destFile)
    {
        cout << "Error: Cannot create or open the destination file!" << endl;
        sourceFile.close();
        return 1;
    }

    char ch;
    while (sourceFile.get(ch))
        destFile.put(ch);

    cout << "\e[1;32mFile copied successfully in text mode!\e[0m" << endl;
    sourceFile.close();
    destFile.close();
    return 0;
}