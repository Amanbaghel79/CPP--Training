#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
 mutex m;
void tryLockExample(int id) {
    if (m.try_lock()) {
        cout << "Thread " << id << " acquired the lock.\n";
        this_thread::sleep_for(chrono::milliseconds(100));
        m.unlock();
    } else {
       cout << "Thread " << id << " could not acquire the lock.\n";
    }
}

int main() {
    thread t1(tryLockExample, 1);
    thread t2(tryLockExample, 2);

    t1.join();
    t2.join();
}


/*1.we can lock multiple mutex at same time using the try_lock();
2.tries to lock all the lockable objects passed one by one in given order.
3. SYNTAX: try_lock(m1,m2,m3,m4,m5,m6).
4. on sucess return -1 , else return 0 based mutex index number which it cant lock.
5. if it fail to lock any mutex then it will release all mutex it locked before.
*/


/*Benefits of try_lock():
 1.Non-blocking: Doesn’t stall your thread.
 2.Useful for time-sensitive or UI code (e.g., games, UIs, real-time systems.
 3.Can help avoid deadlocks when trying to acquire multiple locks.
 4.You don't want your thread to get stuck waiting on a lock.
 */