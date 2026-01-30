#include <iostream>
using namespace std;

class Character
{
    int *health, *power, *defense;

public:
    void setHealth(int input)
    {
        *health = input;
    }
    void setPower(int input)
    {
        *power = input;
    }
    void setDefense(int input)
    {
        *defense = input;
    }
    int getHealth()
    {
        return *health;
    }
    int getPower()
    {
        return *power;
    }
    int getDefense()
    {
        return *defense;
    }
    Character()
    {
        health = new int(100);
        power = new int(0);
        defense = new int(0);
    }
    Character(int h, int p, int d)
    {
        health = new int(h);
        power = new int(p);
        defense = new int(d);
    }
    Character(const Character &obj)
    {
        health = new int(*(obj.health));
        power = new int(*(obj.power));
        defense = new int(*(obj.defense));
    }
};

int main()
{
    Character taha;
    Character arslan(80, 200, 500);
    Character buzrg = taha;
    cout << "Taha" << endl
         << "Health: " << taha.getHealth() << endl
         << "Power: " << taha.getPower() << endl
         << "Defense: " << taha.getDefense() << endl;
    cout << "Arslan" << endl
         << "Health: " << arslan.getHealth() << endl
         << "Power: " << arslan.getPower() << endl
         << "Defense: " << arslan.getDefense() << endl;
    cout << "Aryan" << endl
         << "Health: " << buzrg.getHealth() << endl
         << "Power: " << buzrg.getPower() << endl
         << "Defense: " << buzrg.getDefense() << endl;
    return 0;
}