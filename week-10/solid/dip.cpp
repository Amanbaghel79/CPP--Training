// Based on this idea, Robert C. Martin’s definition of the Dependency Inversion Principle consists of two parts:

// High-level modules should not depend on low-level modules. Both should depend on abstractions.
// Abstractions should not depend on details. Details should depend on abstractions.
// Definition:
// High-level modules should not depend on low-level modules. Both should depend on abstractions.

//  Focuses On:
// Decoupling high-level and low-level logic

// Using interfaces or abstract classes instead of concrete ones



//+++ Voilation of the dependency inversion principle.

// #include <iostream>
// using namespace std;
// class bulb{
//     string name;
//     public:
//     bulb(string s=""): name(s){};
//     void turn_on(){
//         cout<<name<<" bulb gets turn on"<<endl;
//     }
// };
// class button: public bulb{
//     bulb* bulb_obj;
//     public:
//     button(bulb* temp): bulb_obj(temp){}
//     void on(){
//         bulb_obj->turn_on();
//     }
// };
// int main()
// {
//   bulb b("a");
//    button obj(&b);
//    obj.on();

// }
// In this above code button class is tightly coupled with the bulb like if you want to add a
// new class like ledbulb then you have to make changes in the both classes which voilets 
//the principle of the di.

//++ correct code-----------------------------

#include <iostream>
using namespace std;

class idevice{   // -----abstract class---
    public:
    virtual void turn_on()=0;
    virtual ~idevice()=default;
};
class bulb_led: public idevice{
    string name;
    public:
    bulb_led(string s=""): name(s){};
    void turn_on() override{
        cout<<name<<" ledbulb gets turn on"<<endl;
    }
};
class bulb: public idevice{
    string name;
    public:
    bulb(string s=""): name(s){};
    void turn_on() override{
        cout<<name<<" bulb gets turn on"<<endl;
    }
};
class button{
    idevice* i_obj;
    public:
    button(idevice* temp): i_obj(temp){}
    void on(){
        i_obj->turn_on();
    }
};
int main()
{
   bulb_led led_obj("abc");
   button obj(&led_obj);
   obj.on();
}
// this is the proper implementation of the dependency inversion where a high level module is 
// not directly dependent on the low level module