#include <iostream>
using namespace std;

class EncryptionTechnique
{
protected:
    string text;

public:
    EncryptionTechnique(const string &text) : text(text) {}

    virtual string encrypt() const = 0;
};

class EncryptionTechnique1 : public EncryptionTechnique
{
public:
    EncryptionTechnique1(const string &text) : EncryptionTechnique(text) {}
    string encrypt() const override
    {
        string encrypted = "";
        for (char c : text)
            encrypted += to_string(static_cast<int>(c));
        return encrypted;
    }
};

class EncryptionTechnique2 : public EncryptionTechnique
{
public:
    EncryptionTechnique2(const string &text) : EncryptionTechnique(text) {}
    string encrypt() const override
    {
        string encrypted = "";
        for (char c : text)
            encrypted += to_string(static_cast<int>(c + 2));
        return encrypted;
    }
};

int main()
{
    string test = "HELLO";
    EncryptionTechnique *arr[2];
    arr[0] = new EncryptionTechnique1(test);
    arr[1] = new EncryptionTechnique2(test);

    for (int i = 0; i < 2; i++)
    {
        string result = arr[i]->encrypt();
        cout << result << endl;
        delete arr[i];
    }
    return 0;
}