#include<iostream>
using namespace std;
// product class or product interface class
class transport{
    public:
    virtual void transport_by()=0;
    virtual ~transport()=default;
};
// concrete product class
class truck: public transport{
    public:
    void transport_by(){
        cout<<"transport by truck"<<endl;
    }
};
// concrete product class
class ship: public transport{
    public:
    void transport_by(){
        cout<<"transport by ship"<<endl;
    }
};
// creator class
class logistics{
    public:
    virtual transport* make_delivery()=0;
    void plan_dilvery(){
         transport* ptr=this->make_delivery();
         ptr->transport_by();
    }
};
//concrete creator class
class transport_by_truck: public logistics {
    public:
    transport* make_delivery(){
        return new truck();
    }
};
//concrete creator class
class transport_by_ship: public logistics {
     public:
    transport* make_delivery(){
        return new ship();
    }
};
void clientcode(logistics *obj){
    obj->plan_dilvery();
}
int main(){
    transport_by_truck obj_truck;
    clientcode(&obj_truck);
}

//***********  using smart_pointer*********************

 #include <iostream>
 #include <string>
#include <memory> // Required for std::unique_ptr

// --- 1. Product Interface ---
// Defines the interface for objects the factory method creates.
class Transport {
public:
    // Use default virtual destructor for proper cleanup in inheritance
    virtual ~Transport() = default;
    virtual void deliver() const = 0; // Pure virtual function
};

// --- 2. Concrete Products ---
// Implement the Product interface.
class Truck : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering cargo by land in a truck." << std::endl;
    }
};

class Ship : public Transport {
public:
    void deliver() const override {
        std::cout << "Delivering cargo by sea in a ship." << std::endl;
    }
};

// --- 3. Creator (Abstract Class) ---
// Declares the factory method, which returns an object of type Product.
// It might also define methods that use the Product object.
class Logistics {
public:
    virtual ~Logistics() = default; // Virtual destructor

    // --- The Factory Method ---
    // It's declared virtual (often pure virtual = 0) so subclasses MUST implement it.
    // Returns a smart pointer to the base Product type.
    virtual std::unique_ptr<Transport> createTransport() const = 0;

    // --- Core Business Logic ---
    // This method uses the product created by the factory method.
    // It doesn't know the concrete type of product it's working with.
    void planDelivery() const {
        // Call the factory method to get a product object.
        std::unique_ptr<Transport> transport = createTransport();

        // Now, use the product.
        std::cout << "Logistics: Planning delivery using the created transport..." << std::endl;
        transport->deliver(); // Polymorphic call
        std::cout << "Logistics: Delivery planned." << std::endl;
    }
};

// --- 4. Concrete Creators ---
// Override the factory method to return an instance of a ConcreteProduct.
class RoadLogistics : public Logistics {
public:
    // Override the factory method to create a Truck
    std::unique_ptr<Transport> createTransport() const override {
        // Use std::make_unique for modern C++ memory management
        return std::make_unique<Truck>();
    }
};

class SeaLogistics : public Logistics {
public:
    // Override the factory method to create a Ship
    std::unique_ptr<Transport> createTransport() const override {
        return std::make_unique<Ship>();
    }
};

// --- 5. Client Code ---
// The client code works with an instance of a ConcreteCreator,
// although often through its base Creator interface.
void clientCode(const Logistics& logistics_company) {
    std::cout << "\nClient: I'm not aware of the specific logistics type, but I need delivery planned." << std::endl;
    // The client calls the Creator's method, which internally uses the
    // factory method to get the right Product, but the client doesn't know which.
    logistics_company.planDelivery();
}

int main() {
    std::cout << "App: Launched with RoadLogistics." << std::endl;
    // Create a specific creator (could be determined at runtime)
    std::unique_ptr<Logistics> road_logistics = std::make_unique<RoadLogistics>();
    // Pass the creator (as a base class reference) to the client code
    clientCode(*road_logistics);

    std::cout << "\n--------------------------------\n";

    // std::cout << "App: Launched with SeaLogistics." << std::endl;
    // std::unique_ptr<Logistics> sea_logistics = std::make_unique<SeaLogistics>();
    // clientCode(*sea_logistics);

    return 0;
} 


//-------------------
// #include<iostream>
// #include<memory>
// using namespace std;
// // product
// class transport{
//     public:
//     virtual void transport_by()=0;
//     virtual ~transport()=default;
// };
// class truck: public transport{
//     public:
//     void transport_by(){
//         cout<<"transport by truck"<<endl;
//     }
// };
// class ship: public transport{
//     public:
//     void transport_by(){
//         cout<<"transport by ship"<<endl;
//     }
// };
// class logistics{
//     public:
//     virtual unique_ptr<transport> make_delivery()=0;
//     void plan_dilvery(){
//           unique_ptr<transport> ptr=this->make_delivery();
//          ptr->transport_by();
//     }
// };
// class transport_by_truck: public logistics {
//     public:
//      unique_ptr<transport> make_delivery(){
//         return make_unique<truck>();
//     }
// };
// class transport_by_ship: public logistics {
//      public:
//      unique_ptr<transport> make_delivery(){
//         return make_unique<ship>();
//     }
// };
// void clientcode(unique_ptr<logistics> obj){
//     obj->plan_dilvery();
// }
// int main(){
//      unique_ptr<logistics> obj_truck= make_unique<transport_by_ship>();
//     clientcode(move(obj_truck));
// }