#include <iostream>

// Abstract Base Class acting as the standard invoicing blueprint
class Store {
protected:
    double total_bill; // Base field populated via constructor tracking raw cost

public:
    // Explicit parameterized constructor
    Store(double bill) : total_bill(bill) {}

    // Pure Virtual Function enforcing uniform billing retrieval interface
    virtual double calculateBill() const = 0;

    // Virtual destructor ensuring safe resource cleanup on polymorphic deletion
    virtual ~Store() = default;
};

// Derived Class for Imtiaz Store (7% discount strategy)
class ImtiazStore : public Store {
public:
    // Chaining the constructor: explicitly passing the value up to the base class
    ImtiazStore(double bill) : Store(bill) {}

    // Overriding interface to inject specific 7% deduction logic
    double calculateBill() const override {
        double discount = total_bill * 0.07;
        return total_bill - discount;
    }
};

// Derived Class for Bin Hashim Store (5% discount strategy)
class BinHashimStore : public Store {
public:
    // Chaining the constructor up to the base layout
    BinHashimStore(double bill) : Store(bill) {}

    // Overriding interface to inject specific 5% deduction logic
    double calculateBill() const override {
        double discount = total_bill * 0.05;
        return total_bill - discount;
    }
};

int main() {
    double rawAmount = 10000.0; // Sample bill amount (e.g., 10,000 PKR)

    // Using Polymorphic pointers pointing to discrete heap object variants
    Store* store1 = new ImtiazStore(rawAmount);
    Store* store2 = new BinHashimStore(rawAmount);

    std::cout << "Original Gross Bill: " << rawAmount << " PKR\n";
    std::cout << "-------------------------------------------\n";
    
    // Runtime polymorphism reads the precise object type from the hidden Vtable
    std::cout << "Finalized Checkout Price at Imtiaz (7% off):    " 
              << store1->calculateBill() << " PKR\n";
              
    std::cout << "Finalized Checkout Price at Bin Hashim (5% off): " 
              << store2->calculateBill() << " PKR\n";

    // Releasing heap resources manually to prevent memory exhaustion
    delete store1;
    delete store2;

    return 0;
}