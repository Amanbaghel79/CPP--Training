#include<iostream>
using namespace std;
// class myclass_2{
//     public:
//     string name ;
//     int id;
//    myclass_2(){
//     name="default";
//     id=0;
//    }
//    myclass_2(string s,int val){
//     name=s;
//     id=val;
//    }
// };

class myclass3{
   public:
   int a;
   int b;
  explicit myclass3(int i,int j) : a(i),b(j){
     cout<<a<<endl;
     cout<<b<<endl;
   }
};
// class myclass{
//     public:
//     int *id; // Pointer member
//     myclass(){
//         int a=5;
//         cout<<"constructor with the no para"<<endl;
//         id=new int(a);
//     }
//     //Constructor overloading
//     myclass(int val){
//         cout<<"constructor with para"<<endl;
//     id=new int(val); // dynamic memory alocation.
//     }
//     ~myclass(){
//         if(id) delete id;
//         cout<<"Destructor is called";
//     }

// };
int main(){
    // myclass obj;
    // //Basic Syntax to Create an Array of Objects: ClassName arrayName[arraySize];
    // // Array of object will call the constructor equal to its size;
    // //myclass obj2[3] --> this will call constructor with 3 times.
    // myclass obj3[5]; //object array with default value;
    // myclass obj2[3]={11,11,10}; // we can intialise the object with the different value.

    // myclass_2 obj1[3]={{"aman",1},{"akash",2},{"aditya",3}};
    // cout<<obj1[2].name<<endl;
    // cout<<obj1[2].id<<endl;

// ----Constructor Intilization list----

//----Syntax------
//   constructor( argument-list) : intilization-section{
//     assignment + other code;
//   }
//    myclass3 obj_4(4,5);
    // a=3.14,b=4.2;
   myclass3 aobj(3.14,4.5);
//    cout<<aobj.a<<endl;
//    cout<<aobj.b<<endl;
}