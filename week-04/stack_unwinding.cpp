#include <iostream>
#include <stdexcept>
using namespace std;
class class2 {
    public:
    class2(){
        cout<<"constructor is class 2"<<endl;
    }
    ~class2(){
        cout<<"destructor of class 2"<<endl;
    }
};


class class1 {
private:
    class2 class2Member;
    int *ptr;
public:
    class1(){
        cout<<"constructor of class1 "<<endl;
    //   throw runtime_error("Error");
    //it remove all the fully constructed obj from the stack.
    }
    void invokeFunction() {
        // try {
           cout<<"inside the class1 fun"<<endl;
           int *ptr= new int[100];
           /*if this throw occur then it remove the pointer from the stack but it will 
           cause memory leak thats why we use smart pointer.*/
           throw runtime_error("Error");
        // }
        // catch (exception& e) {
        // cout << "Caught an exception: " << e.what() << endl;
        // throw; //rethrow
        // //the type of rethrow will depends on the type of catch's argument.
        // }
    }
    ~class1(){
        cout<<"destructor of class 1"<<endl;
    }
};

int main() {
    try{
    class1 obj;

    obj.invokeFunction();
}
 catch (exception& e) {
        cout << "Caught an exception: for rethrow " << e.what() << endl;
        }
    return 0;
}
/*-----***usecase of rethrow***---------
. Exception Propagation to the Caller
If a function catches an exception but cannot handle it appropriately, it can rethrow the
 exception to allow the caller (or higher-level code) to handle it. This ensures that the
 exception isn't silently swallowed, and control is passed to the higher-level exception
  handling code.
*/