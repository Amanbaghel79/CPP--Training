//The iostream library provides objects, manipulators, and methods that allow you to work with 
//data streams—such as reading input from the user or writing output to the console or files.
#include<iostream>
#include<iomanip>
#include <fstream>  //for file
#include<string>
using namespace std;
int main(){
//****Standard Streams--cin,cout,cerr,clog.
//    int x;
//    cin>>x;
//    cout<<x;
//    cerr<<"error is occured"<<endl;
//    clog<<"log"<<endl;//Used for logging information, warnings, or other non-critical data.
//****Manipulators--- endl,setw(),setprecision(int),fixed,scientific,boolalpha,noboolalpha.
    // float a=3.14;
    // bool flag=true;
    // cout<<setw(8)<<4<<endl; //to decide the width of varaible.
    // cout<<setprecision(4) <<3.14<<endl; //without fixed
    // cout<<fixed<<setprecision(4) <<3.14<<endl; // to set precision after the '.'.
    // cout<<boolalpha<<flag<<endl;
    // cout<<noboolalpha<<flag<<endl;
//*****  File I/O (File Streams)****--------
   string s="writing aman in the file";
   string s2;

   //ofstream  used to write in the file.
   ofstream aman("sample.txt");
   aman<<s;
   aman.close(); //out.close() to close the output file after writing, and this will ensure that the data is properly written and flushed.

   ofstream out; //second way to open a file in writting mode
   out.open("sample.txt");
   out<<"this is overwritten";
   out<<"this is overwritten  ejfnejfdnwejd";
   out.close();
   if (!out.is_open()) {
    cerr << "Error: Could not open the file for writing!" <<endl;
    return 1;  // Exit with error code
}
out<< "Hello, File Handling in C++!" << std::endl;
// Check if the write operation succeeded
if (out.fail()) {
    std::cerr << "Error: Failed to write to the file!" << std::endl;
    return 1;  // Exit with error code
}
// bad(): Returns true if there’s a physical error (e.g., file system error, or reading from a corrupted file).
//    ifstream used to read from the file.
   ifstream in("sample.txt");
   in>>s2;
   getline(in,s2);
//    another way to read a file
    string str;
    ifstream in;
    in.open("sample.txt");
    // in>>str;
    while(in.eof()==0){
        getline(in,str);
        cout<<str;
    }
    getline(in,str);
    cout<<str;
//    cout<<s2;
} 

//Aman
