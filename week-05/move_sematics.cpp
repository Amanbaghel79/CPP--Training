/*Move semantics allows the efficient transfer of resources (like dynamically allocated 
memory,file handles, or network connections) from one object to another, without the need
to perform expensive deep copies.*/

#include<iostream>
#include<utility> //for move()
using namespace std;
class myclass{
    public:
    int *i=nullptr;
    myclass(){
    }
    myclass(myclass &other){ //deep copy constructor.
        if(other.i!=nullptr){
            i=new int (*other.i);
        }
    }
    myclass(myclass &&other){
        cout<<"move constructor"<<endl;
        delete i;
        i=other.i;
        other.i=nullptr;
    }
    myclass &operator=(myclass &&other){ 
        cout<<"move assignment "<<endl;
        if(this!=&other){
            delete i;
            i=other.i;
            other.i=nullptr;
        }
        return *this;
    }
    myclass &operator=(myclass &other){   // deep copy assignment operator.
        if(other.i!=nullptr){
            i=new int (*other.i);
        }
        return *this;
    }
    ~myclass(){
        if(i!=nullptr){
            delete i;
            i=nullptr;
        }
    }
};
int main(){
    myclass obj1;
    obj1.i= new int(5);
    myclass obj2(obj1);// if we copy using default copy constructor then it will cause error becoz due to shallow copy they point to same memory location and cause problem of double deletion.
    myclass obj2=move(obj1); //The move keyword is used to cast an object into an rvalue reference.
}
