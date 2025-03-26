/*
**syntax**-
template <typename... Args>
void functionName(Args... args) {
    // Function implementation
}
*/
#include <iostream>
using namespace std;
/*
// Recursive function call.
template<typename T> // get called when only one argument is left
T sum(T value) {
    return value;
}

template<typename T, typename... Args>
T sum(T first, Args... args) {
    return first + sum(args...); 
}
*/
int main() {
    // cout << "Sum: " << sum(0,1) << std::endl; 
    // cout << "Sum: " << sum(1, 2, 3, 4, 5) << std::endl; 
    // cout << "Sum: " << sum(1.5, 2.5, 3.5) << std::endl; 
    return 0;
}