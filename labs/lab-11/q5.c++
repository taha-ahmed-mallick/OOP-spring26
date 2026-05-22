#include <iostream>
#include <set>
using namespace std;

class GuestTracker
{
private:
    set<string> guests;

public:
    GuestTracker() {}

    void addGuests()
    {
        string name;
        do
        {
            cout << "Enter name of student or blank to stop: ";
            getline(cin, name);
            if (name == "")
                break;
            guests.insert(name);
        } while (true);
    }

    void viewGuests()
    {
        if (guests.empty())
        {
            cout << "----------No Guests in the System------------\n";
            return;
        }
        cout << "----------Total Guests------------\n";
        cout << "S#\tName\n";
        set<string>::iterator itr = guests.begin();
        for (int i = 1; itr != guests.end(); i++, itr++)
            cout << i << "\t" << *itr << endl;
        cout << "------------End of Line-----------\n";
    }

    size_t getCount()
    {
        return guests.size();
    }
};

int main()
{
    GuestTracker guests;
    do
    {
        int choice;
        cout << "Select from the options below:" << endl
             << "1. Add guests" << endl
             << "2. View guests" << endl
             << "3. Get total count" << endl
             << "4. EXIT" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            guests.addGuests();
            break;
        case 2:
            guests.viewGuests();
            break;
        case 3:
        {
            size_t total = guests.getCount();
            cout << "\e[1;32mTotal Number of guests: " << total << "\e[0m\n";
        }
        break;
        case 4:
            cout << "EXITING..." << endl;
            return 0;
            break;

        default:
            cout << "\e[1;31mINVALID CHOICE\e[0m\n";
            break;
        }
    } while (true);
    return 0;
}