#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int main() {
    vector<int> vc = {1, 2, 3, 4, 5, 6};

    for (auto it = vc.begin(); it != vc.end(); ){
        cout << *it << endl;
        if (*it == 3){
           vc.erase(it);  // this will get erase ... internally left shift all the element of the vc.
          // it=vc.erase(it); this is safe execute.
           vc.push_back(7);
            vc.push_back(7);   // errro as this will do the reallocation of the vector to the new memory location.
           }
           // erase returns the next valid iterator
        else
            ++it;
    }
    //-------------------unordered_map-----------------
    unordered_map<int,int> mp={{1,100},{2,200}};
    auto it=mp.begin();
    cout<<it->first<<endl;
    mp.insert({3,400}); // this may cause the rehashing of the map which can cause the iterator invalid.
    mp.erase(it); //will give undefined behaviour
    it=mp.erase(it); // safe way
    cout<<it->first<<endl;
    return 0;
}
// erase used to give the next valid iterator pointing to the next value.