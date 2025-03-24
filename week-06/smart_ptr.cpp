#include <iostream>
#include <string>
template<typename T>
class SmartPtr
{
    T* intptr;
public:
    SmartPtr(T* ptr) 
    {
        std::cout << "In constructor" << std::endl;
        intptr = ptr;
    }
    ~SmartPtr() 
    {
        std::cout << "In Destructor" << std::endl;
        delete intptr;
    }
    T& operator *() 
    {
        std::cout << "In operator *" << std::endl;
        return *intptr; 
    }
    T* operator->() 
    {
        std::cout << "In operator ->" << std::endl;
        return intptr;
    }
};
class Sample {
    public:
     int x;
        void fun() {
            std::cout << "Sample fun() called!" << std::endl;
        }
    };
int main()
{
    Sample sample;
    SmartPtr<Sample> sampleptr(new Sample());
    sampleptr->fun();
    // Using SmartPtr with a char
    SmartPtr<char> charPtr(new char('A'));
    std::cout << "Character value: " << *charPtr << std::endl;

    // Using SmartPtr with a std::string
    SmartPtr<std::string> strPtr(new std::string("Hello, World!"));
    std::cout << "String value: " << *strPtr << std::endl;

    return 0;
}
