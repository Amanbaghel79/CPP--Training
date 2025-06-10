//“Race conditions don’t always show up, especially with small iterations or lucky thread timing.

#include <iostream>
#include<thread>
#include<mutex>
using namespace std;
int money=0;
mutex m;
void addmoney(){
    // m.lock();
    lock_guard<std::mutex> lock(m);  // unlocks automatically here when `lock` goes out of scope
    for(int i=0;i<100000;i++){
         ++money;
    }
    // m.unlock();
}
int main() {
    thread t1(addmoney);
    thread t2(addmoney);
    t1.join();
    t2.join();
      cout<<money<<endl;
}
//Ques-->why when using the i value like 10000 or less it give correct answer without any race condition

//Ques-->m.lock() / m.unlock()	V/S std::lock_guard<std::mutex>.
//ANS-->Feature	m.lock() / m.unlock()	std::lock_guard<std::mutex>

/*Manual unlock?	 Yes – you must call unlock()	|| No – automatic unlock (RAII)
Exception-safe?	 No – risk of deadlock if exception	|| Yes – unlocks even if exception
Cleaner syntax?	 Verbose, error-prone	|| Concise, safer
RAII-based?	 No	|| Yes (safe in all cases)
Recommended?	 Only when needed (e.g. special cases)	|| Yes – default go-to choice*/

//Ques->can we use copy assignment and copy constructor with the mutex.?


//function of mutex--> lock(),unlock(),try_lock()









