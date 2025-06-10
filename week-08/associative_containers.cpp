//-------------------------set--------------------------------------------
#include <iostream>
#include<string>
#include<set>
using namespace std;
class person{
    public:
    int age;
    string name;
    bool operator < (const person&rhs) const {
       return age<rhs.age;
    }
};
int main(){
    set<person> st={{22,"abc"},{23,"vmk"},{24,"ekfm"},{25,"fkek"}};
    for(auto &e: st){
        cout<<e.age<<" "<<e.name<<endl;
    }
}

//SYNTAX:: std::set<T> name;
/*
1.associative container that contains a sorted set of unique element.
2.implemented internally using the red-black tree.
3.insertion,remove, search have logirathmic complexity.
4.if you want to store user defined function in set then you have to provide the compare function
 so that set can store them in sorted order.

*/
///-----------multiset-------------------
#include <iostream>
#include <set>

int main() {
    std::multiset<int> ms;

    // 1. insert() – allows duplicate elements
    ms.insert(10);
    ms.insert(30);
    ms.insert(10);
    // ms.insert(30);

    // std::cout << "Multiset after insertion:\n";
    // for (int x : ms) std::cout << x << " ";  // 10 10 20 30
    // std::cout << "\n";

    // // 2. count(key) – returns number of occurrences
    // std::cout << "Count of 10: " << ms.count(10) << "\n";  // 2

    // // 3. find(key) – returns iterator to the first occurrence
    // auto it = ms.find(10);
    // if (it != ms.end())
    //     std::cout << "Found: " << *it << "\n";

    // // 4. erase(key) – removes all instances of key
    // ms.erase(20);
    // std::cout << "After erasing 20:\n";
    // for (int x : ms) std::cout << x << " ";  // 10 10 30
    // std::cout << "\n";

    // // 5. erase(iterator) – removes one element at a time
    // ms.erase(ms.find(10));  // removes just one 10
    // std::cout << "After erasing one 10:\n";
    // for (int x : ms) std::cout << x << " ";  // 10 30
    // std::cout << "\n";

    // 6. lower_bound(key) and upper_bound(key)
    // ms.insert(40);
    // ms.insert(50);
    // auto lb = ms.lower_bound(30);  // >= 30
    // auto ub = ms.upper_bound(30);  // > 30
    // std::cout << "Lower bound of 30: " << *lb << "\n";  // 30
    // std::cout << "Upper bound of 30: " << *ub << "\n";  // 40 // O(log n) for both lower_bound() and upper_bound()


    // 7. equal_range(key) – pair of (lower_bound, upper_bound)
    auto range = ms.equal_range(30);
    std::cout << "All 10s in multiset: ";
    for (auto it = range.first; it != range.second; ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    // // 8. size(), empty(), clear()
    // std::cout << "Size: " << ms.size() << "\n";
    // std::cout << "Is empty? " << (ms.empty() ? "Yes" : "No") << "\n";
    // ms.clear();
    // std::cout << "After clear, is empty? " << (ms.empty() ? "Yes" : "No") << "\n";

    // return 0;
}

//---------------map----------------------

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> mp;

    // 1. insert() – Insert key-value pair
    mp.insert({"apple", 2});
    mp.insert(std::make_pair("banana", 5));
    mp["cherry"] = 10;  // Also inserts if key doesn't exist

    // 2. operator[] – Insert or update value
    mp["banana"] = 8;  // Updates value for existing key

    // // 3. at() – Access element with bounds checking
    // std::cout << "banana: " << mp.at("banana") << "\n";  // 8

    // 4. find() – Returns iterator to key or mp.end() if not found
    // auto it = mp.find("apple");
    // if (it != mp.end()) std::cout << "Found: " << it->first << " => " << it->second << "\n";

    // // 5. count() – Check if key exists (0 or 1)
    // std::cout << "Count of cherry: " << mp.count("cherry") << "\n";  // 1

    // 6. erase() – Remove by key or iterator
    // mp.erase("banana");  // Erase by key
    // mp.erase(mp.find("apple"));  // Erase by iterator

    // 7. clear() – Remove all elements
    // mp.clear();

    // 8. size() and empty()
    // std::cout << "Map size: " << mp.size() << "\n";
    // std::cout << "Is map empty? " << (mp.empty() ? "Yes" : "No") << "\n";

    // 9. lower_bound(), upper_bound()
    mp["dog"] = 3;
    mp["cat"] = 4;
    auto lb = mp.lower_bound("cat");  // >= "cat"
    auto ub = mp.upper_bound("cat");  // > "cat"
    std::cout << "Lower bound of cat: " << lb->first << " => " << lb->second << "\n";
    std::cout << "Upper bound of cat: " << ub->first << " => " << ub->second << "\n";

    // // 10. equal_range() – Pair of lower_bound and upper_bound
    // auto range = mp.equal_range("cat");
    // std::cout << "Equal range of cat:\n";
    // for (auto i = range.first; i != range.second; ++i)
    //     std::cout << i->first << " => " << i->second << "\n";

    // // 11. iteration
    // std::cout << "Current map:\n";
    // for (const auto& [key, value] : mp)
    //     std::cout << key << " => " << value << "\n";

    return 0;

}

//----------------multimap---------------

#include <iostream>
#include <map>

int main() {
    std::multimap<std::string, int> mm;

    // 1. insert() – adds multiple values for same key
    mm.insert({"apple", 10});
    mm.insert({"banana", 20});
    mm.insert({"apple", 15});  // duplicate key

    // 2. emplace() – in-place insertion
    mm.emplace("banana", 25);

    // 3. find() – returns iterator to first occurrence
    auto it = mm.find("apple");
    if (it != mm.end())
        std::cout << "First apple: " << it->first << " => " << it->second << "\n";

    // 4. count() – number of entries with the given key
    std::cout << "Count of apple: " << mm.count("apple") << "\n";  // 2

    // 5. equal_range() – get range of all values for a key
    auto range = mm.equal_range("banana");
    std::cout << "All bananas:\n";
    for (auto i = range.first; i != range.second; ++i)
        std::cout << i->first << " => " << i->second << "\n";

    // 6. erase() – erase by key or iterator
    mm.erase("apple");  // removes all entries with key "apple"

    // 7. size() and empty()
    std::cout << "Size after erase: " << mm.size() << "\n";
    std::cout << "Is multimap empty? " << (mm.empty() ? "Yes" : "No") << "\n";

    // 8. clear()
    mm.clear();

    return 0;
}
/*
In C++, an associative container is a type of container that stores elements in a way that allows 
fast access to individual elements based on a key rather than an index. these are set, multiset ,map ,multimap 
Types of Associative Containers in C++
1.Ordered Associative Containers:
TC-Lookup Time Complexity	O(log n)	
Insertion Time Complexity	O(log n)	
Deletion Time Complexity	O(log n)	
2.Unordered Associative Containers:
O(1) on average (O(n) in worst case)
O(1) on average (O(n) in worst case)
O(1) on average (O(n) in worst case)
*/