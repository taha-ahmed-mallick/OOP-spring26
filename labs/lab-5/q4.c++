#include <iostream>
using namespace std;

class Item {
protected:
    string name;
    int qty;
public:
    Item(string name, int qty) : name(name), qty(qty) {}
    void display() {
        cout << "----------------------------------------------\n";
        cout << "Item: " << name << ", Quantity: " << qty;
    }
};

class BakedGoods: public Item {
protected:
    float discount = 10;
public:
    BakedGoods(string name, int qty) : Item(name, qty) {}
};

class Cakes: public BakedGoods {
protected:
    int price = 600;
public:
    Cakes(string name, int qty) : BakedGoods(name, qty) {}
    void printBill() {
        display();
        cout << ", Rate: " << price << endl;
        float total = price * qty;
        total -= (total * discount / 100);
        cout << "Total bill for " << name << ": " << total << endl;
    }
};

class Bread: public BakedGoods {
protected:
    int price = 200;
public:
    Bread(string name, int qty) : BakedGoods(name, qty) {}
    void printBill() {
        display();
        cout << ", Rate: " << price << endl;
        float total = price * qty;
        total -= (total * discount / 100);
        cout << "Total bill for " << name << ": " << total << endl;
    }
};

class Drinks: public Item {
protected:
    int price = 100;
    float discount = 5;
public:
    Drinks(string name, int qty) : Item(name, qty) {}
    void printBill() {
        display();
        cout << ", Rate: " << price << endl;
        float total = price * qty;
        total -= (total * discount / 100);
        cout << "Total bill for " << name << ": " << total << endl;
    }
};

int main() {
    Cakes cake("Chocolate Cake", 2);
    Bread bread("Large Bread", 1);
    Drinks drinks("Mtn Dew", 3);

    cake.printBill();
    bread.printBill();
    drinks.printBill();

    return 0;
}