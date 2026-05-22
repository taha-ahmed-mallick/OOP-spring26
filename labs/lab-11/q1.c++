#include <iostream>
using namespace std;

class NoDigitsErr
{
public:
    const char *what()
    {
        return "\e[1;31mPassword has no digits!\e[0m";
    }
};

class InsuffLenErr
{
public:
    const char *what()
    {
        return "\e[1;31mInsufficient password length!!\e[0m";
    }
};

class User
{
private:
    string usrName, pass;

public:
    User() : usrName(""), pass("") {}

    bool hasDigits(string pass)
    {
        for (char c : pass)
            if (c >= '0' && c <= '9')
                return true;
        return false;
    }

    void login()
    {
        string input;
        cout << "Enter your user name: ";
        getline(cin, input);
        usrName = input;
        cout << "Enter your password: ";
        getline(cin, input);
        if (input.length() < 6)
            throw InsuffLenErr();
        if (!hasDigits(input))
            throw NoDigitsErr();
        pass = input;
        cout << "\e[1;32mLogin is successful.\e[0m\n";
    }
};

int main()
{
    User usr;
    try
    {
        usr.login();
    }
    catch (InsuffLenErr &e)
    {
        cout << e.what() << endl;
    }
    catch (NoDigitsErr &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}