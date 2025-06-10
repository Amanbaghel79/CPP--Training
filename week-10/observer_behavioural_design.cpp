#include<iostream>
#include<vector>
using namespace std;
// observer class-

class observer{
    public:
    virtual void update(int, string, int)=0;
};

// concrete observer class-
class display: public observer{
    public:
    void update(int t, string s,int speed){
        cout<<"now temp is"<<t<<"\n"<<"now status of weather is: "<<s<<"\n"<<"now speed is :"<<speed<<"\n";
    }
};

// subject class
class station{
    int temp;
    string status;
    int wind_speed;
    vector<observer*> vc;
    public:
    void add_observer(observer* ptr){
        vc.push_back(ptr);
    }
    void update(int temp,string s, int speed){
        for(auto it: vc){
            it->update(temp,status,speed);
        }
    }
};
int main(){
    display* display1 =new display();
    display* display2 =new display();
    station weather_station;
    weather_station.add_observer(display1);
    weather_station.add_observer(display2);
    weather_station.update(56,"winter",9000);
}