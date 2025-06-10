//A light weight wrapper class for owning the mutex on scope basis.
//it acquire the mutex lock the moment you create the object of lock_guard.
//it automaticalyy removes the lock when goes out of scope.
//you cant explicitly unlock the lock_guard.
// you cant copy the lock_guard.
#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
mutex m;
void fun(char ch,int n){
    lock_guard<mutex> lc(m);
    for(int i=0;i<n;i++) cout<<ch<<i<<endl;
    //dont need to unlock.
}
int main(){
     thread t1(fun,'t1',5);
     thread t2(fun,'t2',5);
     t1.join();
     t2.join();
}
