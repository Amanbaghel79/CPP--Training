#include<iostream>
using namespace std;
//product class
class house{
    public:
    string wall;
    string door;
    string roof;
    void show(){
        cout<<"wall "<<wall<<endl;
        cout<<"door "<<door<<endl;
        cout<<"roof "<<roof<<endl;
    }
};
//builder class
class housebuilder{
    public:
    virtual void construct_wall()=0;
    virtual void construct_door()=0;
    virtual void construct_roof()=0;
    virtual house* get_house()=0;
};
//concerete builder class-1
class wood_house: public housebuilder{
    house* ptr;
    public:
     wood_house(){
       ptr = new house();
    }
    void construct_wall(){
        ptr->wall= "wood_wall";
     }
     void construct_door(){
        ptr->door="wood_door";
     }
     void construct_roof(){
        ptr->roof= "wood_roof";
     }
     house* get_house(){
         return ptr;
     }
};
//concerete builder class-2
class glass_house: public housebuilder{
    house* ptr;
    public:
    glass_house(){
       ptr = new house();
    }
    void construct_wall(){
         ptr->wall="ice_wall";
     }
     void construct_door(){
         ptr->door="ice_door";
     }
     void construct_roof(){
         ptr->roof="ice_roof";
     }
     house* get_house(){
         return ptr;
     }
};
//director class
class director{
    housebuilder* builder;
    public:
    director(housebuilder* b): builder(b){}
    house* contruct_house(){
       builder->construct_wall();
       builder->construct_door();
       builder->construct_roof();
       return builder->get_house();
    }
};
int main(){
    glass_house *ghouse= new glass_house();
    house* hr; 
    director obj(ghouse);
    hr=obj.contruct_house();
    hr->show();
}