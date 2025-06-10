// Abstract Factory Pattern is a creational design pattern used in object-oriented 
// programming. It provides an interface for creating families of related or dependent
//  objects without specifying their concrete classes.


// The client doesn't care about the concrete classes of products; it just calls the factory's
//  methods to get a complete car set (engine + tyres).

#include <iostream>
using namespace std;
// product class
class phone{
    public:
    virtual void phone_price()=0;
    virtual ~phone()=default;
};
// concrete product
class redmi_budget_phone: public phone{
    public:
    void phone_price(){
        cout<<"your redmi budget phone phone price is\n";
    }
};
class redmi_flagship_phone: public phone{
    public:
    void phone_price(){
        cout<<"your redmi flagship phone phone price is\n";
    }
};
class samsung_budget_phone: public phone{
    public:
    void phone_price(){
        cout<<"your samsung budget phone phone price is\n";
    }
};
class samsung_flagship_phone: public phone{
    public:
    void phone_price(){
        cout<<"your samsung flagship phone phone price is\n";
    }
};
class phonefactory{
    public:
    virtual phone* get_budget_phone()=0;
    virtual phone* get_flagship_phone()=0;
};

//concrete factory
class redmi_factory: public phonefactory {
    public:
    phone* get_budget_phone(){
        return new redmi_budget_phone();
    }
    phone* get_flagship_phone(){
         return new redmi_flagship_phone();
    }
};

//concrete factory
class samsung_factory: public phonefactory{
    public:
    phone* get_budget_phone(){
        return new samsung_budget_phone();
    }
    phone* get_flagship_phone(){
         return new samsung_flagship_phone();
    }
};
void clientcode(phonefactory* pphone ){
    phone *b_phone=pphone->get_budget_phone();
    phone *f_phone=pphone->get_flagship_phone();
    b_phone->phone_price();
    f_phone->phone_price();
}
int main()
{
    redmi_factory redmi_phone;
    clientcode(&redmi_phone);
}


//-----------------more practical example below---------------------------
#include <iostream>
#include <memory>
using namespace std;

// 1. Abstract Product A: Engine
class Engine {
public:
    virtual void create() = 0;
    virtual ~Engine() = default;
};

// 2. Abstract Product B: Tyre
class Tyre {
public:
    virtual void create() = 0;
    virtual ~Tyre() = default;
};

// 3. Concrete Product A1: Family Car Engine
class FamilyCarEngine : public Engine {
public:
    void create() override {
        cout << "Creating Family Car Engine: 4-cylinder engine.\n";
    }
};

// 4. Concrete Product A2: Sports Car Engine
class SportsCarEngine : public Engine {
public:
    void create() override {
        cout << "Creating Sports Car Engine: 8-cylinder turbo engine.\n";
    }
};

// 5. Concrete Product B1: Family Car Tyre
class FamilyCarTyre : public Tyre {
public:
    void create() override {
        cout << "Creating Family Car Tyre: Standard rubber tyres.\n";
    }
};

// 6. Concrete Product B2: Sports Car Tyre
class SportsCarTyre : public Tyre {
public:
    void create() override {
        cout << "Creating Sports Car Tyre: High-performance tyres.\n";
    }
};

// 7. Abstract Factory: Car Factory
class CarFactory {
public:
    virtual unique_ptr<Engine> createEngine() = 0;
    virtual unique_ptr<Tyre> createTyre() = 0;
    virtual ~CarFactory() = default;
};

// 8. Concrete Factory 1: Family Car Factory
class FamilyCarFactory : public CarFactory {
public:
    unique_ptr<Engine> createEngine() override {
        return make_unique<FamilyCarEngine>();
    }
    unique_ptr<Tyre> createTyre() override {
        return make_unique<FamilyCarTyre>();
    }
};

// 9. Concrete Factory 2: Sports Car Factory
class SportsCarFactory : public CarFactory {
public:
    unique_ptr<Engine> createEngine() override {
        return make_unique<SportsCarEngine>();
    }
    unique_ptr<Tyre> createTyre() override {
        return make_unique<SportsCarTyre>();
    }
};

// 10. Client Code
void clientCode(CarFactory& factory) {
    auto engine = factory.createEngine();
    auto tyre = factory.createTyre();

    engine->create();
    tyre->create();
}

int main() {
    cout << "--- Family Car ---\n";
    FamilyCarFactory familyFactory;
    clientCode(familyFactory);  // Creating a Family Car (Engine + Tyres)

    cout << "\n--- Sports Car ---\n";
    SportsCarFactory sportsFactory;
    clientCode(sportsFactory);  // Creating a Sports Car (Engine + Tyres)

    return 0;
}
