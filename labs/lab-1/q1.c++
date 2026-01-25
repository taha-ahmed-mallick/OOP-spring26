#include <iostream>
using namespace std;

int main()
{
    int roll, marks[5], obt = 0, total = 500;
    char sub_name[][5] = {"CAG", "DS", "LDST", "OOPs", "PS"};
    cout << "Enter Roll No.: ";
    cin >> roll;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter marks of " << sub_name[i] << ": ";
        cin >> marks[i];
        obt += marks[i];
    }
    float perc = ((float)obt / (float)total) * 100;
    cout << "Your percentage " << perc << "%." << endl;
    return 0;
}