#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
//1.custom behaviours
class compare{
  public:
  bool operator()(int a,int b){
     return a>b;
  }
};
//2.state management.
class Counter {
    private:
        int count;
    public:
        Counter() : count(0) {}
        void operator()() {
            ++count;
            std::cout << "Counter value: " << count << std::endl;
        }
};
int main(){
//    vector<int> ans={8,7,2,4,1,5};
//    sort(ans.begin(),ans.end(),compare());
//    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
   Counter obj;
   obj();
   obj(); 
}
//-----*****Usecases of Functor*****------
/*
1.Functors used to pass custom behavior to algorithms, such as sorting, searching, that 
require a comparison function or action.

2.Functors can hold state across multiple calls. This is used when you need to preserve 
some information between calls, something that function pointers cannot do.

3.
*/ 