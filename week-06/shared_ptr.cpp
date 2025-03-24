#include<iostream>
using namespace std;
template<typename T>
class sharedptr{
      private:
      T* res;
      T *count;
      void increment(){
          if(count){
            *(count)+=1;
          }
      }
      void decrement(){
        if(count){
            *count--;
        }
        if(*count==0){
            if(res){
            delete res;
            delete count;
             res=nullptr;
             count=nullptr;
            }
        }
      }
      public:
      sharedptr(T* t=nullptr): res(t), count(new int(1)){}
      sharedptr(const sharedptr &other){ // copy constructor.
         res=other.res;
         count=other.count;
         increment();
      }
      sharedptr& operator=(const sharedptr& other){ // copy assignment
        if(this!=&other){
        decrement();    
        res=other.res;
        count=other.count;
        increment();}
             return *this;
      }
      sharedptr(sharedptr &&other){  //move constructor
         res=nullptr;
         count=nullptr;
         res=other.res;
         count=other.count;
      }
      sharedptr& operator=(sharedptr &&other){ // move assignment
        if(this!=*other){
        decrement();   
        res=nullptr;
        count=nullptr;
        res=other.res;
        count=other.count;
     }
     return *this;
     }
     int get_count(){
        return *count;
     }
     void reset(){
        if(res){
        res=nullptr;
        decrement();
        if(*count==0){
            delete res;
            delete count;
        }
     }
    }
};
int main(){
    sharedptr obj(new int(5));
    sharedptr obj1(obj);
    sharedptr obj2(obj);
    sharedptr obj3(new int(3));

    cout<<obj3.get_count();

}