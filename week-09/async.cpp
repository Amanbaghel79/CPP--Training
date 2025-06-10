#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>
#include<future>
using namespace std;
mutex m;
int ans;
int computeHeavy() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 42;
}
int get_fail(int x){
    if(x<=0) throw runtime_error("Negative input not allowed!");
    return x;
}
int main(){
    // auto fut = async(launch::async, computeHeavy);  
    // future<int> fut= async(launch::deferred,computeHeavy);
    // future<int> result = async(launch::async | launch::deferred, computeHeavy);
    //  cout << "Result: " << fut.get() << "\n"; // Waits for result
    auto fut = async(launch::async, get_fail,0);  
    try{
      int res= fut.get(); // future is now invalid means after result extraction future gets invalidate.
      cout<<"res "<<res<<endl;
    }
    catch(const exception& ex){
       cout<<"exception "<<ex.what()<<endl;
    }

}

//--------------------------------------------------------------


//*******implementation of function without async ,with thread. ******

// void func_for_thread(int x){
//     lock_guard<mutex> lc(m);
//     this_thread::sleep_for(chrono::seconds(2));
//     ans=x;
// }

// int main(){
//     thread t1(func_for_thread);
//     t1.join();
//     cout<<ans;
// }

//------------------------------------------------------------------


// 1. Simplified Asynchronous Programming
// Without std::async, if you want to execute a function asynchronously, you’d have to:
// Manually create a std::thread.
// Manage the thread lifecycle (e.g., call join() or detach()).
// Handle result passing via shared variables or other synchronization primitives (like mutexes).

// 🚀 1. std::launch::async
// ✅ What it does:
// Forces the task to run immediately in a new thread.

// The function is executed concurrently (in parallel) with the caller.

// 🕓 2. std::launch::deferred
// ✅ What it does:
// The task is not executed immediately.

// Instead, it's deferred and runs only when you call .get() or .wait().

//When you may or may not need the result later, and you want to avoid the overhead of spawning a thread.

// 🌀 3. Default Launch Policy (std::launch::async | std::launch::deferred)
// ✅ What it does:
// Lets the implementation (the C++ runtime) decide whether to run the task:

// Immediately in a new thread, or(if cpu is capable of)

// Deferred, executed later when .get() is called.


//QUES-->thread vs async
// Key Features:
// Manages the thread for you.

// Returns a future, so you can easily get results.

// Automatically joins the thread at the end (no leak) unlike thread.

// You don’t need to join() or detach() manually unlike thread.

// Can execute immediately (async) or lazily (deferred) unlike thread.






//Ques->How does the function's return value get captured into the future?
//ANS-> 1. std::async creates a shared state
//         Allocates a shared state: a structure that stores:
//         The return value (or exception).
//         The status of the task (ready or not).
//         Synchronization primitives (mutex, condition variable).
//       2. std::future is a handle to the shared state
//         The future you get from std::async is just a read-only handle to that shared state.
//         It lets you .get() or .wait() for the result once the task completes.
//       3. The function is wrapped and executed
//          std::async wraps your function inside a packaged task-like wrapper.
//          When the function is executed (either in a new thread or deferred), the return value is stored automatically in the shared state.

//https://stackoverflow.com/questions/868568/what-do-the-terms-cpu-bound-and-i-o-bound-mean.

// NOTE****✅ Exceptions from function() do not propagate through std::async directly.
// Instead:
// The exception is caught internally by std::async.
// It is stored inside the future’s shared state.
// The exception is re-thrown only when you call .get() on the future.