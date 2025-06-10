/*A std::condition_variable is a synchronization primitive that allows threads to wait 
(sleep) until some condition is met, and then get notified to resume.
It helps avoid busy-waiting, making your program more efficient.
ANALOGY-->
You're waiting for a package at home.
Instead of checking the door every second, you take a nap and ask your roommate to 
wake you up when it arrives — that’s a condition variable.
//conditional variable is use for the sychronize two or more thread.
*/

#include <iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
int balance=0;
condition_variable ax;
mutex m;
void addmoney(int money){
   lock_guard<mutex> lg(m);
   balance+=money;
   cout<<"money is added to the account "<<money<<endl;
   ax.notify_all();
}
void withdrawmoney(int money){
    unique_lock<mutex> ul(m);
    ax.wait(ul,[]{return (balance!=0) ? true : false;});
    if(balance>=money){
        balance-=money;
        cout<<"amount deducted "<<money<<endl;
    }
    else{
        cout<<"ERROR current balance is less than "<<money<<endl;
    }
    cout<<"current balance is "<<balance<<endl;
}
int main() {
    thread t2(withdrawmoney,200);
    thread t3(withdrawmoney,200);
    thread t4(withdrawmoney,100);
    thread t1(addmoney,500);
    t1.join();
    t2.join(); 
    t3.join();
    t4.join();
}
