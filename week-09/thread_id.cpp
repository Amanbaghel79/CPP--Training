#include<iostream>
#include<thread>
#include<vector>
#include<chrono>
#include<cassert>
#include<algorithm>
using namespace std;
void worker(){
    cout<<"in function "<<this_thread::get_id()<<endl;
}
int main(){     
   vector<thread> vc;
//   unsigned long const hardware_threads=thread::hardware_concurrency();
   for(int i=0;i<10;i++){
      vc.emplace_back(thread(worker));
      this_thread::sleep_for(chrono::seconds(2));
      cout<<"in loop "<<dec<<vc[i].get_id()<<endl;
   }
    for (auto& t : vc) {
        if (t.joinable())
            t.join();  // wait for all threads to complete
    }
}