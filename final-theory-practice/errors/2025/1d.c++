#include <iostream>
using namespace std;

class Book
{
private:
    string *title;
    bool borrowed;

public:
    Book(string t) : title(new string(t)), borrowed(false) {}
    Book(const Book &other)
    {
        title = new string(*other.title);
    }
    void operator=(Book other)
    {
        *title = *other.title;
    }
    void status()
    {
        cout << *title << ": " << borrowed << endl;
    }
};
int main()
{
    Book b1("Book1");
    Book b2 = b1;
    b2 = b1;
    // b1.status();
    b2.status();
}