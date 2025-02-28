#include <iostream>
using namespace std;
//Compile time polymorphism.
// class myclass {
// public:
//     void show(int i) {
//         cout << "Integer: " << i << endl;
//     }
//     void show(double d) {
//         cout << "Double: " << d << endl;
//     }
//     void show(string s) {
//         cout << "String: " << s << endl;
//     }
// };
class Animal {
    public:
        // Virtual function
        virtual void sound() {
            cout << "Some animal sound!" << endl;
        }
    };
    class Dog : public Animal{
    public:
        void sound()  { // Override the base class function
            cout << "Bark" << endl;
        }
    };
    class Cat : public Animal {
    public:
        void sound()  { // Override the base class function
            cout << "Meow" << endl;
        }
 };
int main(){
    //***Compile time polymorphism
    // myclass obj;
    // obj.show(5);          
    // obj.show(3.14);       
    // obj.show("Hello");    
    // return 0;

    //*** Runtime polymorphism***----
    Animal* animalPtr;
    Dog dog;
    Cat cat;
    // Using base class pointer to call derived class functions
    animalPtr = &dog;
    animalPtr->sound();  // Output: Bark!
    //call the function of that class whose address is stored in the pointer.
    animalPtr = &cat;
    animalPtr->sound();  // Output: Meow!
    return 0;
}

