#include<iostream>
#include<vector>
using namespace std;
int add(int a ,int b){
    return a+b;
}
int sub(int a ,int b){
    return a-b;
}
int main(){
    int (*ptr)(int ,int); //function pointer. 
    int (*arry_ptr[3])(int,int); //static memory allocation.
    /*note-->hen you declare an array of function pointers, you need to specify either
     the size of the array or initialize it. You can't declare an array of function
      pointers without knowing how many function pointers it will hold*/
    arry_ptr[0]=add;
    arry_ptr[1]=sub;
    // ptr=&add;
    ptr=add;
    vector<int(*)(int,int)> ans; //dynamic allocation of array of function.
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;
    // cout<<&add<<endl;
    // cout<<*add<<endl;
    // int res=ptr(3,2);
    // cout<<res;
}