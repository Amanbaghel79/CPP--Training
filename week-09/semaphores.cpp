// #include <iostream>
// #include <thread>
// #include <semaphore>
// #include <chrono>

// std::counting_semaphore<4> sem(4); // Allows up to 3 threads concurrently

// void access_resource(int id) {
//     sem.acquire(); // wait()
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     std::cout << "Thread " << id << " is accessing the resource\n";
//     std::cout << "Thread " << id << " is releasing the resource\n";
//     sem.release(); // signal()
// }

// int main() {
//     std::thread threads[6];
//     for (int i = 0; i < 6; ++i)
//         threads[i] = std::thread(access_resource, i);

//     for (auto& t : threads)
//         t.join();

//     return 0;
// }

// 🆚 Mutex vs Semaphore

// Feature	                 Mutex                             Semaphore
// Ownership->	Only the thread that locks can unlock	      No concept of ownership
// Resource Access->	One thread at a time	              Can allow multiple threads
// Blocking behavior->	Blocks if already locked	          Blocks if count is zero
// Use case->	        Exclusive access to a resource	      Limited concurrent access (e.g., N slots)
// Type->	            Binary only	                          Binary or Counting
// C++ Support	        std::mutex (C++11+)	                  std::counting_semaphore (C++20+)