//Deferred locking is a technique used in C++ multithreading where a lock object is
// created but not immediately acquired. Instead, the lock acquisition is postponed to 
//a later time when explicitly requested. This approach offers more flexibility in 
//controlling when and how a mutex is locked.

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <optional>

std::mutex mtx;
std::timed_mutex timed_mtx;
std::condition_variable cv;
bool ready = false;

// Function that returns a unique_lock (ownership transfer)
std::unique_lock<std::mutex> getLockedMutex() {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Mutex locked in getLockedMutex()\n";
    return lock;  // ownership moved to caller
}

void deferredLockExample() {
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
    std::cout << "Lock is deferred\n";
    
    // Do some work before locking
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    
    lock.lock();  // manually acquire lock
    std::cout << "Lock manually acquired in deferredLockExample\n";
    lock.unlock();  // manually release
    std::cout << "Lock manually released in deferredLockExample\n";
}

void tryLockExample() {
    std::unique_lock<std::timed_mutex> lock(timed_mtx, std::defer_lock);

    if (lock.try_lock_for(std::chrono::milliseconds(100))) {
        std::cout << "Lock acquired with try_lock_for\n";
        // do work
    } else {
        std::cout << "Failed to acquire lock in tryLockExample\n";
    }
}

void conditionVariableExample() {
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "Waiting for condition...\n";

    cv.wait(lock, []{ return ready; });

    std::cout << "Condition met. Proceeding...\n";
}

void notifyThread() {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
        std::cout << "Condition set to true.\n";
    }
    cv.notify_one();
}

void ownershipTransferExample() {
    std::unique_lock<std::mutex> lock = getLockedMutex();  // lock moved from function
    if (lock.owns_lock()) {
        std::cout << "Ownership successfully transferred\n";
    }
}

int main() {
    std::thread t1(deferredLockExample);
    std::thread t2(tryLockExample);
    std::thread t3(conditionVariableExample);
    std::thread t4(notifyThread);
    std::thread t5(ownershipTransferExample);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}


// ✅ Advantages of std::unique_lock (with defer_lock) over manual locking
// Feature	Manual Locking (mutex.lock())	unique_lock with defer_lock
// RAII (automatic unlock)	❌ No — you must manually call unlock()	✅ Yes — unlocks automatically when it goes out of scope
// Exception Safety	❌ Risk of forgetting unlock() if an exception occurs	✅ Safe — ensures unlock() is called
// Works with std::lock()	❌ Not directly usable with std::lock()	✅ Yes — needed when locking multiple mutexes safely
// Condition Variables Support	❌ Not compatible — needs unique_lock	✅ Required by std::condition_variable::wait()
// Lock ownership transfer	❌ Not possible	✅ You can move ownership of the lock
// Try-lock and timed-lock support	❌ Must be written manually	✅ Supported via constructor options or methods