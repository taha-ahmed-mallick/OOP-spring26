#include <iostream>
using namespace std;

class BookType
{
    string title, author[4], pub;
    int ISBN, yrOfPub, noOfCpy, noOfAuth;
    float price;

public:
    void getTitle()
    {
        cout << "Title: " << title << endl;
    }
    void setTitle(const string t)
    {
        title = t;
    }
    bool checkTitle(const string t)
    {
        return title == t;
    }

    void getCopies()
    {
        cout << "Number of Copies: " << noOfCpy << endl;
    }
    void setCopies(const int num)
    {
        noOfCpy = num;
    }
    void updateCopies(const int num)
    {
        noOfCpy += num;
    }

    void setAuth(const string auth)
    {
        if (noOfAuth < 4)
            author[noOfAuth++] = auth;
        else
            cout << "Max Limit Reached!!\n";
    }
    void getAuth()
    {
        cout << "No. of authors: " << noOfAuth << endl;
        for (int i = 0; i < noOfAuth; i++)
        {
            cout << "Author" << i + 1 << ": " << author[i] << endl;
        }
    }

    void getPub()
    {
        cout << "Publication: " << pub << endl;
    }
    void setPub(const string t)
    {
        pub = t;
    }

    void getPrice()
    {
        cout << "Price: $" << price << endl;
    }
    void setPub(float p)
    {
        price = p;
    }

    void getISBN()
    {
        cout << "ISBN: " << ISBN << endl;
    }
    void setISBN(int i)
    {
        ISBN = i;
    }

    BookType()
    {
        pub = title = "Unknown";
        for (int i = 0; i < 4; i++)
            author[i] = "N/A";
        ISBN = yrOfPub = noOfCpy = noOfAuth = price = 0;
    }
};

int main()
{

    BookType books[10];

    return 0;
}