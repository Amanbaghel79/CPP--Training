#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//---***Syntax of Lambda Function***-----
/*
[ capture clause ] (parameters) -> return-type {
 function body
}
Capture clause:Specifies which variables from the surrounding scope are accessible inside the lambda.
Parameters: Similar to function parameters.

2.*****Capturing Variables

i)By reference: [&] captures all external variables by reference.

ii)By value: [=] captures all external variables by value.

iii)Mixed capture: [a, &b] captures a by value and b by reference.
*/
void print_if(vector<int> nums,bool (*predicate)(int)){  //lambda function as an pointer.
    for(int i=0;i<nums.size();i++){
        if(predicate(nums[i])){
            cout<<nums[i]<<" ";
        }
    }
}
// void fun(vector<int > num,function<bool(int)> predicate){ // lambda function using function
//     for(int i=0;i<num.size();i++){
//         if(predicate(num[i])) cout<<num[i];
//     }
// }
// template<typename T>
// void fun(vector<int > num,T predicate){ // lambda function using Template
//     for(int i=0;i<num.size();i++){
//         if(predicate(num[i])) cout<<num[i];
//     }
// }
// void fun(vector<int > num, auto predicate){ // this auto lambda will only support in c++ 20
//     for(int i=0;i<num.size();i++){
//         if(predicate(num[i])) cout<<num[i];
//     }
// }
auto make_lambda(){
    return [](){cout<<"return lambda function";};
}
int main(){
   vector<int> nums={3,2,4,1,7};
   int n=nums.size();

//    sort(nums.begin(),nums.end(),[](int a,int b)->bool{return a>b;});
//    for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";

//    auto it=[](vector<int> &num,int n){
//       for(int i=0;i<num.size();i++) num[i]+=1;
//    };
//    it(nums,n); // calling a lambda function.
// auto it=[&](){ 
//     for(int i=0;i<nums.size();i++) nums[i]+=1; 
//    };


//  auto it=[=](){ 
//   for(int i=0;i<nums.size();i++) nums[i]+=1; // error here because we are trying to change lvalue
//  };  
//    it();
//    
//   print_if(nums,[](int x){ return x%2==0;}); // print even number.
//   print_if(nums,[](int x){ return x%2==1;}); // print odd number.
//  
//    fun(nums,[](int x){return x>2;});
 auto it=make_lambda(); // taking lambda as a return type.
 it();
}


/*********NOTE*******
1.[](int x){ cout << x; }(100); last bracket () is used to invoke or call the lambda function immediately after it's 
defined.This pattern is known as an immediately invoked lambda expression (IIFE).
 
2. lambda function with empty [] is called stateless lambda function.

3. stateless lambda function cant access the surrounded variables.

4. Passing lambda function as a parameter to a function. 3-->ways

 i)->  Passing a Lambda via std::function
       syntax---->  fun(function<return-type(parameter_type1,parameter_type1)> lambda_name)

 ii)-> Passing a Lambda via Template   
       syntax-----> template<typename T>  
             void fun(T lambda_name)

 iii)-> Passing a Lambda via Function Pointer
       syntax----->  fun(return_type(*lambda_name)(parameter_type1,parameter_type1))

*/