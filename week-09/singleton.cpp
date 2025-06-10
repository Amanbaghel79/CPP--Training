//A singleton ensures that only one instance of a class is created, and that it’s globally accessible.
// #include<iostream>
// using namespace std;
// class myclass{
//    static myclass* _instance;
//    int id;
//    string password;
//    myclass(int x=0, string s=""): id(x),password(s){}
//    public:
//    myclass(const myclass&)=delete;
//    myclass& operator=(const myclass&)=delete;
//    static myclass* getinstance(){
//        if(_instance==NULL){
//         _instance= new myclass();
//        }
//        return _instance;
//    }
//    void set_id(int x){
//       id=x;
//    }
//    void set_password(string s){
//       password=s;
//    }
//    int get_id(){
//       return id;
//    }
//    string get_password(){
//        return password;
//    }
//    void display(){
//        cout<<"id :"<<id<<endl;
//        cout<<"password :"<<password<<endl;
//    }
// };
//  myclass* myclass::_instance=NULL;
// int main(){
//     myclass *obj= myclass::getinstance();
//     obj->set_id(5);
//     obj->set_password("aman");
//     obj->display();
// }

// thread safe singleton class


#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

class logger{
    static int cnt;
    static logger* single_instance;
    static mutex m;
    logger(){
        cnt++;
        cout<<cnt<<" instance is created"<<endl;
    };
    public:
    static logger* get_instance(){
        if(single_instance==nullptr){
        m.lock(); // lock is expensive so we just cant use every time instead we can use double checking locking.
          if(single_instance==nullptr){
            single_instance=new logger();
          }
        m.unlock();
        }
        return single_instance;
    }
    void log(string s){
        cout<<s<<endl;
    }
};

 int logger::cnt=0;
 logger* logger::single_instance=nullptr;
  mutex logger:: m;
 
 void user1log(){
     logger *obj= logger::get_instance();
     obj->log("msg from user 1");
 }
 void user2log(){
     
    logger *obj1= logger::get_instance();
    obj1->log("msg from user 2");
 }
int main(){
    
    thread t1(user1log);
    thread t2(user2log);
   t1.join();
   t2.join();
}

//Ques->>>How do you make a Singleton thread-safe in C++11 and later?
//Ques-> why we need second check in double check locking?
//Let’s say you have two threads, T1 and T2:

// Both threads call getInstance() at the same time.

// Both do the first check (instance == nullptr) and find it true.

// Both enter the if block — now they both try to create the instance!

// Only one can lock the mutex at a time, yes — but when first unlock the lock , second will create a new object, defeating the purpose of Singleton.


//Ques-> Why we delete the copy constructor and copy assignment operator in singleton.
/*In a singleton, we delete the copy and assignment operators to prevent creating
additional instances through copying or assignment.*/
/*Ques->If you're copying a Singleton, and both instances use the same underlying 
resource (like a file or config), what's the big deal?*/