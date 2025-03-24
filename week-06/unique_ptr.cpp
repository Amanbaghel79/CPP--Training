#include<iostream>
using namespace std;
class uniqueptr{
   public:
   int *ptr;
   uniqueptr(int val){
    cout<<"ctor"<<endl;
      ptr=new int(val);
   }
   uniqueptr(const uniqueptr &other)=delete;
   uniqueptr& operator=(const uniqueptr &other) =delete;
   uniqueptr& operator=(uniqueptr &&other){
      if(this!= &other){
        if(ptr!=nullptr) delete ptr;
        ptr=other.ptr;
        other.ptr=nullptr;
     }
     return *this;
   }
   uniqueptr(uniqueptr &&other){
     if(this!= &other){
        if(ptr!=nullptr) delete ptr;
        ptr=other.ptr;
        other.ptr=nullptr;
     }
   }
   int &operator*(){
      return *ptr;
   }
   int* operator->(){
    return ptr;
   }
   ~uniqueptr(){
    cout<<"dtor"<<endl;
    delete ptr;
   }
   void reset(int val){
    if(ptr) delete ptr;
    ptr=new int(val);
   }
   int *get(){
    return ptr;
   }
};
int main(){
    uniqueptr obj(5);
    uniqueptr obj2(7);
    //uniqueptr obj2(obj); // compilation error we cant make other pointer to point same memory location.
    // obj=obj2; // same of above.
    obj2= move(obj);
    if(obj.ptr==nullptr) cout<<"moved object got null"<<endl;
    cout<<*obj2.ptr<<endl;
}