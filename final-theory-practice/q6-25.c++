// #include <iostream>
// using namespace std;

// class Item
// {
//     string name;
//     int ID, price;
//     bool instock;

// public:
//     Item(string name, int ID, int price, bool instock) : name(name), ID(ID), price(price), instock(instock) {}
//     Item(const Item &other) : name(other.name), ID(other.ID), price(other.price), instock(other.instock) {}
//     ~Item() = default;
//     bool operator==(const Item&other) {
//         return ID == other.ID;
//     }
//     Item operator<(const Item &other) {
//         if (price < other.price) {
//             Item result(*this);
//             return result;
//         } else {
//             Item result(other);
//             return result;
//         }
//     }
// };

// int main()
// {

//     return 0;
// }

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Item
{
private:
    char* name;
    int id;
    double price;
    bool inStock;

public:
    // Constructor
    Item(const char* n = "", int id = 0,
         double price = 0.0, bool stock = false)
    {
        this->id = id;
        this->price = price;
        this->inStock = stock;

        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Copy Constructor
    Item(const Item& other)
    {
        id = other.id;
        price = other.price;
        inStock = other.inStock;

        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    // Copy Assignment Operator
    Item& operator=(const Item& other)
    {
        if (this != &other)
        {
            delete[] name;

            id = other.id;
            price = other.price;
            inStock = other.inStock;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        return *this;
    }

    // Destructor
    ~Item()
    {
        delete[] name;
    }

    // Compare by ID
    bool operator==(const Item& other) const
    {
        return id == other.id;
    }

    // Compare by Price
    bool operator<(const Item& other) const
    {
        return price < other.price;
    }

    int getID() const
    {
        return id;
    }

    void display() const
    {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Price: " << price
             << ", In Stock: "
             << (inStock ? "Yes" : "No")
             << endl;
    }
};

class Cart
{
private:
    vector<Item> items;

public:
    // Add item
    void addItem(const Item& item)
    {
        items.push_back(item);
    }

    // Remove item by ID
    bool removeItem(int id)
    {
        for (auto it = items.begin(); it != items.end(); ++it)
        {
            if (it->getID() == id)
            {
                items.erase(it);
                return true;
            }
        }

        return false; // item not found
    }

    // Find item by ID
    Item* findItem(int id)
    {
        for (auto& item : items)
        {
            if (item.getID() == id)
                return &item;
        }

        return nullptr;
    }

    void displayCart() const
    {
        if (items.empty())
        {
            cout << "Cart is empty.\n";
            return;
        }

        for (const auto& item : items)
            item.display();
    }
};

int main()
{
    Cart cart;

    Item i1("Laptop", 101, 1500.0, true);
    Item i2("Mouse", 102, 25.0, true);
    Item i3("Keyboard", 103, 50.0, false);
    // i1 = i2 = i3;

    cart.addItem(i1);
    cart.addItem(i2);
    cart.addItem(i3);

    cout << "Cart Contents:\n";
    cart.displayCart();

    cout << "\nFinding ID 102:\n";
    Item* found = cart.findItem(102);

    if (found)
        found->display();
    else
        cout << "Item not found\n";

    cout << "\nRemoving ID 102\n";

    if (cart.removeItem(102))
        cout << "Removed successfully\n";
    else
        cout << "Item not found\n";

    cout << "\nUpdated Cart:\n";
    cart.displayCart();

    return 0;
}