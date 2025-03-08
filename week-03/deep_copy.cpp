#include<iostream>
using namespace std;
 class Myclass{
    public:
    int *ptr;
    string *str;
    Myclass():ptr(nullptr),str(nullptr){}
    Myclass(int a,string s){
        ptr=new int(a);
        str=new string(s);
    }
    //Deep copy assignment operator.
    Myclass& operator=( Myclass& other) { //We are returning the reference.
        cout<<"copy assignment operator is called"<<endl;
        if (this == &other){
            return *this;  // Prevent self-assignment
        }
        // First delete the existing data if any
        delete ptr;
        delete str;
        
        // Allocate new memory and copy the string
        ptr=new int(*other.ptr);
        str = new string(*other.str);
        return *this;
    }
    //Deep copy constructor.
    Myclass(const Myclass &other){
        cout<<"copy constructor called"<<endl;
         ptr=new int (*(other.ptr)); 
         str=new string(*other.str);
    }
    ~Myclass() {
        delete ptr;
        delete str;
    }
    void setdata(int a){
        *ptr=a;
    }
};
int main(){
//    Myclass obj(2,"aman"); 
//    Myclass obj2(obj); 
//    cout<<*(obj2.str)<<endl;
//    *obj.str="baghel";
//    // change on object obj will not affect object obj2
//    cout<<*(obj2.str)<<endl;

//    Myclass obj3;
//    obj3=obj; // this will call copy assignment operator.
Myclass obj1(1,"aman");
Myclass obj2(2,"kapil");
Myclass obj3(3,"ankit");
    obj1=obj2=obj3;
   cout<<"obj1 "<<*(obj1.str)<<endl;
   cout<<"obj2 "<<*(obj2.str)<<endl;
   cout<<"obj3  "<<*(obj3.str)<<endl;
}
//*** NOTE**** */
//1.Class_name obj_name(obj2_name) and class_name obj_name=obj2_name----this both syntax call copy constructor.

//2.class_name obj;
// class_name obj2;
// obj2=obj //------>this will call copy assignment operator.







//Aman Baghel