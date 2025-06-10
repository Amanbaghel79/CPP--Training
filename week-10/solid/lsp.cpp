//Objects of a superclass should be replaceable with objects of its subclasses without
// breaking the behavior of the program.

// Objects of a subclass should be replaceable for objects of the base class without affecting program correctness.

//  Focuses On:
// Inheritance & Polymorphism

// Making sure derived classes respect the behavior contract of base classes

#include<iostream>
using namespace std;
class bird{
    public:
    virtual void fly() const{
        cout<<"bird can fly"<<endl;
    }
    virtual ~bird() =default;
};
class dove: public bird{
    public:
    void fly() const override {
        cout<<"dove can fly"<<endl;
    }
};

//-----voilation of lsp-----
class Penguin : public bird {
    public:
        void fly() const override {
            throw std::logic_error("Penguins can't fly!");  //  Violates LSP
        }
    };
class peacock: public bird{
    public:
    void fly() const override{
        cout<<"peacock can fly"<<endl;
    }
};
void makeitfly(bird& obj){
    obj.fly();
}
int main(){
   bird birdb;
   dove obj1;
   peacock obj2;
   makeitfly(birdb);
   makeitfly(obj1);
   makeitfly(obj2);
}


//-----------ways of lsp voilations
//--rectangle and square problem of lsp