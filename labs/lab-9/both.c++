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
    string input;
    cout << "Enter The Text: ";
    getline(cin, input);
    EncryptionTechnique *encryption[2];
    DecryptionTechnique *decryption[2];
    encryption[0] = new EncryptionTechnique1(input);
    encryption[1] = new EncryptionTechnique2(input);
    decryption[0] = new DecryptionTechnique1(encryption[0]->encrypt());
    decryption[1] = new DecryptionTechnique2(encryption[1]->encrypt());
    for (int i = 0; i < 2; i++)
        cout << "TECHNIQUE " << i + 1 << " :" << endl
             << "Encrption: " << encryption[i]->encrypt() << endl
             << "Decryption: " << decryption[i]->decrypt() << endl;

    return 0;
}