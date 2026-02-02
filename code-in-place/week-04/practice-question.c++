#include <iostream>
using namespace std;

class LibMember {
private:
    const int memberID;
    string memberName;
    int booksIssued;
    static int totalMembers;
    static const int maxBooks;
public:
    LibMember(int ID, string name) : memberID(ID), memberName(name), booksIssued(0) {
        totalMembers++;
    }
    void issueBook() {
        if (booksIssued < maxBooks)
            booksIssued++;
        else
            cout << "Max limit reached.";
    }
    void display() const {
        cout << "ID: " << memberID << " Name: \"" << memberName << "\" Books Issued: " << booksIssued << endl;
    }
    static int getTotalMembers() {
        return LibMember::totalMembers;
    }
};

int LibMember::totalMembers = 0;
const int LibMember::maxBooks = 5;

int main() {
    LibMember mem1(1, "abc"), mem2(2, "def");
    mem1.issueBook();
    mem1.display();
    mem1.issueBook();
    mem1.display();
    cout << "Total Members: "<< LibMember::getTotalMembers();
    return 0;
}