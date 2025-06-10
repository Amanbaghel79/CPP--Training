// Same thread can lock a mutex multiple times using the recursive mutex.
// If a thread t1 acquire a lock on mutex, then it can lock that mutex again and again without any problem.
//But if t1 acquire a lock on mutex 10 times then it have to unlock that mutex 10 times.
//Means recursive mutex keep track of how many times a mutex is locked and unlocked.
// it is not defined that how many time you can lock a recursive_mutex but when you reach the limit you will
//and try to lock then you will get the system error of for try_lock() you will get the false.
#include <iostream>
#include<mutex>
#include<thread>
using namespace std;
recursive_mutex m;
void worker(char a, int n){
    if(n<=0) return;
    cout<<a<<" "<<n<<endl;
    m.lock();
    worker(a,--n);
    m.unlock();
    cout<<"unlocked by "<<a<<endl;
}
int main() {
    thread t1(worker,'a',10);
    thread t2(worker,'b',10);
   t1.join();
    t2.join();
}