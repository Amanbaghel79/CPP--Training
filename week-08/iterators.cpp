// In C++, iterators are pointer-like objects that allow you to traverse through the elements
//  of a container, such as arrays or STL containers. They provide a uniform way to access
//   and manipulate container elements without needing to know the underlying structure of 
//   the container.
#include <iostream>
#include <iterator>
#include<vector>
#include <forward_list>
#include<list>
using namespace std;
 int main() {
    //-------------output iterator-----------------
    
//Common Output Iterators in the STL:
// std::back_inserter
// std::front_inserter
// std::inserter
// std::ostream_iterator

    //     std::ostream_iterator<int> out_it(std::cout," "); //pure output iterator
    //     *out_it = 100; 
    //     //  cout<<*out_it; // only Writing is allowed not reading
    //     // int x = *out_it;  //❌ ERROR: Reading is NOT allowed
    // vector<int> arr{ 1,2,3,4,5 };
    // std::cout << "Output: ";
    // ostream_iterator<int> outputItr(cout," "); 
    // copy(arr.begin(), arr.end(), outputItr); 

    // for (auto it = arr.begin(); it != arr.end(); ++it) {   // how copy work internally
    //     *outputItr = *it;  // This 2 is what std::copy does
    //     ++outputItr;       // Internally advances the output iterator
    // }
    //   A == B     // Not Allowed
    //   A <= B     // Not Allowed

//-----------------------------------

// #include <iostream>
// #include <iterator>
// #include <vector>
// using namespace std;

// int main() {
//     vector<int> ans = {1, 2, 3, 4, 5};
    
//     ostream_iterator<int> out(cout, " ");
    
//     // Write each element to cout using output iterator
//     for (int val : ans) {
//         *out = val;  // ✅ This is allowed
//         ++out;       // ✅ Advance the iterator
//     }

//     return 0;
// }



// -------------------Input iterator---------------------

//    cout << "Enter vector elements: ";
//    std::istream_iterator<int> inputIt(std::cin);
//    std::istream_iterator<int> end;
//    std::vector<int> vec(inputIt, end);  // Reads until stream ends or user stops

//    cout << "entered element is: ";
//    for (auto el : vec)
//    cout << el << " ";
//    cout << endl;
   // A==B  valid becoz You can only compare for equality: A == B or A != B  
   // A != B  valid becoz You cannot compare their position/order in a range
   //A--    // Not allowed with input iterators
   //    A <= B     // Not Allowed
   //A + 1     // Not allowed
   // B - 2     // Not allowed
   
//---------------------forward iterator------------------

//      forward_list<int> fl = {1, 2, 3};
//      forward_list<int> f2 = {1, 2, 3};
//      forward_list<int>::iterator it = fl.begin();
//      forward_list<int>::iterator it2 = f2.begin();
//      cout << "Forward Iterator: ";
// //      while (it != fl.end()){
// //      cout << *it << " ";
// //       ++it;  // Can only go forward
// // }
//    //it--;// inavlid
//    // it+3; //invalid
//    if(it==it2) cout<<"yes";
//    else cout<<"no";
// //    it<=it2;
// std::cout << std::endl;

//-----------------Bidirectional Iterator------------------
// std::list<int> lst = {1, 2, 3};

// std::list<int>::iterator it = lst.begin();
// ++it; // Points to 2
// --it; // Back to 1

// std::cout << "Bidirectional Iterator at: " << *it << std::endl;


//------------------random iterator-------------------------

std::vector<int> vec = {10, 20, 30, 40};

std::vector<int>::iterator it = vec.begin();
std::cout << "Random Access Iterator: " << *(it + 2) << std::endl; // Access 3rd element (30)
std::cout << "Bidirectional Iterator at: " << *it << std::endl;

//     return 0;
 }
/*
Container	Iterator Type	Supports
std::array	Random Access	++, --, +, -, []
std::vector	Random Access	++, --, +, -, []
std::deque	Random Access	++, --, +, -, []
std::list	Bidirectional	++, --
std::forward_list	Forward	++
std::set, std::multiset	Bidirectional	++, --
std::map, std::multimap	Bidirectional	++, --
std::unordered_set	Forward	++
std::unordered_map	Forward	++
std::unordered_multiset	Forward	++
std::unordered_multimap	Forward	++
std::stack	❌ No Iterators	Access via top(), no iteration
std::queue	❌ No Iterators	Access via front()/back(), no iteration
std::priority_queue	❌ No Iterators	Access via top(), no iteration*/



// ques-> why ordered_map have a bidirectional iterator but a unordered_map doesnt.
//ques--->How do you erase an element using an iterator? tell with respect to the iterator invalidation.

//ques---> what are advance() method do wiht iterator.
// ANS--->std::advance() moves an iterator forward (or backward) by a specified number of steps.
// std::advance(it, n);  // Moves 'it' forward by n steps (or backward if n is negative)
// Works with all standard iterator types.
// For random-access iterators (like vector), it uses it + n.
// For input/forward iterators, it uses repeated ++it.
// ⚠️ It modifies the iterator in place and does not return a new iterator.