#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string line;
    fstream objectFile("./text.txt", ios::in | ios::out | ios::trunc);
    if (!objectFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    objectFile << "Good Luck!" << endl;
    objectFile.seekg(0);
    objectFile >> line;
    cout << line;
    objectFile.close();
}