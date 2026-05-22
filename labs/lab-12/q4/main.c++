#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

class Participant
{
private:
    int ID, score;
    char name[25];

public:
    Participant() : ID(0), score(0)
    {
        name[0] = '\0';
    }
    Participant(int ID, char *name, int score) : ID(ID), score(score)
    {
        strncpy(this->name, name, 24);
        name[24] = '\0';
    }

    int getID() { return ID; }
    int getScore() { return score; }
    void print()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Score: " << score << endl;
    }

    void input()
    {
        fstream file("./participant.dat", ios::app | ios::binary);
        if (!file)
        {
            cout << "\e[1;31mFile error.\e[0m\n";
            return;
        }
        file.write((char *)this, sizeof(Participant));
    }

    void output(int IDin)
    {
        Participant p;
        fstream file("./participant.dat", ios::in);
        if (!file)
        {
            cout << "\e[1;31mNo Participants.\e[0m\n";
            return;
        }
        while (file.read((char *)&p, sizeof(p)))
        {
            if (p.getID() == IDin)
            {
                cout << "-----\e[1;32mTarget Found\e[0m-----\n";
                p.print();
                return;
            }
        }
        cout << "\e[1;31mID wasn't in the file.\e[0m" << endl;
    }

    void max()
    {
        Participant p, max;
        fstream file("./participant.dat", ios::in | ios::binary);
        if (!file)
        {
            cout << "\e[1;31mNo Participants.\e[0m\n";
            return;
        }
        while (file.read((char *)&p, sizeof(p)))
            if (p.getScore() > max.getScore())
                max = p;
        cout << endl
             << "\e[1;32mMaxima:\e[0m" << endl;
        max.print();
    }
};

int main()
{
    int ID, score;
    char name[25];
    cout << "Enter your name: ";
    cin.getline(name, 24);
    cout << "Enter ID: ";
    cin >> ID;
    cout << "Enter score: ";
    cin >> score;

    Participant p(ID, name, score);

    p.input();

    cout << "Enter ID you want to search: ";
    cin >> ID;
    p.output(ID);

    p.max();

    return 0;
}