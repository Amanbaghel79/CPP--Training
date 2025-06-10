// *****ALSO KNOWN AS BOUNDED BUFFER PROBLEM.******

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
using namespace std;
condition_variable cv;
mutex m;
queue<int> pq;
int maxsizebuffer=50;
void producer(int val){
    while(val){
        unique_lock<mutex> ul(m);
        cv.wait(ul,[]{return pq.size()<maxsizebuffer;});// wait untill condition become true.(When condition == true, the thread will not wait—it will proceed further immediately.) 
        pq.push(val);
        cout<<"producer :"<<val<<endl;
        val--;
        ul.unlock();
        cv.notify_all();
    }
}
void consumer(){
    while(true){
         unique_lock<mutex> ul(m);
         cv.wait(ul,[]{return !pq.empty();});
         int val=pq.front();
         cout<<"cosumer :"<<val<<endl;
         pq.pop();
         ul.unlock();
         cv.notify_all();
    }
}
int main(){
    thread t1(producer,100);
    thread t2(consumer);
    t1.join();
    t2.join();
}

//*********using semaphores in c++***************

// #include<iostream>
// #include<mutex>
// #include<thread>
// #include<queue>
// #include<semaphore>
// #include<chrono>
// const int MAX_SIZE=10;
// std::queue<int> pq;
// std::counting_semaphore<MAX_SIZE> empty(MAX_SIZE);
// std::counting_semaphore<MAX_SIZE> full(0);
// std::mutex m;
// void producer(int id){
//     int item=0;
//     while(true){
//         std::this_thread::sleep_for(std::chrono::milliseconds(200));
//         empty.acquire();
//         {
//         std::lock_guard<std::mutex> lc(m);
//         item++;
//         pq.push(item);
//         std::cout<<"producer id :"<<id<<" produced item :"<<item<<std::endl;
//         }
//         full.release();
//     }
// }
// void consumer(int id){
//     while(true){
//          std::this_thread::sleep_for(std::chrono::milliseconds(200));
//          full.acquire();
//          {
//              std::lock_guard<std::mutex> lc(m);
//              int iteam=pq.front();
//              pq.pop();
//              std::cout<<"consumer id :"<<id<<" consumed item"<<iteam<<std::endl;
//          }
//          empty.release();
//     }
// }
// int main(){
//     std::thread t1(producer,1);
//     std::thread t2(consumer,1);
//     t1.join();
//     t2.join();
// }