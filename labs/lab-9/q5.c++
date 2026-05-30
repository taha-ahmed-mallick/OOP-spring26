#include <iostream>
using namespace std;

class DecryptionTechnique
{
protected:
    string text;

public:
    DecryptionTechnique(const string &text) : text(text) {}

    virtual string decrypt() const = 0;
};

class DecryptionTechnique1 : public DecryptionTechnique
{
public:
    DecryptionTechnique1(const string &text) : DecryptionTechnique(text) {}
    string decrypt() const override
    {
        string decrypted = "";
        for (int i = 0; i < text.size();)
        {
            string num = "";
            if (text[i] == '1')
                for (int j = 0; j < 3; j++, i++)
                    num += text[i];
            else
                for (int j = 0; j < 2; j++, i++)
                    num += text[i];
            char c = static_cast<char>(stoi(num));
            decrypted += c;
        }
        return decrypted;
    }
};

class DecryptionTechnique2 : public DecryptionTechnique
{
public:
    DecryptionTechnique2(const string &text) : DecryptionTechnique(text) {}
    string decrypt() const override
    {
        string decrypted = "";
        for (int i = 0; i < text.size();)
        {
            string num = "";
            if (text[i] == '1')
                for (int j = 0; j < 3; j++, i++)
                    num += text[i];
            else
                for (int j = 0; j < 2; j++, i++)
                    num += text[i];
            char c = static_cast<char>(stoi(num) - 2);
            decrypted += c;
        }
        return decrypted;
    }
};

int main()
{
    DecryptionTechnique *arr[2];
    arr[0] = new DecryptionTechnique1("7269767679");
    arr[1] = new DecryptionTechnique2("7471787881");

    for (int i = 0; i < 2; i++)
    {
        string result = arr[i]->decrypt();
        cout << result << endl;
        delete arr[i];
    }
    return 0;
}