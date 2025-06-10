// implemented as a doubly linked list
#include <iostream>
#include <list>
using namespace std;
int main(){
    list<int> myList = {10, 20, 30, 40};
    myList.push_back(50);   // Adds 50 at the end
    myList.emplace_back(50);  // 
    myList.push_front(5);   // Adds 5 at the beginning
    // auto it= myList.begin();
    // cout<<*it;
    myList.pop_back();  // Removes last element
    myList.pop_front(); // Removes first element
    myList.remove(20);  // Removes all occurrences of 20
    // cout << myList.front();  // Get first element
    // cout << myList.back();   // Get last element

    // for (int x : myList) {    //iterate over the list
    //     std::cout << x << " ";
    // }
    // cout << myList.size();    // Returns number of elements
    // cout << myList.empty();   // Returns true if empty
    list<int>::iterator it = myList.begin();

    advance(it, 2);  // Move iterator to 3rd position // note-->advance() is not the fun of list 
    auto p=next(it,2);  // advance() vs next() ?
    myList.insert(it, 25); // Insert 25 at 3rd position
    for (int x : myList) {    //iterate over the list
        std::cout << x << " ";
    }
    list<int> list1 = {1, 3, 5};
    list<int> list2 = {2, 4, 6};
    list1.merge(list2); // list1 becomes {1, 2, 3, 4, 5, 6}

    auto it3=find(list1.begin(),list1.end(),30);
    
    if(it==list1.end()){
        cout<<"not found";
    }
    
}
/*
behaviour:push_back()
i.Creates a temporary object and copies or moves it into the list.
ii.Requires an explicitly constructed object before passing it.

Behavior:emplace_back()
Constructs the object in place at the end of the list.
Avoids unnecessary copies or moves.

More efficient for complex objects.
*/