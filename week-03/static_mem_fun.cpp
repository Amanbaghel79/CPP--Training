#include<iostream>
using namespace std;
class myclass{
    private:
    static int count;
    public:
   static int b;
   static string a;
   myclass(){
      cout<<"constructor is called"<<endl;
      count++; //increasing the count by 1 when an object get created.
   }
   static int getcount(){
    return count;
    // cout<<a<<b; //cant access the non static members.
   }
};
//Initilization of static member
int myclass::count=0;
// int myclass:: b=5;
// string myclass:: a="aman";
int main(){
    //  cout<<myclass:: b<<endl; //you can access static members before the creation of any object.
    //  myclass obj;
    //  cout<<obj.b<<endl; //After the creation of an object.
    //  myclass:: b=1; // wrong pratice not suggested.
    //  cout<<obj.b<<endl;
    //  cout<<obj.a<<endl;
    // myclass obj[11];
    myclass obj1;
    myclass obj2;
    // int cnt=obj.getcount(); // Error cant be called like this
    cout<<myclass::getcount();
}
//-----**Static member**---
// 1.Shared by all the object of the class.
// 2.By default value is zero.
// 3.we can intialized it outside the class using :: operator.
// 4.No matter how many objects are created of a class there is only one copy of Static member will get created.
//5. one advantage is we can calculate the no. of object of class get created.


//-----**Static member function**-----
//1.It doesnt have the access of this pointer.
//2.it can access both static variables and static member functions of the class,but cannot access any instance-specific variables or methods.
//3.it can be called using the class name without the creation an object of the class.
