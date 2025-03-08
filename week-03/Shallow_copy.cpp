#include<iostream>
using namespace std;
 class Myclass{
    public:
    int *ptr;
    string *str;
    Myclass(int a,string s){
        *ptr=a;
        str=&s;
    }
    Myclass(Myclass &other){
         ptr=other.ptr; 
         str=other.str;
    }
};
int main(){
   Myclass obj(2,"aman"); 
   Myclass obj2(obj);
   cout<<*(obj2.str)<<endl;
   *obj2.str="baghel";
   //change in object obj will reflect in object obj2
   cout<<*(obj2.str);
}