#include <iostream>
using namespace std;

class Media {
public:
    virtual void borrow() = 0;
    virtual void returning() = 0;
    virtual void display() = 0;
};

class BookAttr {
protected:
    string name, author;
    int numPage;
public:
    BookAttr(string name, string auth, int pg) : name(name), author(auth), numPage(pg) {}
};

class MagzineAttr {
protected:
    string editor;
    int revision, issueNum;
public:
    MagzineAttr(string editor, int num, int rev) : editor(editor), issueNum(num), revision(rev) {}
};

class DVDAttr {
protected:
    string name, director;
    int numAlbums;
public:
    DVDAttr(string name, string director, int numAlbums) : name(name), director(director), numAlbums(numAlbums) {}
};

class Book : protected Media, protected BookAttr {
public:
    Book(string name, string auth, int pg) : BookAttr(name, auth, pg) {}
    void borrow() {
        cout << "Borrowing " << name << " by: " << author << endl;
    }
    void returning() {
        cout << "Returning " << name << endl;
    }
    void display() {
        cout << "INFO:-" << endl;
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << numPage << endl;
    }
};

class Magzine : protected Media, protected MagzineAttr {
public:
    Magzine(string editor, int num, int rev) : MagzineAttr(editor, num, rev) {}
    void borrow() {
        cout << "Borrowing Magzine number " << issueNum << " by: " << editor << endl;
    }
    void returning() {
        cout << "Returning Magzine " << issueNum << " Revision: " << revision << endl;
    }
    void display() {
        cout << "INFO:-" << endl;
        cout << "Issue: " << issueNum << endl;
        cout << "Revision: " << revision << endl;
        cout << "Editor: " << editor << endl;
    }
};

class DVD : protected Media, protected DVDAttr {
public:
    DVD(string name, string director, int numAlbums) : DVDAttr(name, director, numAlbums) {}
    void borrow() {
        cout << "Borrowing " << name << " by: " << director << endl;
    }
    void returning() {
        cout << "Returing " << name << endl;
    }
    void display() {
        cout << "INFO:-" << endl;
        cout << "Name: " << name << endl;
        cout << "Director: " << director << endl;
        cout << "Albums: " << numAlbums << endl;
    }
};

int main() {
    Book b1("ABC", "CDE", 56);
    Magzine m1("Student Digest", 123, 456);
    DVD d1("XYZ", "PQR", 5);
    b1.display();
    m1.display();
    d1.display();
    cout << endl;
    b1.borrow();
    return 0;
}