#include<iostream>
#include<memory>
using namespace std;
class myclass {
    public:
      myclass() {
            std::cout << "MyClass constructor called!" << std::endl;
        }
        ~myclass() {
            std::cout << "MyClass destructor called!" << std::endl;
        }
        void show() {
            std::cout << "Inside MyClass" << std::endl;
        }
    };
class person{
     shared_ptr<person> mfriend; //this shared pointer cause memory leak if cyclic dependency
    // weak_ptr<person> mfriend;
    string name;
    public:
    person(string s=""): name(s){cout<<"ctor"<<endl;}
    ~person(){
        cout<<"dtor"<<endl;
    }
    void set_freind(shared_ptr<person> other){
        mfriend=other;
    }
};
int main(){
     shared_ptr<myclass> sharedptr= make_shared<myclass>();
     weak_ptr<myclass> weakptr= sharedptr;
    //  weakptr->show()  // compilation error. it should convert into a shared pointer.

    //  shared_ptr<myclass> lockptr= weakptr.lock(); // lock returns a shared ptr of that object.. if the object is dead then it will return a nullptr.
    // if (lockptr) {
    //     std::cout << "Object is still alive!" << std::endl;
    // } else {
    //     std::cout << "The object has been destroyed (weak_ptr is expired)!" << std::endl;
    // }
    shared_ptr<person> a = make_shared<person>("aman");
    shared_ptr<person> b= make_shared<person>("kapil");
    a->set_freind(b);
    b->set_freind(a);
    cout<<a.use_count();
}
/*
NOTE--->
In the cyclic dependency when compiler wants to deallocate the object when they go out of scope but
to deallocate the reference count should be zero but due to cyclic dependency a points to b which prevent
the reference count of b to get zero , goes same for a .. then the statically allocated pointers goes
out of the scope or stack but the heap allocated memory will not and cause memory leak.

ques-->
when we have to lock a weak pointer to access the object then why dont we create a shared
pointer of that object and access it and decrement the count after using it.?
ans-->
If we directly create a std::shared_ptr from a std::weak_ptr without checking if the object is 
still valid, we would inadvertently increase the reference count of the object. This could lead 
to unexpected ownership of the object, which is not the intended behavior for a weak pointer. 
It creates a std::shared_ptr only if the object is still alive (i.e., the reference count hasn't 
dropped to zero).
*/

/*
Advantages of std::weak_ptr:
1.Prevents circular references: Helps in cases where mutual ownership could prevent objects from 
being properly deleted.
2.Non-owning reference: Allows you to reference an object without increasing its reference count,
 preventing unintended ownership.
3.Safe access: By locking a std::weak_ptr, you can safely check if an object is still alive and 
access it if it is.
4.Memory management in caches: In cache systems or observer patterns, where the cache doesn't need 
to own the object, std::weak_ptr is a perfect fit.*/