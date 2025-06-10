#include<iostream>
#include<chrono>
#include<thread>
using namespace std;
void fun(int x){
    while(x--) cout<<x<<" "<<endl;
    this_thread::sleep_for(chrono::seconds(10));
}
int main(){
    thread t1(fun,100);
    cout<<"before"<<endl;
    // t1.join();
    // if(t1.joinable()){ //check that we can join the thread again.
    //     t1.join();
    // }
    t1.detach();
    cout<<"after the thread ends";
}
//detach is used to deatch the newly created thread from the parent thread.
//double detach is will also lead to program termination.
//always check before detaching the thread that it is joinable so to prevent the double detaching of the thread.
//if you detach a thread from the main thread then the output can vary, as thier is many cases like the main thread get completed before the detached thread. 