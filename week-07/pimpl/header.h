
#ifndef MYCLASS_H
#define MYCLASS_H

#include <memory>
#include <string>


class MyClassImpl;

class MyClass {
public:
    MyClass();                
    ~MyClass();               

    void setName(const std::string& name); 
    void calc();
    std::string getName() const;            

private:
    std::unique_ptr<MyClassImpl> ptr; 
};

#endif 