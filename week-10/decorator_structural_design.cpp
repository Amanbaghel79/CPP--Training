#include <iostream>
using namespace std;
// product class
class Icecream{
    public:
    virtual string getdescription()=0;
    virtual int cost()=0;
};
// concrete product class
class vanillaicecream: public Icecream{
    public:
    string getdescription(){
        return "you got your vanilla icecream";
    }
    int cost(){
        // cout<<"the cost for the vanilla icecream is"<<100<<"\n";
        return 100;
    }
};
//decorator class---
class icreamdecorator: public Icecream {
    protected:
    Icecream * icecream;
    public:
    icreamdecorator(Icecream * obj) : icecream(obj){}
     string getdescription(){
         return icecream->getdescription();
     }
     int cost(){
        return icecream->cost();
    }
};
class add_chocolate_decorator: public icreamdecorator{
    public:
    add_chocolate_decorator(Icecream * obj): icreamdecorator(obj){}
    string getdescription(){
        return icecream->getdescription() + "you added chocolate topping";
    }
    int cost(){
        return icecream->cost()+100;
    }
};
class add_buttersoch_decorator: public icreamdecorator{
    public:
    add_buttersoch_decorator(Icecream * obj): icreamdecorator(obj){}
    string getdescription(){
        return icecream->getdescription() + "you added buttersoch topping";
    }
    int cost(){
        return icecream->cost()+100;
    }
};
int main()
{
     vanillaicecream *vanilla_ice= new vanillaicecream();
     cout<<vanilla_ice->getdescription()<<endl;
     cout<<vanilla_ice->cost()<<endl;
     
     add_chocolate_decorator * choco_vanilla=new add_chocolate_decorator(vanilla_ice);
      cout<<choco_vanilla->getdescription()<<endl;
     cout<<choco_vanilla->cost()<<endl;
    return 0;
}