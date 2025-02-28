#include<iostream>
using namespace std;
class base{
    public:
    int a;
   void display(){
    cout<<"base class display function";
   }
    base(){
    cout<<"Base class non argument constructor is called"<<endl;}
    base(int i){
        cout<<"Base class argument constructor is called"<<endl;
        a=i;
    }
};
class derived : public base{
   public:
   int b;
   derived(int i){
    cout<<"derived class constructor is called"<<endl;
    b=i;
   }
   derived(int x,int y) : base(x){ // here we are calling parent class constructor in derived class.
    cout<<"derived class double argument"<<endl;
     b=y;
   }
   void display(){
    cout<<"Display of the derived class."<<endl;
    cout<<a<<" "<<b<<endl;
   }
};
int main(){
//   base obj(5);
  derived obj1(6,4);
//   obj1.a=1; //derived class object have the data memebers of base class.
  obj1.display();
  
  
}
//--------**** NOTE***-----
////Calling of constructor will take place from child to parent but execution is vise versa.
//When we create a object of derived class then it will first call the constructor of parent class.
//Always define the default constructor of parent class when thier is parameterised contructor for the object of child class.
//Destructor got executed from child to parent.