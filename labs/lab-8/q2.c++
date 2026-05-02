#include <iostream>
#include <vector>
using namespace std;

class Character
{
protected:
    string name;
    int level, health;

public:
    Character(string name, int lvl, int hp) : name(name), level(lvl), health(hp) {}

    void displayCharacter()
    {
        cout << "Character Info:" << endl
             << "===============" << endl
             << "Name: " << name << endl
             << "Level: " << level << endl
             << "Health: " << health << endl;
    }

    virtual ~Character() {} // Best practice
};

class Warrior : virtual public Character
{
protected:
    int strength, meleeProf;

public:
    Warrior(string name, int lvl, int hp, int strength, int meleeProf)
        : Character(name, lvl, hp), strength(strength), meleeProf(meleeProf) {}

    void slash()
    {
        cout << "Warrior is slashing with power: "
             << strength + meleeProf * 0.2 << endl;
    }

    void displayWarrior()
    {
        cout << "Strength: " << strength << endl
             << "Melee Proficiency: " << meleeProf << endl;
    }

    void display()
    {
        displayCharacter();
        displayWarrior();
    }
};

class Mage : virtual public Character
{
protected:
    int intelligence, spellCastProf;

public:
    Mage(string name, int lvl, int hp, int intel, int prof)
        : Character(name, lvl, hp), intelligence(intel), spellCastProf(prof) {}

    void fireball()
    {
        cout << "Throwing fireball with power: "
             << spellCastProf * intelligence * 0.4 << endl;
    }

    void displayMage()
    {
        cout << "Intelligence: " << intelligence << endl
             << "Spell Cast Proficiency: " << spellCastProf << endl;
    }

    void display()
    {
        displayCharacter();
        displayMage();
    }
};

class Archer : virtual public Character
{
protected:
    int dexterity, rangedWepProf;

public:
    Archer(string name, int lvl, int hp, int dex, int prof)
        : Character(name, lvl, hp), dexterity(dex), rangedWepProf(prof) {}

    void rapidShot()
    {
        cout << "Shooting rapid arrows with accuracy: "
             << dexterity + rangedWepProf * 0.1
             << " and damage: "
             << rangedWepProf * 0.4 + dexterity * 0.1 << endl;
    }

    void displayArcher()
    {
        displayCharacter();
        cout << "Dexterity: " << dexterity << endl
             << "Ranged Weapon Proficiency: " << rangedWepProf << endl;
    }
};

class NPC : public Character
{
protected:
    vector<string> dialogues;
    vector<int> movements;

public:
    NPC(string name, int lvl, int hp, vector<string> dia, vector<int> moves)
        : Character(name, lvl, hp), dialogues(dia), movements(moves) {}

    void say(int i)
    {
        cout << "Saying: " << dialogues[i] << endl;
    }

    void move()
    {
        cout << "Moving..." << endl;
        for (int i = 0; i < movements.size(); i++)
            cout << movements[i] << endl;
    }

    void displayNPC()
    {
        displayCharacter();
        cout << "Dialogues:" << endl;
        for (int i = 0; i < dialogues.size(); i++)
            say(i);

        cout << "Moves:" << endl;
        move();
    }
};

class Mighty : public Warrior, public Mage
{
public:
    Mighty(string name, int lvl, int hp, int strength, int meleeProf, int intel, int prof)
        : Character(name, lvl, hp),
          Warrior(name, lvl, hp, strength, meleeProf),
          Mage(name, lvl, hp, intel, prof) {}

    void spellSlash()
    {
        cout << "Using abilities of both Warrior and Mage." << endl;
    }

    void displayMighty()
    {
        displayCharacter();
        displayWarrior();
        displayMage();
    }
};

int main()
{
    Warrior warrior("Warrior", 5, 100, 120, 50);
    Mage mage("Mage", 2, 70, 57, 68);
    Archer archer("Archer", 10, 23, 54, 90);

    vector<string> dialogues = {"Hi! I am a character","Wanna go for an adventure?", "Bye!!"};

    vector<int> moves = {1, 2, 1, 3, 4, 2};

    NPC npc("NPC", 0, 89, dialogues, moves);

    Mighty mighty("Mighty", 90, 150, 55, 130, 200, 60);

    warrior.display();
    cout << "Abilities:" << endl;
    warrior.slash();

    cout << endl;

    mage.display();
    cout << "Abilities:" << endl;
    mage.fireball();

    cout << endl;

    archer.displayArcher();
    cout << "Abilities:" << endl;
    archer.rapidShot();

    cout << endl;

    npc.displayNPC();

    cout << endl;

    mighty.displayMighty();
    cout << "Abilities:" << endl;
    mighty.spellSlash();

    return 0;
}