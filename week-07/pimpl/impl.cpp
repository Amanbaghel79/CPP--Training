
#include "header.h"
#include<iostream>
 
class MyClassImpl {
public:

    std::string name; 
    void calc() {
        std::cout << "doing some inner calculation";
    }
};

MyClass::MyClass() : ptr(std::make_unique<MyClassImpl>()) {
    
}

MyClass::~MyClass() = default; 

void MyClass::setName(const std::string& name) {
    ptr->name = name;
}

std::string MyClass::getName() const{
    return ptr->name; 
}

void MyClass::calc() {
    ptr->calc(); 
}