#include <iostream>
using namespace std;

class demo
{
    const int a;
public:
    // void constFunc() const
    // {
    //     cout << "demo:const" << endl;
    // }
    // void nonConstFunc()
    // {
    //     cout << "demo:non-const" << endl;
    // }
    // demo(){
    //     cout<<"you should always intialise the constructor";
    // }
    demo(int i): a(i){
        // a=i; error... you cant intialise a const member inside a constructor it should be done in intialisation list.
    }
    // void setValue(){
    //     a=2;
    // }
    void calc() {
    }
    void getValue() const{ // const member function ensure that not modification with the object.
        // calc(); error....as we are modifing the member variable in calc.
        cout << a << endl;
    }
};
int main()
{
    // demo d1;
    // d1.constFunc();// read only function 
    // d1.nonConstFunc();
    // const demo d2; //read only object
    // d2.constFunc();
    // d2.nonConstFunc(); //error...since it can change the state of class!


    // // d.setValue(10);
    // d.getValue();
    // return 0;
}
// ***NOTE***
//1.You cant change the value of a const variable.
//2.Const variable must be intialized while declaring.
//3. const member variables must be initialized in the constructor's initializer list, not inside the
// constructor body.This is because const variables must be initialized at the time of their creation and
// cannot be assigned values later.
//4.If you don't initialize a const member, the compiler will give an error because the const member 
//needs to be assigned a value at the time of object creation.

//---**const object**--
//1.A const object cannot call non-const member functions it can call only const object.