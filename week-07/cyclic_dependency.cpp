/*
Cyclic dependecy between two class both having weak pointers.
*/

#include <iostream>
#include <memory>
using namespace std;
class ClassB; 
class ClassA {
public:
    ClassA() {
        cout << "ClassA created\n";
    }
    ~ClassA() {
        cout << "ClassA destroyed\n";
    }
    void setB(std::shared_ptr<ClassB> b) {
        bPtr = b; 
    }
    void doSomething() {
        if (auto b = bPtr.lock()) { // Lock the weak_ptr to get a shared_ptr
            cout << "ClassA is doing something with ClassB\n";
        } else {
           cout << "ClassB is no longer available\n";
        }
    }
private:
    weak_ptr<ClassB> bPtr; // Weak pointer to ClassB
};
class ClassB {
public:
    ClassB() {
        cout << "ClassB created\n";
    }
    ~ClassB() {
        cout << "ClassB destroyed\n";
    }

    void setA(std::shared_ptr<ClassA> a) {
        aPtr = a; // Store shared_ptr to ClassA
    }
    void doSomething() {
        if (auto a = aPtr.lock()) { // Lock the weak_ptr to get a shared_ptr
            cout << "ClassB is doing something with ClassA\n";
        } else {
            cout << "ClassA is no longer available\n";
        }
    }
private:
    std::weak_ptr<ClassA> aPtr; 
};

int main() {
    // Create shared pointers to ClassA and ClassB
    auto a = make_shared<ClassA>();
    auto b = make_shared<ClassB>();
    a->setB(b);
    b->setA(a);
    cout<<a.use_count()<<endl;
    cout<<b.use_count()<<endl;
    // Use the classes
    a->doSomething();
    b->doSomething();
    return 0;
}