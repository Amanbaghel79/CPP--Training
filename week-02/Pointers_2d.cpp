#include<iostream>
using namespace std;
int main(){
    int arr[2][3]={1,2,3,4,5,6};
    cout<<arr[0][2];
    cout<<&arr[0][0]<<endl;
    cout<<arr[0]<<endl;
    cout<<&arr<<endl;
    cout<<*arr;
    // All print address of the first element of the 2d arr

    cout << "arr[0][0]: " << *(*(arr) + 0) << endl;  // First element of first row
    cout << "arr[0][1]: " << *(*(arr) + 1) << endl;  // Second element of first row
    cout << "arr[1][0]: " << *(*(arr + 1) + 0) << endl;  // First element of second row
    cout << "arr[1][2]: " << *(*(arr + 1) + 2) << endl;  // Third element of second row
    
    cout<<arr+1<<endl;
    cout<<*(arr+1)<<endl;
    cout<<&arr[1][0];
    // above all 3 print the address of arr[1][0]

    // value at any index using *(*(arr+i)+j)

    cout<< *(*(arr+1)+2)<<endl;
    cout<<*(arr+1)+2; // give address of 1st row and 2nd column

    cout<<(arr[1]+1); // prints the address of 1 row and 1 col
    cout<<*(arr[1]+1); //value at arr[1][1]

    cout<<arr+1<<" "<<((&arr)+1)<<endl;// these two are different thing.
    //arr+1 return the address of 1 row.
    // &arr+1 -&arr return pointer of whole 2d array and +1 will increment the value by one whole 2d array
    cout<<&arr[1][0]<<" "<< &arr[1][3];
}