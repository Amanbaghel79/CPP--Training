#include<iostream>
using namespace std;
class myclass{
    public:
    int a;
    explicit myclass(int i){
    a=i;
    }
};
int  main(){
  myclass obj(8.2); //this will not cause error in explicit keyword also becoz in direct intilization c++ narrowing conversion.
//   myclass obj2=8; // this will create error becoz here we are assigning 'myclass' to 'int' type when explicit keyword is used.
  //  myclass obj3 = 10;  // NO ERROR becoz Implicit conversion from int to MyClass when we dont use explicit keyword.
}