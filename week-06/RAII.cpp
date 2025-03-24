/*Resource Acquisition Is Initialization or RAII, is a C++ programming technique[1][2] which binds
 the life cycle of a resource that must be acquired before use (allocated heap memory, thread of 
 execution, open socket, open file, locked mutex, disk space, database connection—anything that 
 exists in limited supply) to the lifetime of an object.

 RAII guarantees that the resource is available to any function that may access the object
  (resource availability is a class invariant, eliminating redundant runtime tests). 
  It also guarantees that all resources are released when the lifetime of their controlling
   object ends, in reverse order of acquisition
   #include <iostream>

*/
#include<iostream>
using namespace std;
class Resource {
    public:
        // Constructor acquires the resource
        Resource() {
            data = new int[100];  // Allocate some memory
            cout << "Resource acquired" << endl;
        }
    
        // Destructor releases the resource
        ~Resource() {
            delete[] data; 
            cout << "Resource released" << endl;
        }
    
    private:
        int* data;
    };
    
    int main() {
        
            Resource res;  // Resource is acquired here
    }
    