#include <iostream>
#include <string>

// ==========================================
// 1. ABSTRACT BASE CLASS: Vehicle
// ==========================================
class Vehicle {
private:
    std::string carId;
    std::string brand;
    std::string model;

public:
    Vehicle(std::string id, std::string b, std::string m) 
        : carId(id), brand(b), model(m) {}

    // Pure Virtual Functions - establishing the interface contract
    virtual bool isAvailable() const = 0;
    virtual void rent() = 0;
    virtual void returnCar() = 0; // Added to fulfill returnVehicle requirements

    // Encapsulation helpers
    std::string getDetails() const {
        return brand + " " + model + " [" + carId + "]";
    }

    virtual ~Vehicle() = default; // Essential for safe heap cleanup
};

// ==========================================
// 2. DERIVED CLASS: Car
// ==========================================
class Car : public Vehicle {
private:
    bool availabilityStatus; // Specific attribute required by manual

public:
    Car(std::string id, std::string b, std::string m) 
        : Vehicle(id, b, m), availabilityStatus(true) {}

    // Concrete implementations of the virtual contract
    bool isAvailable() const override {
        return availabilityStatus;
    }

    void rent() override {
        availabilityStatus = false; 
    }

    void returnCar() override {
        availabilityStatus = true;
    }
};

// ==========================================
// 3. RENTAL SYSTEM CLASS: RentalSystem
// ==========================================
class RentalSystem {
public:
    // Interacts strictly through the abstract base class interface
    void rentVehicle(Vehicle* vehicle) {
        if (vehicle->isAvailable()) {
            vehicle->rent();
            std::cout << "[RentalSystem] Approved. " << vehicle->getDetails() << " has been checked out.\n";
        } else {
            std::cout << "[RentalSystem] Denied. " << vehicle->getDetails() << " is currently unavailable.\n";
        }
    }

    void returnVehicle(Vehicle* vehicle) {
        vehicle->returnCar();
        std::cout << "[RentalSystem] Processing Return. " << vehicle->getDetails() << " is back in inventory.\n";
    }
};

// ==========================================
// 4. CUSTOMER CLASS: Customer
// ==========================================
class Customer {
private:
    std::string name;

public:
    Customer(std::string customerName) : name(customerName) {}

    // Interacts with RentalSystem without knowing the specific type of vehicle
    void rentVehicle(RentalSystem& system, Vehicle* vehicle) {
        std::cout << "[Customer] " << name << " is attempting to rent a vehicle...\n";
        system.rentVehicle(vehicle); // Delegates operation entirely to the controller
    }

    void returnVehicle(RentalSystem& system, Vehicle* vehicle) {
        std::cout << "[Customer] " << name << " is returning a vehicle...\n";
        system.returnVehicle(vehicle);
    }
};

// ==========================================
// TEST PROGRAM (With Dynamic Heap Array of Pointers)
// ==========================================
int main() {
    // 1. Setup our decoupled environment entities
    RentalSystem agencyController;
    Customer customer("Hamza");

    // 2. Define an array of pointers of the Base class (Stack allocated array of 8-byte pointers)
    Vehicle* inventory[2];

    // 3. Allocate dynamic memory on the Heap for the concrete objects
    inventory[0] = new Car("KHI-789", "Toyota", "Corolla");
    inventory[1] = new Car("LHR-123", "Suzuki", "Swift");

    std::cout << "=== SIMULATING RENTAL PIPELINE ===\n\n";

    // First transaction: Successful Rent
    customer.rentVehicle(agencyController, inventory[0]);
    std::cout << "\n";

    // Second transaction: Trying to rent an already occupied vehicle
    customer.rentVehicle(agencyController, inventory[0]);
    std::cout << "\n";

    // Third transaction: Returning the vehicle
    customer.returnVehicle(agencyController, inventory[0]);
    std::cout << "\n";

    // Fourth transaction: Renting it again after a successful return
    customer.rentVehicle(agencyController, inventory[0]);
    std::cout << "\n";

    // Clean up memory from the Heap
    delete inventory[0];
    delete inventory[1];

    return 0;
}