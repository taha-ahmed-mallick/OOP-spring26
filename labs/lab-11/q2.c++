#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Stack
{
private:
    vector<char> stack;

public:
    Stack() {}
    void input()
    {
        string input;
        cout << "Enter any sentence: ";
        getline(cin, input);
        for (char c : input)
            stack.push_back(c);
    }
    void push(char c)
    {
        stack.push_back(c);
    }
    char pop()
    {
        if (!stack.empty())
        {
            char last = stack.back();
            stack.pop_back();
            return last;
        }
        else
            throw "Stack Underflow";
    }
    char peek()
    {
        if (!stack.empty())
            return stack.back();
        else
            return '\0';
    }
    void view()
    {
        cout << "Stack is filled with: \e[32m";
        for (const char &c : stack)
            cout << c;
        cout << "\e[0m" << endl;
    }
    void reverse()
    {
        string reversed = "", word = "";
        for (const char &c : stack)
        {
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            {
                word += c;
            }
            else
            {
                std::reverse(word.begin(), word.end());
                reversed += word + c;
                word = "";
            }
        }
        stack.clear();
        for (const char &c : reversed)
            stack.push_back(c);
        cout << "Your reversed string: \e[1;33m" << reversed << "\e[0m" << endl;
    }
};

int main()
{
    Stack stack;
    stack.input();

    do
    {
        int choice;
        cout << "\nSelect a option:" << endl
             << "1. Push a character" << endl
             << "2. Pop a character" << endl
             << "3. Peek at stack" << endl
             << "4. View Stack Elements" << endl
             << "5. Reverse each word in stack" << endl
             << "6. EXIT" << endl;
        cout << "What do u want to perform? ";
        cin >> choice;
        cout << endl
             << endl;
        switch (choice)
        {
        case 1:
        {
            char input;
            cout << "Enter a character you want to push: ";
            cin >> input;
            stack.push(input);
            break;
        }
        case 2:
        {
            char popped = stack.pop();
            cout << "Popped element was: " << popped << endl;
            break;
        }
        case 3:
        {
            char peek = stack.peek();
            cout << "Top of stack: " << peek << endl;
            break;
        }
        case 4:
            stack.view();
            break;
        case 5:
            stack.reverse();
            break;
        case 6:
            cout << "EXITING...\n";
            return 0;
            break;

        default:
            cout << "\e[1;31mINVALID CHOICE\e[0m\n";
            break;
        }
    } while (true);
    return 0;
}