// Definition:
// Clients should not be forced to depend on interfaces they do not use.

//  Focuses On:
// Interfaces

// Making interfaces small, focused, and client-specific

// Avoiding "fat" or overly generic interfaces



#include<iostream>
using namespace std;
#include <iostream>
class IMachine {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
    virtual ~IMachine() = default;
};

class OldPrinter : public IMachine {
public:
    void print() override {
        std::cout << "Printing document\n";
    }
    void scan() override {
        std::cout << "Cannot scan!\n";  //  Bad: not supported
    }
    void fax() override {
        std::cout << "Cannot fax!\n";  //  Bad: not supported
    }
};

int main(){
    OldPrinter obj;
    obj.print();
}


// BAD IMPLEMENTATION WHERE OldPrinter is forced to implement scan() and fax() even though it can't. 
// above code VOILETS INTERFACE SEGREGATION PRINCIPLE.

#include <iostream>

class IPrinter {
public:
    virtual void print() = 0;
    virtual ~IPrinter() = default;
};

class IScanner {
public:
    virtual void scan() = 0;
    virtual ~IScanner() = default;
};

class IFax {
public:
    virtual void fax() = 0;
    virtual ~IFax() = default;
};

// Now implement only what you need
class BasicPrinter : public IPrinter {
public:
    void print() override {
        std::cout << "Printing document\n";
    }
};

class OfficePrinter : public IPrinter, public IScanner, public IFax {
public:
    void print() override {
        std::cout << "Printing...\n";
    }

    void scan() override {
        std::cout << "Scanning...\n";
    }

    void fax() override {
        std::cout << "Faxing...\n";
    }
};


// Ques--> Single Responsibility Principle (SRP) vs Interface Segregation Principle (ISP).