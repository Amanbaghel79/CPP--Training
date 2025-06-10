//QUES-> facade vs proxy design pattern
// QUES-> facade vs adapter design pattern

// it is used to hide the system complexity from the client we use facade design pattern.
#include <iostream>
using namespace std;
class amplifier{
    public:
    void on(){
         cout<<"amplifiers gets turn on"<<endl;
    }
    void off(){
        cout<<"amplifiers gets turn off"<<endl;
    }
};
class dvdplayer{x
    private:
    string movie;
    public:
    // dvdplayer(string s): movie(s){}
    void play(string s){
        cout<<"starting the movie"<<s<<endl;
    }
    void on(){
        cout<<"starting the dvdplayer"<<endl;
    }
    void off(){
        cout<<"turning off the dvdplayer"<<movie<<endl;
    }
    void stop(string s){
        cout<<"stopping the movie "<<s<<endl;
    }
};
class screen{
    public:
    void up(){
        cout<<"screen raising"<<endl;
    }
    void down(){
        cout<<"screen lowering"<<endl;
    }
};
//
class theater{
    public:
    amplifier ampli_;
    dvdplayer dvdp_;
    screen screen_;
    void start_movie(string s){
        screen_.down();
        ampli_.on();
        dvdp_.on();
        dvdp_.play(s);
    }
    void end_movie(string s){
        cout<<"-----------------"<<endl;
         ampli_.off();
        dvdp_.off();
        dvdp_.stop(s);
        screen_.up();
    }
};
int main()
{
   string s="game of thrones";
   theater obj;
   obj.start_movie(s);
 obj.end_movie(s);
    return 0;
}