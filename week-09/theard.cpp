//A thread is the smallest unit of execution within a process.

// ✅ What is std::jthread?
// std::jthread is a joining thread in c++20— it behaves like std::thread, but automatically joins in its destructor.
// 🔑 Key features:
// Automatic joining — no need to manually call .join()
// Supports cooperative cancellation via stop_token
// Non-copyable but movable, just like std::thread

#include <iostream>
#include<thread>
using namespace std;
void fun(){
    for(int i=0;i<1000;i++){
        cout<<i<<" ";
    }
}
auto it=[](int x,int y){ // Lambda function
    int n=x+y;
    cout<<n;
};
class myclass{
    public:
    void operator()(int x){
        while(x--) cout<<x<<endl;
    }
};
class base{ 
    public:
    void prin(int x){
        cout<<x<<" "<<" called using non static member";
    }
    static void foo(){
        cout<<" called a static member function"<<endl;
    }
};
int main() {
//   thread t1(fun);  //using function pointer.
 //thread t1(it,3,4);   //using  Lambda function.
 //thread t1(myclass(),5); //using functor. 
//  base obj;
//  thread t1(&base::prin,&obj,3); // using non static member function.
 thread t1(&base::foo);      //using static member function.
  t1.join();
}

// ques-> why concurrrency is important ?
// 2 reasons-> i.increase performance 
//             ii.sepration of concerns.

//  QUES->> Problems with Sharing Data between Threads.


///----------------------------------
//this below code will produce only one code again and again becoz we are producing a code and then waiting for it.

// #include <iostream>
// #include<thread>
// #include<vector>
// using namespace std;
// void fun(int x){
//     cout<<"hi from the thread "<<x<<endl;
//     cout<<"this thread id "<<this_thread::get_id()<<endl;
// }
// int main()
// {
//     vector<thread> vc;
//     for(int i=0;i<10;i++){
//         vc.push_back(thread(fun,i));
//           vc[i].join();
//     }
// }