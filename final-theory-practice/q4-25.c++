#include <iostream>
using namespace std;

class Medicine
{
protected:
    string name;
    int price;

public:
    Medicine(string name, int price) : name(name), price(price) {}
    virtual void displayDet() const = 0;
};

class PrescriptionMedicine : virtual public Medicine
{
protected:
    string docName, patName, date;

public:
    PrescriptionMedicine(string name, int price, string docName, string patName, string date) : Medicine(name, price), docName(docName), patName(patName), date(date) {}
    void displayDet() const override
    {
        cout << "Prescription med" << endl;
        cout << "Name: " << name << endl
             << "Price: " << price << endl;
    }
};

class OTCMedicine : virtual public Medicine
{
protected:
    int maxDosage;
    int ageRestriction;

public:
    OTCMedicine(string name, int price, int max, int age) : Medicine(name, price), maxDosage(max), ageRestriction(age) {}
    void displayDet() const override
    {
        cout << "OTC" << endl
             << "Name: " << name << endl
             << "Price: " << price << endl;
    }
};

class HybridMed: public PrescriptionMedicine , public OTCMedicine {
    public:
    HybridMed(string name, int price, string docName, string patName, string date, int max, int age) : Medicine(name,price), PrescriptionMedicine(name, price, docName, patName, date), OTCMedicine(name, price, max, age) {}
    void displayDet() const override {
        cout << "Hybrid" << endl;
    }
};

int main()
{
    return 0;
}