#include <iostream>
#include "header.h"

int main() {
    MyClass myObject; 
    myObject.setName("Pimpl Example"); 
    myObject.calc();
    std::cout << "Name: " << myObject.getName() << std::endl; 
    return 0; 
}