#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>
#include<future>
using namespace std;
void fun(promise<int> &p){
   this_thread::sleep_for(chrono::seconds(2));
   p.set_value(42);
}
int main(){
    promise<int> p;
    future<int> f=p.get_future();
    thread t1(fun,ref(p));
     cout<<"waiting for the results...."<<endl;
    //  this_thread::sleep_for(chrono::seconds(5));
     cout<<"it will print imidiacte"<<endl;
     int res=f.get(); //wait for the promise value
     cout<<"res = "<<res<<endl;
     t1.join();
}
//Ques-->Why we use promise and future instead why dont we create a ref variable.