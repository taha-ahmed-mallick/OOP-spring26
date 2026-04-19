#include <iostream>
using namespace std;

class Character
{
public:
    virtual void attack()
    {
        cout << "Character attacking..." << endl;
    }
    virtual void power()
    {
        cout << "Character using power..." << endl;
    }
};

class Warrior : public Character
{
public:
    void attack() override
    {
        cout << "Warrior attacking!" << endl;
    }
    void power() override
    {
        cout << "Warrior using power!" << endl;
    }
};

class Mage : public Character
{
public:
    void attack() override
    {
        cout << "Mage attacking!" << endl;
    }
    void power() override
    {
        cout << "Mage using power!" << endl;
    }
};

class DamageCalculator
{
public:
    void calculateDamage(int attack)
    {
        cout << "Damage: " << attack * 2 << endl;
    }
    void claculateDamage(int attack, int specialAttack)
    {
        cout << "Damage: " << attack + specialAttack * 3 << endl;
    }
};

class Position
{
public:
    int x, y;
    Position() : x(0), y(0) {}
    Position(int x, int y) : x(x), y(y) {}

    void display()
    {
        cout << "Position: (" << x << ", " << y << ")" << endl;
    }

    Position operator+(const Position &other)
    {
        return Position(x + other.x, y + other.y);
    }
};

int main()
{
    // Overriding example
    Character *ptr;
    ptr = new Warrior();
    ptr->attack();
    ptr->power();
    ptr = new Mage();
    ptr->attack();
    ptr->power();

    // Function Overloading example
    DamageCalculator calc;
    calc.calculateDamage(10);
    calc.claculateDamage(10, 5);

    // Operator Overloading example
    Position pos1(2, 3), pos2(4, 5);
    cout << "1. ";
    pos1.display();
    cout << "2. ";
    pos2.display();
    Position pos3 = pos1 + pos2;
    cout << "Resultant -> ";
    pos3.display();
    return 0;
}