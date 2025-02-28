#include <iostream>
using namespace std;
class Base {
public:
    int publicVar;  // Accessible in Derived
protected:
    int protectedVar;  // Accessible in Derived
private:
    int privateVar;  // Not accessible in Derived

public:
    Base() {
        publicVar = 9;
        protectedVar = 2;
        privateVar = 3;
    }
};

//***-----------Public iheritance-----------***
class Derived : public Base {
public:
    void display() {
        cout << "publicVar: " << publicVar << endl;  // Accessible
        cout << "protectedVar: " << protectedVar << endl;  // Accessible
        // cout << "privateVar: " << privateVar << endl;  // Error: privateVar is not accessible
    }
};

//****--------- Protected inheritance----------------****
// class Derived : protected Base {
//     public:
//         void display() {
//             cout << "publicVar: " << publicVar << endl;  
//             cout << "protectedVar: " << protectedVar << endl;  
//             // cout << "privateVar: " << privateVar << endl;  // Error: privateVar is not accessible
//         }
//     };
//****-----------private inheritance------------- */
// class Derived : private Base {
//         public:
//             void display() {
//                 cout << "publicVar: " << publicVar << endl;  
//                 cout << "protectedVar: " << protectedVar << endl;  
//                 // cout << "privateVar: " << privateVar << endl;  // Error: privateVar is not accessible
//             }
//         };
int main() {
    Derived obj;
    // cout<<obj.publicVar;
    // cout<<obj.privateVar;
    // cout<<obj.protectedVar; 
    return 0;
}
