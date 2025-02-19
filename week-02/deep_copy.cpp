#include<iostream>
using namespace std;
 class Myclass{
    public:
    int *ptr;
    Myclass(int a){
        *ptr=a;
    }
    Myclass(Myclass &other){
         ptr=new int (*(other.ptr)); 
    }
    void setdata(int a){
        *ptr=a;
    }
};
int main(){
   Myclass obj(2); 
   Myclass obj2=obj;
   obj.setdata(3);
   cout<<*(obj.ptr)<<endl;
   // change on object obj will not affect object obj2
   cout<<*(obj2.ptr);
}









//Aman Baghel