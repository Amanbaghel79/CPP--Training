#include <iostream>
using namespace std;
class C {
private:
     int privateVarC;
    public:
    C(int a) {
        privateVarC=a;
    }
    friend class B;
    friend class A;
};
class B {
private:
   int privateVarB;
public:    
    B(int i) {
        privateVarB=i;
    }
     void setdata_b(C &obj){
         cout<<"accessing the data of class c using class B "<<obj.privateVarC;
     }
    friend class A;
};
class A {
private:
    int privateVarA;
    public:   
    A() {
    }
    void setdata_a(C &obj){
    cout<<"accessing C data using class A "<<obj.privateVarC;
    }
};
int main() {
    C obj(9);
    B objb(7);
    A obja;
    obja.setdata_a(obj);
}

// Derived class

