#include <iostream>
#include<mutex>
#include<thread>
using namespace std;
timed_mutex m;
void worker(int i){
    if(m.try_lock_for(chrono::seconds(2))){
        cout<<"thread "<<i<<" get the lock"<<endl;
        this_thread::sleep_for(chrono::seconds(2));
        m.unlock();
    }
    else{
       cout<<"thread "<<i<<" cant get the lock"<<endl;
    }
}
int main() {
    thread t1(worker,1);
    thread t2(worker,2);
    t1.join();
    t2.join();
}