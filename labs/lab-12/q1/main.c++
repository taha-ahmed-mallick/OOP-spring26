#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fout("./data.txt", ios::out | ios::trunc);
    if (!fout)
    {
        cout << "An error occured." << endl;
        return 1;
    }
    string input;
    cout << "Input data you want to store: ";
    getline(cin, input);
    cout << "Length: " << input.length() << endl;
    for (char c : input)
        fout.put(c);
    fout.close();
    ifstream fin("./data.txt");
    char ch;
    cout << endl << "\e[1;32mData retrived from the file.\e[33m" << endl;
    while (fin.get(ch))
        cout << ch;
    cout  << "\e[0m\n";
    return 0;
}