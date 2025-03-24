#include <iostream>
#include <memory>
#include<fstream>
using namespace std;
// Custom deleter class
struct CustomDeleter {
    void operator()(int* ptr) const {
        std::cout << "Custom delete for int with value: " << *ptr << std::endl;
        delete ptr;  // Free the memory
    }
};
struct FileDeleter {
    void operator()(FILE* file) const {
        if (file) {
            std::cout << "Closing the file." << std::endl;
            fclose(file); // Close the file
        }
    }
};
int main() {
    //  std::shared_ptr<int> ptr(new int(42), CustomDeleter());
    FILE * ptr =fopen("sample.txt","w");
    unique_ptr<FILE, FileDeleter> fileptr(ptr);
    fputs("hello from aman", fileptr.get());
    return 0;
}
/*
---Advantage/need of custom deletors
1.File Handling: Automatically close files when a smart pointer goes out of scope,preventing 
file handle leaks.
2.Database Connections:Ensure database connections are properly closed when the pointer goes out
 of scope.
3.Network Sockets: Automatically close sockets to free system resources when no longer needed.
4.Cascading Cleanup: Handle cleanup of dependent resources in the correct order when one resource’s destruction affects others.
5.Multithreading Resource Management: Safely clean up resources shared across multiple threads,
 preventing leaks in concurrent environments.
*/