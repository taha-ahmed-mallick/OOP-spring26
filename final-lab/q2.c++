#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Participant
{
private:
    int ID, score;
    char name[50];

public:
    Participant() {}
    Participant(int ID, int score, char *name) : ID(ID), score(score)
    {
        strncpy(this->name, name, 49);
        this->name[49] = '\0';
    }

    void input()
    {
        ofstream file("./participants.dat", ios::app);
        if (!file)
        {
            cout << "Error file can't be created." << endl;
            return;
        }
        file << ID << "|" << name << "|" << score << endl;
        file.close();
    }

    void output(int id) {
        ifstream file("./participants.dat");
        if (!file) {
            cout << "Error file doesn't exists.\n";
            return;
        }
        string line;
        while(getline(file, line)) {
            string name, input;
            int fID, fScore;
            stringstream ss(line);
            getline(ss, input, '|');
            fID = stoi(input);
            if (fID != id)
                continue;
            getline(ss, name, '|');
            getline(ss, input, '|');
            fScore = stoi(input);
            cout << "Searched for ID: " <<id<<endl;
            cout << "Name: " << name << endl;
            cout << "Score: " << score << endl;
        }
    }
};

int main()
{
    char name[50];
    int ID, score;
    cout << "Enter name: ";
    cin.getline(name, 49);
    cout << "Enter ID: ";
    cin >> ID;
    cout << "Enter score: ";
    cin >> score;
    Participant p(ID, score, name);
    p.input();
    cout << "Enter ID you want to search: ";
    cin >> ID;
    p.output(ID);
    return 0;
}